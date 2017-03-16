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
	int n;
	scanf("%d", &n);
	if(n==0) printf("INSOMNIA\n");
	else
	{
		int u[10];
		for(int i=0; i<10; u[i]=0, i++);
		int x;
		for(x=n; ; x+=n)
		{
			int i;
			for(i=x; i>0; u[i%10]=1, i/=10);
			for(i=0; i<10 && u[i]; i++);
			if(i==10) break;
		}
		printf("%d\n", x);
	}
}
int main()
{
	int ts;
	scanf("%d", &ts);
	for(int t=1; t<=ts; t++)
	{
		printf("Case #%d: ", t);
		sol();
	}
	return 0;
}