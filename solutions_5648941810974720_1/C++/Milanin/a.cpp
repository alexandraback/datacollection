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
char s[N];
int u[256], y[256], a[10], p[10]={0, 2, 6, 8, 3, 4, 7, 1, 5, 9};
char d[10][10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
void apply_dig(int x)
{
	for(int i=0; i<26; y['A'+i]=0, i++);
	for(int i=0; d[x][i]; y[d[x][i]]++, i++);
	int n=N;
	for(int i=0; i<26; i++)
		if(y['A'+i]>0) n=min(n, u['A'+i]/y['A'+i]);
	a[x]+=n;
	for(int i=0; i<26; u['A'+i]-=n*y['A'+i], i++);
}
void sol()
{
	scanf("%s", s);
	for(int i=0; i<26; u['A'+i]=0, i++);
	for(int i=0; i<10; a[i]=0, i++);
	for(int i=0; s[i]; u[s[i]]++, i++);
	for(int i=0; i<10; apply_dig(p[i]), i++);
	for(int i=0; i<10; i++)
		for(int j=0; j<a[i]; printf("%d", i), j++);
	printf("\n");
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