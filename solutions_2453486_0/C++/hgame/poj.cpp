#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <string>
#include <string.h>
#include <queue>
#include <set>
#include <complex>
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
char s[4][5];
int main()
{
	int cas;
	freopen("a.in","w",stdout);
	scanf("%d",&cas);
	for(int k=1;k<=cas;k++)
	{
		bool f=0;
		for(int i=0;i<4;i++) scanf("%s",s[i]);
		printf("Case #%d: ",k);
		int sum=0;
		for(int i=0;i<4;i++)
		{
			int cnt0=0,cnt1=0,cnt2=0,cnt3=0;
			for(int j=0;j<4;j++)
			{
				if(s[i][j]!='.')
				{
					sum++;
					if(s[i][j]!='O') cnt0++;
					if(s[i][j]!='X') cnt1++;
				}
				if(s[j][i]!='.')
				{
					if(s[j][i]!='O') cnt2++;
					if(s[j][i]!='X') cnt3++;
				}
			}
			if(cnt0==4||cnt2==4) {puts("X won"); f=1; break;}
			if(cnt1==4||cnt3==4) {puts("O won"); f=1; break;}
		}
		if(!f)
		{
			int cnt0=0,cnt1=0,cnt2=0,cnt3=0;
			for(int i=0;i<4;i++)
			{
				
				if(s[i][i]!='.')
				{
					if(s[i][i]!='O') cnt0++;
					if(s[i][i]!='X') cnt1++;
				}
				if(s[i][3-i]!='.')
				{
					if(s[i][3-i]!='O') cnt2++;
					if(s[i][3-i]!='X') cnt3++;
				}
			}
			if(cnt0==4||cnt2==4) {puts("X won"); f=1;}
			if(cnt1==4||cnt3==4) {puts("O won"); f=1;}
		}
		if(!f)
		{
			if(sum==16) puts("Draw");
			else puts("Game has not completed");
		}
	}
}