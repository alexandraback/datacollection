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

class Solver
{
public:
	void exe();
	
private:
	void input();
	void run();
	void output();
	
private:
	const static int MAX_S = 10000;
	int caseNum, caseIndex;
	int maxS;
	int levelCount[MAX_S + 1];
	int result;
};

void Solver::exe()
{
	scanf("%d", &caseNum);
	for(caseIndex = 1; caseIndex <= caseNum; ++caseIndex)
	{
		input();
		run();
		output();
	}
}

void Solver::input()
{
	scanf("%d", &maxS);
	char line[MAX_S + 2];
	scanf("%s", line);
	for(int i = 0; i <= maxS; ++i)
	{
		levelCount[i] = line[i] - '0';
	}
}

void Solver::run()
{
	result = 0;
	int total = 0;
	for(int i = 0; i <= maxS; ++i)
	{
		if(levelCount[i] && total < i)
		{
			result += i - total;
			total = i;
		}
		total += levelCount[i];
	}
}

void Solver::output()
{
	printf("Case #%d: %d\n", caseIndex, result);
}

Solver instance;
int main()
{
#ifdef FILE_IO
	freopen("C:\\Users\\Zee\\Desktop\\A.in", "r", stdin);
	freopen("C:\\Users\\Zee\\Desktop\\A.out", "w", stdout);
#endif
	
	instance.exe();
	return 0;
}

