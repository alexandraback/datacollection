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

class C
{
private:
	int caseNum, caseIndex;
	int R, C, M;
	bool result;
	char grid[100][100];
	char finalGrid[100][100];
	
public:
	void Run();

private:
	void Input();
	void Do();
	void Output();
	void Check(int rowNum, int colNum, int freeCell);
};

void C::Run()
{
	scanf("%d", &caseNum);
	for(caseIndex = 1; caseIndex <= caseNum; ++caseIndex)
	{
		Input();
		Do();
		Output();
	}
}

void C::Input()
{
	scanf("%d %d %d", &R, &C, &M);
}

void C::Check(int rowNum, int colNum, int freeCell)
{
	result = false;
	
	memset(grid, '*', sizeof(grid));
	
	if(freeCell == 1)
	{
		result = true;
		grid[0][0] = 'c';
		return;
	}
	
	if(colNum == 1)
	{
		result = true;
		for(int row = 0; row < freeCell; ++row) grid[row][0] = '.';
		grid[0][0] = 'c';
		return;
	}
	
	int height, remain0, remain1, base;
	for(base = 2; base < freeCell && base <= colNum; ++base)
	{
		height = freeCell / base - 1;
		remain1 = base;
		remain0 = freeCell % base;
		if(remain0 == 0)
		{
			if(height > 0 && height + 1 <= rowNum)
			{
				result = true;
				break;
			}
		}
		else if(remain0 == 1)
		{
			if(base > 2)
			{
				int total = remain1 + remain0;
				remain0 = total >> 1;
				remain1 = total - remain0;
				
				if(height > 1 && height + 2 <= rowNum)
				{
					result = true;
					break;
				}	
			}
		}
		else
		{
			if(height > 0 && height + 2 <= rowNum)
			{
				result = true;
				break;
			}
		}
	}
	
	if(result == true)
	{
		for(int row = 0; row < height; ++row)
		{
			for(int col = 0; col < base; ++col)
			{
				grid[row][col] = '.';
			}
		}

		for(int col = 0; col < remain1; ++col)
		{
			grid[height][col] = '.';
		}
		
		for(int col = 0; col < remain0; ++col)
		{
			grid[height + 1][col] = '.';
		}
		grid[0][0] = 'c';
	}
}

void C::Do()
{
	int freeCell = R * C - M;
	Check(R, C, freeCell);
	if(result)
	{
		for(int row = 0; row < R; ++row)
		{
			for(int col = 0; col < C; ++col)
			{
				finalGrid[row][col] = grid[row][col];
			}
		}
	}
	else
	{
		Check(C, R, freeCell);
		if(result)
		{
			for(int row = 0; row < R; ++row)
			{
				for(int col = 0; col < C; ++col)
				{
					finalGrid[row][col] = grid[col][row];
				}
			}
		}
	}
}

void C::Output()
{
	printf("Case #%d:\n", caseIndex);
	if(result)
	{
		for(int row = 0; row < R; ++row)
		{
			for(int col = 0; col < C; ++col)
			{
				printf("%c", finalGrid[row][col]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("Impossible\n");
	}
}

C instance;
int main()
{
	#ifdef FILE_IO
	freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
	freopen("C:\\Users\\Administrator\\Desktop\\out.txt", "w", stdout);
	#endif

	instance.Run();
	return 0;
}
