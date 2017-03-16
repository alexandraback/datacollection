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
	struct Dinner
	{
		int pancakeNum;
		int partNum;
		int maxNum;
	};
	
public:
	void exe();
	
private:
	void input();
	void run();
	void output();
	void updateDinner(int index);
	
private:
	const static int MAX_DINNER = 1000;
	const static int MAX_PANCAKE = 1000;
	int caseNum, caseIndex;
	int dinnerNum;
	Dinner dinners[MAX_DINNER];
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
	scanf("%d", &dinnerNum);
	for(int i = 0; i < dinnerNum; ++i)
		scanf("%d", &dinners[i].pancakeNum);
}

void Solver::run()
{
	priority_queue<pair<int, int> > order;
	for(int i = 0; i < dinnerNum; ++i)
	{
		dinners[i].partNum = 1;
		updateDinner(i);
		order.push(pair<int, int>(dinners[i].maxNum, i));
	}
	
	int cutCount = 0;
	result = order.top().first + cutCount;
	while(order.top().first != 1)
	{
		int index = order.top().second;
		order.pop();
		
		++cutCount;
		++dinners[index].partNum;
		updateDinner(index);
		order.push(pair<int, int>(dinners[index].maxNum, index));
		
		result = min(result, order.top().first + cutCount);
	}
}

void Solver::updateDinner(int index)
{
	dinners[index].maxNum = dinners[index].pancakeNum / dinners[index].partNum;
	if(dinners[index].pancakeNum % dinners[index].partNum) ++dinners[index].maxNum;
}
	
void Solver::output()
{
	printf("Case #%d: %d\n", caseIndex, result);
}

Solver instance;
int main()
{
#ifdef FILE_IO
	freopen("C:\\Users\\Zee\\Desktop\\B.in", "r", stdin);
	freopen("C:\\Users\\Zee\\Desktop\\B.out", "w", stdout);
#endif
	
	instance.exe();
	return 0;
}

