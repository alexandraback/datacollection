/* ***********************************************
Author        :axp
Created Time  :2016/5/1 0:36:20
TASK		  :B.cpp
LANG          :C++
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 20;
int T;
char ch[2][N];
int ten[10];
int n;
int sx,sy;
int ar[2][10];

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
	ten[0]=1;
	ten[1]=10;
	ten[2]=100;
	ten[3]=1000;
    scanf("%d",&T);
	for(int kase=1;kase<=T;kase++)
	{
		for(int i=0;i<2;i++)
		{
			scanf("%s",ch[i]);
			n=strlen(ch[i]);
		}
		sx=9999,sy=0;
		bool flag;
		for(int x=0;x<ten[n];x++)
		{
			int t=x;
			for(int i=0;i<n;i++)
			{
				ar[0][n-i-1]=t%10;
				t/=10;
			}
			for(int y=0;y<ten[n];y++)
			{
			int t=y;
			for(int i=0;i<n;i++)
			{
				ar[1][n-i-1]=t%10;
				t/=10;
			}
				flag=1;
				for(int k=0;k<2;k++)
				for(int i=0;i<n;i++)
					if(isdigit(ch[k][i]) && ch[k][i]-'0'!=ar[k][i])
					{
						flag=0;
						break;
					}
				if(flag)
				{
					if(abs(sx-sy)>abs(x-y))
						sx=x,sy=y;
					else if(abs(sx-sy)==abs(x-y) &&( x<sx || (x==sx && y<sy)))
						sx=x,sy=y;
				}
			}
		}
		printf("Case #%d:",kase);
		for(int k=0;k<2;k++)
		{
			int t=k==0?sx:sy;
			for(int i=0;i<n;i++)
			{
				ar[k][n-i-1]=t%10;
				t/=10;
			}
			putchar(' ');
			for(int i=0;i<n;i++)putchar('0'+ar[k][i]%10);
		}
		putchar(10);
	}
    return 0;
}
