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
#define N 100010
#define K 100010
#define M 1000000000
struct T 
{
	int i, v;
	T(int i=0, int v=0): i(i), v(v) {}
};
bool operator <(T a, T b) { return a.v>b.v; }
int l, n, u[N], w[N], p[N], a[2*K], c[2*K], e[2*K];
vector <int> m[N];
priority_queue <T> q;
void push(int i, int v, int j)
{
	if(v<u[i]) { u[i]=v; p[i]=j; q.push(T(i, v)); }
}
bool bfs(int b, int s)
{
	int i, v, j, k;
	for(fill(u, u+n, M), push(b, 0, -1); !q.empty(); )
	{
		i=q.top().i; v=q.top().v; q.pop();
		if(v==u[i])
			for(j=0; j<m[i].size(); j++)
				if(a[k=m[i][j]]) push(e[k], v+c[k]+w[i]-w[e[k]], k);
	}
	return u[s]<M;
}
int mcmf(int b, int s)
{
	int i, j, f;
	for(fill(w, w+n, 0), f=0; bfs(b, s); )
	{
		for(j=M, i=s; i!=b; j=min(j, a[p[i]]), i=e[p[i]^1]);
		int cst=0;
		for(i=s; i!=b; a[p[i]]-=j, a[p[i]^1]+=j, cst+=c[p[i]]*j, i=e[p[i]^1]);
		if(cst>N) break;
		f+=j;
		for(i=0; i<n; w[i]+=((u[i]-M)>>31)&u[i], i++);
	}
	return f;
}
void add(int i, int j, int v, int p)
{
	e[l]=j;	a[l]=v; c[l]=p; m[i].push_back(l++);
	e[l]=i;	a[l]=0; c[l]=-p; m[j].push_back(l++);
}

void clr()
{
	l=0;
	for(int i=0; i<n; m[i].clear(), i++);
}
map <string, int> fw, sw;
char s[N];
void sol()
{
	fw.clear();
	sw.clear();
	int k;
	scanf("%d", &k);
	n=3*k+2;
	clr();
	int fi=0, si=0;
	for(int i=0; i<k; i++)
	{
		add(n-2, k+i, 1, N);
		add(k+i, n-1, 1, N);
		scanf("%s", s);
		if(fw.find(s)==fw.end()) fw[s]=fi++;
		add(fw[s], k+i, 1, 0);
		scanf("%s", s);
		if(sw.find(s)==sw.end()) sw[s]=si++;
		add(k+i, 2*k+sw[s], 1, 0);
	}
	for(int i=0; i<fi; add(n-2, i, 1, 0), i++);
	for(int i=0; i<si; add(2*k+i, n-1, 1, 0), i++);
	printf("%d\n", k-mcmf(n-2, n-1));
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