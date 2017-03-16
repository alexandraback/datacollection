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
	int d1,m1;
	int d2,m2;
	if N==1 then begin
		int d,h,m;
		scanf("%d%d%d",&d,&h,&m);
		d1=d2=d;
		m1=m;
		m2=m+1;
	end else begin
		int d,h,m;
		scanf("%d%d%d",&d,&h,&m);
		d1=d;m1=m;
		scanf("%d%d%d",&d,&h,&m);
		d2=d;m2=m;
	end;
	long long t1,t2,T1,T2;
	t1=1LL*(360-d1)*m1;
	T1=1LL*(720-d1)*m1;
	t2=1LL*(360-d2)*m2;
	T2=1LL*(720-d2)*m2;
	if t1>t2 then begin
		std::swap(t1,t2);
		std::swap(T1,T2);
	end;
	if t1==t2 then begin
		puts("0");
	end else begin
		if t2>=T1 then begin
			puts("1");
		end else begin
			puts("0");
		end;
	end;
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