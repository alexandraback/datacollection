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

class Solver
{
public:
	void exe();
	
private:
	void input();
	void run();
	void output();
	void init();
	
private:
	const static int MAX_LEN = 10000;
	int caseNum, caseIndex;
	int len, repeatNum;
	char line[MAX_LEN + 1];
	int targetMap[4][4];
	int factorMap[4][4];
	bool result;
};

void Solver::exe()
{
	init();
	scanf("%d", &caseNum);
	for(caseIndex = 1; caseIndex <= caseNum; ++caseIndex)
	{
		input();
		run();
		output();
	}
}

void Solver::init()
{
	int tmp[][4] = {
		{ 0, 1, 2, 3 },
		{ 1, 0, 3, 2 },
		{ 2, 3, 0, 1 },
		{ 3, 2, 1, 0 } };
	
	int tmp2[][4] = {
		{ 1, 1, 1, 1 },
		{ 1, -1, 1, -1 },
		{ 1, -1, -1, 1 },
		{ 1, 1, -1, -1 } };
	
	for(int i = 0; i < 4; ++i) for(int j = 0; j < 4; ++j)
	{
		targetMap[i][j] = tmp[i][j];
		factorMap[i][j] = tmp2[i][j];
	}
}

void Solver::input()
{
	long long tmp;
	scanf("%d%lld", &len, &tmp);
	if(tmp > 11)
	{
		repeatNum = 11 + (tmp - 11) % 4;
	}
	else
	{
		repeatNum = (int)tmp;
	}
	scanf("%s", line);
}

void Solver::run()
{
	int last = 0;
	int lastFactor = 1;
	bool findi = false;
	bool findk = false;
	for(int i = 0; i < repeatNum; ++i)
	{
		for(int j = 0; j < len; ++j)
		{
			int tmp = line[j] - 'i' + 1;
			lastFactor *= factorMap[last][tmp];
			last = targetMap[last][tmp];
			
			if(last == 1 && lastFactor > 0)
			{
				findi = true;
			}
			if(findi && last == 3 && lastFactor > 0)
			{
				findk = true;
			}
		}
	}
	
	if(findi && findk && last == 0 && lastFactor < 0)
	{
		result = true;
	}
	else
	{
		result = false;
	}
}

void Solver::output()
{
	if(result)	printf("Case #%d: YES\n", caseIndex);
	else printf("Case #%d: NO\n", caseIndex);
}

Solver instance;
int main()
{
#ifdef FILE_IO
	freopen("C:\\Users\\Zee\\Desktop\\C.in", "r", stdin);
	freopen("C:\\Users\\Zee\\Desktop\\C.out", "w", stdout);
#endif
	
	instance.exe();
	return 0;
}

