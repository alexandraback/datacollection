#include <stdio.h>
#include <algorithm>

#define if if (
#define then )
#define do )
#define for for (
#define while while (
#define begin {
#define end }

inline void solve()
begin
	int N;
	scanf("%d",&N);
	int n=0;
	int i;
	int D[15],M[15];
	for i=1;i<=N;i++ do begin
		int d,h,m;
		scanf("%d%d%d",&d,&h,&m);
		int j;
		for j=0;j<h;j++ do begin
			++n;
			D[n]=d;M[n]=m+j;
		end;
	end;
	long long T[15];
	int ans=n;
	for i=1;i<=n;i++ do begin
		T[i]=1LL*(360-D[i])*M[i];
	end;
	for i=1;i<=n;i++ do begin
		long long t=T[i];
		int j;
		int tmp=0;
		for j=1;j<=n;j++ do begin
			if T[j]>t then begin
				++tmp;
			end else begin
				int k;
				for k=2;k<=n+3;k++ do begin
					if 1LL*(360*k-D[j])*M[j]<=t then ++tmp;
				end;
			end;
		end;
		ans=std::min(ans,tmp);
	end;
	printf("%d\n",ans);
end;

int main()
begin
	int T;
	scanf("%d",&T);
	int i;
	for i=1;i<=T;i++ do begin
		printf("Case #%d: ",i);
		solve();
	end;
end