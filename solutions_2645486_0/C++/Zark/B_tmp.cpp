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
public:
	void Run();

private:
	void Input();
	void Do();
	void Output();
	long long Cal(int start, int end, long long startValue, long long endValue);

private:
	static const int MAX_LEN = 10000;
	int caseNum, caseIndex;
	int length;
	long long E, R;
	long long V[MAX_LEN];
	long long result;
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
	scanf("%lld %lld %d", &E, &R, &length);
	for(int i = 0; i < length; ++i)
		scanf("%lld", V + i);
}

void B::Do()
{
	R = min(E, R);
	result = Cal(0, length - 1, E, R);
}

long long B::Cal(int start, int end, long long startValue, long long endValue)
{
	if(start > end) return (long long)0;
	int index = start;
	for(int i = start + 1; i <= end; ++i)
	{
		if(V[i] > V[index]) index = i;
	}
	long long maxGainValue = min(E, startValue + (index - start) * R);
	long long minRemainValue = max(R, endValue - (end - index) * R);
	long long ans = V[index] * max((long long)0, maxGainValue - (minRemainValue - R));
	ans += Cal(start, index - 1, startValue, maxGainValue) + Cal(index + 1, end, minRemainValue, endValue);
	return ans;
}

void B::Output()
{
	printf("Case #%d: %lld\n", caseIndex, result);
}

B instance;
int main()
{
	#ifdef FILE_IO
	freopen("C:\\Users\\Administrator\\Desktop\\data\\in.txt", "r", stdin);
	freopen("C:\\Users\\Administrator\\Desktop\\data\\out.txt", "w", stdout);
	#endif

	instance.Run();
	return 0;
}
