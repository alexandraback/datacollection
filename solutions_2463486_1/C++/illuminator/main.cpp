#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef unsigned long long u64;

u64 table[10000];
int tc;

bool is(u64 v)
{
	int len = 0;
	char str[20];

	while(v)
	{
		str[len++] = v % 10;
		v/=10;
	}

	for(int i = 0; i < len; i++)
		if( str[i] != str[len - 1 - i] ) return false;
	return true;
}

void f(char str[],int s,int e)
{
	if( s > e ) 
	{
		if( str[0] != '0')
		{
			u64 v = atoi(str);
			v *= v;
			if(is(v)) table[tc++] = v;
		}
		return ;
	}

	for(int i = 0; i < 10; i++)
	{
		str[s] = str[e] = '0' + i;
		f(str,s+1,e-1);
	}
}

void MakeTable()
{
	tc = 0;
	char str[20];
	table[tc++] = 0;
	for(int i = 0; i < 8; i++)
	{
		str[i+1] = 0;
		f(str,0,i);
	}
}

int main()
{
	int T,c = 1;
	u64 A,B;
	MakeTable();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64u%I64u",&A,&B);
		printf("Case #%d: %d\n",c++,upper_bound(table,table+tc,B) - lower_bound(table,table+tc,A));
	}
	return 0;
}