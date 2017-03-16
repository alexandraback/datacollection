#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<string.h>
#include<memory.h>
#include<iomanip>
#include<cmath>
using namespace std;

int R, C, M, F;
bool swp;
char mas[100][100];
char row[100];
bool ok;

int main()
{
	int test_cnt;
	cin>>test_cnt;
	for(int test_num=1;test_num<=test_cnt;test_num++)
	{
		memset(mas, '*', sizeof(mas));
		cin >> R >> C >> M;
		F = R*C-M;
		swp = (R>C);
		if (swp) swap(R,C);
		ok = true;
		
		if (F==1)
		{
			mas[0][0] = 'c';
		}
		else if (R==1)
		{
			mas[0][0] = 'c';
			for(int i=1;i<F;i++)
				mas[0][i] = '.';
		}
		else if (F<4)
			ok = false;
		else if (R==2)
		{
			if (F&1) ok = false;
			else
			{
				for(int i=0;i<F/2;i++)
					mas[0][i] = mas[1][i] = '.';
				mas[0][0] = 'c';
			}
		}
		else if (F < 8 && F !=4 && F != 6)
		  ok = false;
		else
		{
			mas[0][0] = 'c'; mas[0][1] = mas[1][0] = mas[1][1] = '.'; F-=4;
			if (F>=2)
			{
				mas[0][2] = mas[1][2] = '.';
				F-=2;
			}
			if (F>=2)
			{
				mas[2][0] = mas[2][1] = '.';
				F-=2;
			}
			for(int i=3;i<C && F>=2;i++,F-=2)
				mas[0][i] = mas[1][i] = '.';
			for(int j=3;j<R && F>=2;j++,F-=2)
				mas[j][0] = mas[j][1] = '.';
			for(int i=2;i<C && F;i++)
				for(int j=2;j<R && F;j++,F--)
				{
					mas[j][i] = '.';
				}				
		}
		
		printf("Case #%d:\n", test_num);
		if (!ok) printf("Impossible\n");
		else
		{
			if (swp)
			{
				row[R] = 0;
				for(int j=0;j<C;j++)
				{
					for(int i=0;i<R;i++)
						row[i] = mas[i][j];
					printf("%s\n", row);
				}
			}
			else
			{
				for(int i=0;i<R;i++)
				{
					mas[i][C] = 0;
					printf("%s\n", mas[i]);		
				}
			}
		}
	}
	
	return 0;
}
