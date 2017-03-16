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
#define N 100100

void sol()
{
	int k, c, s;
	scanf("%d%d%d", &k, &c, &s);
	if(c*s<k) { printf(" IMPOSSIBLE\n"); return; }
	int i;
	long long x=1, y=0;
	for(i=0; i<k; i++)
	{
		y+=x*i;
		x*=k;
		if(i%c==c-1) 
		{
			printf(" %lld", y+1);
			x=1;
			y=0;
			if(i==k-1) break;
		}
	}
	if(i==k) 
	{
		for(; i%c!=0; i++)
		{
			y+=x*(k-1);
			x*=k;
		}
		printf(" %lld", y+1);
	}
	printf("\n");
}
int main()
{
	int ts;
	scanf("%d", &ts);
	for(int t=1; t<=ts; t++)
	{
		printf("Case #%d:", t);
		sol();
	}
	return 0;
}