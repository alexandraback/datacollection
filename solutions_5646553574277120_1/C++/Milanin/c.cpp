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
int m[N];
void solve()
{
	int c, n, i, j, v, r;
	long long x;
	scanf("%d%d%d", &c, &n, &v);
	for(i=0; i<n; scanf("%d", &m[i]), i++);
	r=0;
	x=0;
	for(i=0; x<v; )
		if(i<n && x>=m[i]-1)
		{
			x=(long long)m[i]*c+x;
			i++;
		}
		else
		{
			x=(long long)(x+1)*c+x;
			r++;
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