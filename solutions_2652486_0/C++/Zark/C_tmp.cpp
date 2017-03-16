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

class C
{
public:
	void Run();

private:
	void Input();
	void Do();
	void Output();
	bool Check(int index);

private:
	int caseNum, caseIndex;
	int roundNum, N, M, K;
	int pdct[8000][12];
	int numbers[12];
};

void C::Run()
{
	scanf("%d", &caseNum);
	for(caseIndex = 1; caseIndex <= caseNum; ++caseIndex)
	{
		Input();
		Do();
		//Output();
	}
}

void C::Input()
{
	scanf("%d %d %d %d", &roundNum, &N, &M, &K);
	for(int i = 0; i < roundNum; ++i)
	{
		for(int j = 0; j < K; ++j)
		{
			scanf("%d", &pdct[i][j]);
		}
	}
}

void C::Do()
{
	printf("Case #%d:\n", caseIndex);
	for(int rIndex = 0; rIndex < roundNum; ++rIndex)
	{
		int CODE = 1;
		for(int i = 0; i < N; ++i) CODE *= M - 1;
		for(int i = 0; i < CODE; ++i)
		{
			int tmp = i;
			for(int j = 0; j < N; ++j)
			{
				numbers[j] = tmp % (M - 1) + 2;
				tmp /= M - 1;
			}
			if(Check(rIndex))
			{
				break;
			}
		}
		for(int i = 0; i < N; ++i) printf("%d", numbers[i]);
		printf("\n");
	}
}

void C::Output()
{
	//printf("Case #%d:\n", caseIndex);
}

bool C::Check(int index)
{
	for(int i = 0; i < K; ++i)
	{
		int tmp = pdct[index][i];
		for(int i = 0; i < N; ++i)
		{
			if(tmp % numbers[i] == 0)
			{
				tmp /= numbers[i];
			}
		}
		if(tmp != 1) return false;
	}
	return true;
}

C instance;
int main()
{
	#ifdef FILE_IO
	freopen("C:\\Users\\Administrator\\Desktop\\data\\in.txt", "r", stdin);
	freopen("C:\\Users\\Administrator\\Desktop\\data\\out.txt", "w", stdout);
	#endif

	instance.Run();
	return 0;
}
