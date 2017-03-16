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
	int Abit[32], Bbit[32], Kbit[32], pattern[32];
	long long dpBuffer[33][2][2];
	long long result;
	
public:
	void Run();

private:
	void Input();
	void Do();
	void Output();
	void GetBit(int n, int bit[]);
	long long Count();
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
	GetBit(A, Abit);
	GetBit(B, Bbit);
	GetBit(K, Kbit);
	
	result = 0;
	for(int i = 31; i >= 0; --i)
	{
		if(Kbit[i] == 1)
		{
			for(int j = 31; j > i; --j)
			{
				pattern[j] = Kbit[j];
			}
			pattern[i] = 0;
			for(int j = 0; j < i; ++j)
			{
				pattern[j] = 2;
			}
			
			result += Count();
		}
	}
}

void B::GetBit(int n, int bit[])
{
	for(int i = 0; i < 32; ++i)
	{
		if(n & (1 << i)) bit[i] = 1;
		else bit[i] = 0;
	}
}

long long B::Count()
{
	dpBuffer[0][1][1] = dpBuffer[0][0][1] = dpBuffer[0][1][0] = 0;
	dpBuffer[0][0][0] = 1;
	
	for(int len = 1; len <= 32; ++len)
	{
		int index = len - 1;
		for(int i = 0; i < 2; ++i)
		{
			for(int j = 0; j < 2; ++j)
			{
				dpBuffer[len][i][j] = 0;
				for(int x = 0; x < 2; ++x)
				{
					for(int y = 0; y < 2; ++y)
					{
						int xy = x & y;
						if(pattern[index] == 2 || pattern[index] == xy)
						{
							int ii, jj;
							if(i == 1)
							{
								if(x > Abit[index]) continue;
								else if(x == Abit[index]) ii = 1;
								else ii = 0;
							}
							else
							{
								ii = 0;
							}
							
							if(j == 1)
							{
								if(y > Bbit[index]) continue;
								else if(y == Bbit[index]) jj = 1;
								else jj = 0;
							}
							else
							{
								jj = 0;
							}
							dpBuffer[len][i][j] += dpBuffer[len - 1][ii][jj];
						}
					}
				}
			}
		}
	}
	
	return dpBuffer[32][1][1];
}

void B::Output()
{
	printf("Case #%d: %lld\n", caseIndex, result);
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
