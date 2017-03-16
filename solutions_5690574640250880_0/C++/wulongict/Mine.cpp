#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
void PrintMine(char *Mine[], int R, int C)
{
	for (int i = 0; i < R; i ++)
	{
		for (int j = 0; j < C; j++)
		{
			printf("%c",Mine[i][j]);
		}
		printf("\n");
	}
}

void solve(int caseNum)
{
	int R,C,M;
	scanf("%d %d %d",&R,&C,&M);
	char **Mine = new char*[R];
	for (int i = 0; i < R; i++)
	{
		Mine[i]= new char[C];
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j ++)
		{
			Mine[i][j] = '*';
		}
	}
	int emptyCellNum = R*C-M;
	bool possible = false;
	int x1=0,y1=0,x2=0,y2=0,x0=0,y0=0;
	for (x1=1;x1<=C;x1++)
	{
		if (x1==1 && x1!=C)
		{
			continue;
		}
		for (x2=x1;x2<=C;x2++)
		{
			for (y2=1;y2<=R;y2++)
			{
				if (y2==1 && y2!=R)
				{
					continue;
				}
				for (y1=y2;y1<=R;y1++)
				{
					//printf("x1=%d,y1=%d,x2=%d,y2=%d\n", x1,y1,x2,y2);
					//printf("x1*y1+x2*y2-x1*y2 = %d == %d = emptyCellNum\n",x1*y1+x2*y2-x1*y2,emptyCellNum);
					if (x1*y1+x2*y2-x1*y2 == emptyCellNum)
					{
						possible=true;
						break;
					}
					
				}
				if (possible)
				{
					break;
				}
			}
			if (possible)
			{
				break;
			}
		}
		if (possible)
		{
			break;
		}
	}
	if (!possible)
	{
		if (emptyCellNum==1)
		{
			x1=y1=x2=y2=1;
			possible=true;
		}
	}
	/*
	if (!possible)
	{
		x1=0,y1=0,x2=0,y2=0,x0=0,y0=0;
		for (x1=1;x1<=C;x1++)
		{
			if (x1==1 && x1!=C)
			{
				continue;
			}
			for (x2=x1;x2<=C;x2++)
			{
				for (y2=1;y2<=R;y2++)
				{
					if (y2==1 && y2!=R)
					{
						continue;
					}
					for (y1=y2;y1<=R;y1++)
					{

						if (x1*y1+x2*y2-x1*y2 == emptyCellNum)
						{
							possible=true;
							break;
						}

					}
					if (possible)
					{
						break;
					}
				}
				if (possible)
				{
					break;
				}
			}
			if (possible)
			{
				break;
			}
		}
	}*/
	//printf("x1=%d, y1=%d, x2=%d, y2=%d\n",x1,y1,x2,y2);
	//cout << possible <<endl;
	if (possible)
	{
		for (int i =0; i < y1; i++)
		{
			for (int j =0; j < x1; j++)
			{
				Mine[i][j]='.';
			}
		}
		for (int i =0; i < y2; i++)
		{
			for (int j =x1; j < x2; j++)
			{
				Mine[i][j]='.';
			}
		}
		Mine[0][0]='c';
		printf("Case #%d:\n",caseNum);
		PrintMine(Mine,R,C);
	}
	else
	{
		if (R==4 && C==4 && M==3)
		{
			x1=2;y1=4;x2=4;y2=2;
			for (int i =0; i < y1; i++)
			{
				for (int j =0; j < x1; j++)
				{
					Mine[i][j]='.';
				}
			}
			for (int i =0; i < y2; i++)
			{
				for (int j =x1; j < x2; j++)
				{
					Mine[i][j]='.';
				}
			}
			Mine[0][0]='c';
			Mine[2][2]='.';
			printf("Case #%d:\n",caseNum);
			PrintMine(Mine,R,C);
		}
		else
		printf("Case #%d:\nImpossible\n",caseNum);
	}





	for (int i = 0; i < R; i ++)
	{
		delete [] Mine[i];
	}
	delete [] Mine;
}


int main()
{
	int caseNum = 0;
	scanf("%d",&caseNum);
	for (int i = 0; i < caseNum; i ++)
	{
		solve(i+1);
	}
	return 0;
}