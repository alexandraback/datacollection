#include <stdio.h>

#define if if (
#define then )
#define do )
#define for for (
#define while while (
#define begin {
#define end }

char ch;
inline void read(int &x)
begin
	x=0;ch=getchar();
	while ch<=32 do ch=getchar();
	while ch>32 do x=x*10+ch-48,ch=getchar();
end;

int a[1005];

inline void solve()
begin
	int n;
	read(n);
	int i,j;
	for i=1;i<=n;i++ do begin
		read(a[i]);
	end;
	int ans=0x3f3f3f3f;
	for i=1;i<=1000;i++ do begin
		int tmp=i;
		for j=1;j<=n;j++ do begin
			tmp+=(a[j]-1)/i;
		end;
		if tmp<ans then ans=tmp;
	end;
	printf("%d\n",ans);
end;

int main()
begin
	int T;
	read(T);
	int i;
	for i=1;i<=T;i++ do begin
		printf("Case #%d: ",i);
		solve();
	end;
end