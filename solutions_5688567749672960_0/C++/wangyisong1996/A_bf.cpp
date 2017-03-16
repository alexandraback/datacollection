#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define if if (
#define then )
#define do )
#define for for (
#define while while (
#define begin {
#define end }

#define MAXN 10000005

int N;
int n;

int dist[MAXN];
int l[MAXN];

inline int rev(int x)
begin
	char s[20]={0};
	sprintf(s,"%d",x);
	std::reverse(s,s+strlen(s));
	return atoi(s);
end;

inline void pre()
begin
	N=10000000;
	dist[1]=1;
	int s=0,t=1;
	l[1]=1;
	while s<t do begin
		int x=l[++s];
		int y;
		y=x+1;
		if y<=N && !dist[y] then begin
			dist[y]=dist[x]+1;
			l[++t]=y;
		end;
		y=rev(x);
		if y<=N && !dist[y] then begin
			dist[y]=dist[x]+1;
			l[++t]=y;
		end;
	end;
end;

inline void solve()
begin
	scanf("%d",&n);
	printf("%d\n",dist[n]);
end;

int main()
begin
	int T;
	scanf("%d",&T);
	pre();
	int i;
	for i=1;i<=T;i++ do begin
		printf("Case #%d: ",i);
		solve();
	end;
end