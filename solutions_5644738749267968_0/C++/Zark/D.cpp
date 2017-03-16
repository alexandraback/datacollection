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
using namespace std;

#pragma comment(linker, "/STACK:104857600,104857600")

//#define FILE_IO

class D
{
private:
	int caseNum, caseIndex;
	int num;
	double blocks[2][1000];
	int score1, score2;
	
public:
	void Run();
	
private:
	void Input();
	void Do();
	void Output();
};

void D::Run()
{
	scanf("%d", &caseNum);
	for(caseIndex = 1; caseIndex <= caseNum; ++caseIndex)
	{
		Input();
		Do();
		Output();
	}
}

void D::Input()
{
	scanf("%d", &num);
	for(int i = 0; i < 2; ++i)
	{
		for(int j = 0; j < num; ++j)
		{
			scanf("%lf", &blocks[i][j]);
		}
	}
}

void D::Do()
{
	sort(blocks[0], blocks[0] + num);
	sort(blocks[1], blocks[1] + num);
	score2 = num;
	int index = 0;
	for(int i = 0; i < num; ++i)
	{
		while(index < num && blocks[1][index] <= blocks[0][i])
			++index;
		if(index < num)
		{
			--score2;
			++index;
		}
	}

	score1 = 0;
	index = 0;
	for(int i = 0; i < num; ++i)
	{
		if(blocks[0][i] > blocks[1][index])
		{
			++score1;
			++index;
		}
	}
}

void D::Output()
{
	printf("Case #%d: %d %d\n", caseIndex, score1, score2);
}

D instance;
int main()
{
	#ifdef FILE_IO
	freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
	freopen("C:\\Users\\Administrator\\Desktop\\out.txt", "w", stdout);
	#endif

	instance.Run();
	return 0;
}

