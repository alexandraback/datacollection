#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <list>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>
#include <cstdlib>
#include <set>
#include <string>
#include <cstring>
#include <memory>

#pragma comment(linker, "/STACK:104857600,104857600")

using namespace std;

//#define FILE_IO

class B
{
private:
	int caseNum, caseIndex;
	double C, F, X;
	double result;
	
public:
	void Run();

private:
	void Input();
	void Do();
	void Output();
};

void B::Run()
{
	scanf("%d", &caseNum);
	for(caseIndex = 1; caseIndex <= caseNum; ++caseIndex)
	{
		Input();
		Do();
		Output();
	}
}

void B::Input()
{
	scanf("%lf %lf %lf", &C, &F, &X);

}

void B::Do()
{
	result = X / 2.0;
	int n = 0;
	double timeCost = 0.0;
	while(true)
	{
		timeCost += C / (2.0 + n * F);
		double tmp = timeCost + X / (2 + (n + 1) * F);
		if(tmp >= result)
		{
			break;
		}
		else
		{
			result = tmp;
		}
		++n;
	}
}

void B::Output()
{
	printf("Case #%d: %.7lf\n", caseIndex, result);
}

B instance;
int main()
{
	#ifdef FILE_IO
	freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
	freopen("C:\\Users\\Administrator\\Desktop\\out.txt", "w", stdout);
	#endif

	instance.Run();
	return 0;
}
