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
	int caseNum, caseIndex;
	int x, r, c;
	bool result;
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
	scanf("%d%d%d", &x, &r, &c);
}

void Solver::run()
{
	if(r > c) swap(r, c);
	
	result = false;
	if((r * c) % x) result = true;
	else if(x >= 7) result = true;
	else if(x == 3)
	{
		if(r == 1) result = true;
	}
	else if(x == 4)
	{
		if(r <= 2 || c < 4) result = true;
	}
	else if(x == 5)
	{
		if(r <= 2 || c < 5) result = true;
	}
	else if(x == 6)
	{
		if(r <= 3 || c < 6) result = true;
	}
}

void Solver::output()
{
	if(result)	printf("Case #%d: RICHARD\n", caseIndex);
	else printf("Case #%d: GABRIEL\n", caseIndex);
}

Solver instance;
int main()
{
#ifdef FILE_IO
	freopen("C:\\Users\\Zee\\Desktop\\D.in", "r", stdin);
	freopen("C:\\Users\\Zee\\Desktop\\D.out", "w", stdout);
#endif
	
	instance.exe();
	return 0;
}
