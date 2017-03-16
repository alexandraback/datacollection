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

#define FILE_IO

class A
{
public:
	void Run();

private:
	void Input();
	void Do();
	void Output();

private:
	int caseNum, caseIndex;
	long long r, t;
	long long result;
};

void A::Run()
{
	scanf("%d", &caseNum);
	for(caseIndex = 1; caseIndex <= caseNum; ++caseIndex)
	{
		Input();
		Do();
		Output();
	}
}

void A::Input()
{
	scanf("%lld %lld", &r, &t);
}

void A::Do()
{
	long long start = 0, end = ((long long)1) << 30, mid;
	while(start <= end)
	{
		mid = (start + end) >> 1;
		int len1 = log((double)mid) / log(2.0);
		int len2 = log((double)r) / log(2.0);
		if(len1 + len2 >= 60 || mid * mid * 2 + 2 * r * mid - mid > t)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	result = end;
}

void A::Output()
{
	printf("Case #%d: %lld\n", caseIndex, result);
}

A instance;
int main()
{
	#ifdef FILE_IO
	freopen("C:\\Users\\Administrator\\Desktop\\data\\in.txt", "r", stdin);
	freopen("C:\\Users\\Administrator\\Desktop\\data\\out.txt", "w", stdout);
	#endif

	instance.Run();
	return 0;
}
