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
char s[N], f[N];
int p[N];
double b[N], d[N];
void pf()
{
	int i, j;
	for(p[0]=-1, j=-1, i=0; s[i]; ++i, ++j, p[i]=j)
		for(; j>=0 && s[i]!=s[j]; j=p[j]);
}
int go(int t, char c)
{
	for(; t>=0 && s[t]!=c; t=p[t]);
	t++;
	return t;
}
void solve()
{
	int i, j, k, l, n, m, t;
	double r;
	scanf("%d%d%d%s%s", &k, &l, &n, f, s);
	pf();
	s[l]='$';
	m=0;
	for(t=0, i=0; i<n; i++)
	{
		int bt=0;
		for(j=0; j<k; j++)
			if(go(t, f[j])>bt) bt=go(t, f[j]);
		t=bt;
		if(t==l) m++;
	}
	b[0]=1;
	for(t=1; t<=l; b[t]=0, t++);
	r=0;
	for(i=0; i<n; i++)
	{
		for(t=0; t<=l; d[t]=0, t++);
		for(t=0; t<=l; t++)
			for(j=0; j<k; d[go(t, f[j])]+=b[t]/k, j++);
		for(t=0; t<=l; b[t]=d[t], t++);
		r+=b[l];
	}
	printf("%.13lf\n", m-r);
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