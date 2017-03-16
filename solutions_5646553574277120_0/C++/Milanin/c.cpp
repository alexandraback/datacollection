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
using namespace std;
#define N 110
int m[N], d[N];
void solve()
{
	int c, n, i, j, v, r;
	scanf("%d%d%d", &c, &n, &v);
	for(i=0; i<=v; d[i]=0, i++);
	for(i=0; i<n; scanf("%d", &m[i]), i++);
	for(d[0]=1, i=0; i<n; i++)
		for(j=v-m[i]; j>=0; j--)
			if(d[j]) d[j+m[i]]=1;
	r=0;
	for(i=1; i<=v; i++)
		if(!d[i])
		{
			r++;
			for(j=v-i; j>=0; j--)
				if(d[j]) d[j+i]=1;
		}
	printf("%d\n", r);
}
int main()
{
	int tst;
	scanf("%d", &tst);
	for(int ts=1; ts<=tst; ts++)
	{
		printf("Case #%d: ", ts);
		solve();
	}
	return 0;
}