#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;
int N,flag;
char a[5][5];
int t[2000];
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&N);
	for (int test=1;test<=N;test++)
	{
		flag=0;
		for (int i=0;i<4;i++)scanf("%s",a[i]);
		for (int i=0;i<4;i++)
		{
			t['O']=0;
			t['T']=0;
			t['.']=0;
			t['X']=0;
			for (int j=0;j<4;j++)
			t[a[i][j]]++;
			if (t['O']+t['T']==4)flag=1;
			if (t['X']+t['T']==4)flag=2;
		}
		for (int j=0;j<4;j++)
		{
			t['O']=0;
			t['T']=0;
			t['.']=0;
			t['X']=0;
			for (int i=0;i<4;i++)
			t[a[i][j]]++;
			if (t['O']+t['T']==4)flag=1;
			if (t['X']+t['T']==4)flag=2;
		}
		t['O']=0;
		t['T']=0;
		t['.']=0;
		t['X']=0;
		for  (int i=0;i<4;i++)t[a[i][i]]++;
		if (t['O']+t['T']==4)flag=1;
		if (t['X']+t['T']==4)flag=2;
		t['O']=0;
		t['T']=0;
		t['.']=0;
		t['X']=0;
		for  (int i=0;i<4;i++)t[a[i][3-i]]++;
		if (t['O']+t['T']==4)flag=1;
		if (t['X']+t['T']==4)flag=2;
		if (!flag)
		{
			for (int i=0;i<4;i++)
			for (int j=0;j<4;j++)
			if (a[i][j]=='.')flag=3;
		}
		printf("Case #%d: ",test);
		if (flag==0)printf("Draw\n");
		if (flag==1)printf("O won\n");
		if (flag==2)printf("X won\n");
		if (flag==3)printf("Game has not completed\n");
	}
}
