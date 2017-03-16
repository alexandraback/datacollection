#include <stdio.h>

#define if if (
#define then )
#define do )
#define for for (
#define while while (
#define begin {
#define end }

inline bool _solve()
begin
	int X,R,C;
	scanf("%d%d%d",&X,&R,&C);
	if X==1 then return true;
	if X>=7 then return false;
	if X==2 then begin
		return R*C%2==0;
	end;
	if X==3 then begin
		return R*C%3==0 && R>=2 && C>=2;
	end;
	if X==4 then begin
		if R==2 && C==2 then return false;
		return R*C%4==0 && R>=3 && C>=3;
	end;
	if X==5 then begin
		return R*C%5==0 && R>=3 && C>=3;
	end;
	if X==6 then begin
		return R*C%6==0 && R>=4 && C>=4;
	end;
end;

inline void solve()
begin
	puts(_solve() ? "GABRIEL" : "RICHARD");
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