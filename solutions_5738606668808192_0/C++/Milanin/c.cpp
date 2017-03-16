#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:100000000")
#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
int d[11];
bool isdiv(unsigned x, int b, int n)
{
	int r=0;
	for(int i=31; i>=0; i--)
	{
		r*=b;
		if(((unsigned)x>>(unsigned)i)&1) r++;
		r%=n;
	}
	return r==0;
}
int finddiv(unsigned x, int b)
{
	for(int n=2; n<50; n++)
		if(isdiv(x, b, n)) return n;
	return 0;
}
bool isjamcoin(unsigned x)
{
	for(int b=2; b<=10; b++)
	{
		int n=finddiv(x, b);
		if(!n) return 0;
		d[b]=n;
	}
	return 1;
}
void sol()
{
	int l, n, i;
	scanf("%d%d", &l, &n);
	for(i=0; n; i++)
	{
		unsigned x=i*2+1;
		x|=(unsigned)1<<(unsigned)(l-1);
		if(isjamcoin(x))
		{
			for(int i=l-1; i>=0; printf("%d", ((unsigned)x>>(unsigned)i)&1), i--);
			for(int i=2; i<=10; printf(" %d", d[i]), i++);
			printf("\n");
			n--;
		}
	}
}
int main()
{
	int ts;
	scanf("%d", &ts);
	for(int t=1; t<=ts; t++)
	{
		printf("Case #%d:\n", t);
		sol();
	}
	return 0;
}