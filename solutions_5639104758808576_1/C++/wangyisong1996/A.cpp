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
	int i;
	for i=0;i<=n;i++ do begin
		ch=getchar();
		while ch<=32 do ch=getchar();
		a[i]=ch-48;
	end;
	int ans=0;
	int sum=0;
	for i=0;i<=n;i++ do begin
		if sum<i then begin
			ans+=i-sum;
			sum=i;
		end;
		sum+=a[i];
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