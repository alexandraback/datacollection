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
	int A, B, K;
	int result;
	
public:
	void Run();

private:
	void Input();
	void Do();
	void Output();
	void DFS(int nodeIndex);
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
	scanf("%d %d %d", &A, &B, &K);
}

void B::Do()
{
	result = 0;
	for(int i = 0; i < A; ++i) for(int j = 0; j < B; ++j)
	{
		if((i & j) < K) ++result; 
	}
}

void B::Output()
{
	printf("Case #%d: %d\n", caseIndex, result);
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
