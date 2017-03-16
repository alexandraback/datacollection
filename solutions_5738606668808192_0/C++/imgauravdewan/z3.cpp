#include <bits/stdc++.h>
using namespace std;

const int n= 16;
const int j =50;
char s[n/2] = {0};

int cnt = 0;

void rec(int lvl)
{
	if(lvl == n/2-2)
	{ //s[0 to lvl-1] contain the number
	
		printf("1%s11%s1",s,s);
		//print decimal rep of 1s1 in all base
		int base;
		s[lvl] = '1';
		for(base=2;base<=10;base++)
		{
			long long num = 1;
			for(int k=0;k<=lvl;k++)
				num = num*base+(s[k]-'0');
			printf(" %lld",num);
		}
		s[lvl] = '\0';
		printf("\n");
		cnt++;
		return;
	}
	s[lvl] = '0';
	if(cnt<j)
		rec(lvl+1);
	s[lvl] = '1';
	if(cnt<j)
		rec(lvl+1);
}

int main()
{
	printf("Case #1:\n");
	rec(0);
	return 0;
}
