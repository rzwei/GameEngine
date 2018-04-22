#include <iostream>
#include "IApplication.hpp"
using namespace My;
namespace My
{
extern IApplication *g_pApp;
}
int main(int argc, char **argv)
{
	// std::cout << "hello world" << std::endl;
	int ret;
	if ((ret = g_pApp->Initialize()) != 0)
	{
		std::cout << "App Initialize failed, exit code " << ret << std::endl;
		return ret;
	}
	while (!g_pApp->IsQuit())
	{
		g_pApp->Tick();
	}
	g_pApp->Finalize();
	return 0;
}
