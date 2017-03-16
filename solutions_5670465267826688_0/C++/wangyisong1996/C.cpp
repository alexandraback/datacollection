#include <stdio.h>

#define if if (
#define then )
#define do )
#define for for (
#define while while (
#define switch switch (
#define begin {
#define end }

char ch;
template <class T>
inline void read(T &x)
begin
	x=0;ch=getchar();
	while ch<=32 do ch=getchar();
	while ch>32 do x=x*10+ch-48,ch=getchar();
end;

int F[300][300];
int F1[300][300];

int a[10005*10];

inline int mul(int a,int b)
begin
	bool f=(a>128) ^ (b>128);
	a&=127;b&=127;
	int ret=F[a][b];
	f^=F1[a][b];
	return f ? ret+128 : ret;
end;

inline bool _solve()
begin
	int n;
	long long m;
	read(n);read(m);
	int m1=(m-1)%4+1;
	if m1+4<=m then m1+=4;
	int N=n*m;
	int i;
	for i=1;i<=n;i++ do begin
		ch=getchar();
		while ch<=32 do ch=getchar();
		a[i]=ch;
	end;
	for i=n+1;i<=N;i++ do begin
		a[i]=a[(i-1)%n+1];
	end;
	int now='1';
	for i=1;i<=N;i++ do begin
		now=mul(now,a[i]);
		if now=='i' then break;
	end;
	if i>N then return false;
	for ++i;i<=N;i++ do begin
		now=mul(now,a[i]);
		if now=='k' then break;
	end;
	if i>N then return false;
	for ++i;i<=N;i++ do begin
		now=mul(now,a[i]);
	end;
	if now!='1'+128 then return false;
	return true;
end;

inline void solve()
begin
	puts(_solve() ? "YES" : "NO");
end;

int main()
begin
	int T;
	read(T);
	F['1']['1']='1';
	F['1']['i']='i';
	F['1']['j']='j';
	F['1']['k']='k';
	
	F['i']['1']='i';
	F['i']['i']='1';
	F['i']['j']='k';
	F['i']['k']='j';
	
	F['j']['1']='j';
	F['j']['i']='k';
	F['j']['j']='1';
	F['j']['k']='i';
	
	F['k']['1']='k';
	F['k']['i']='j';
	F['k']['j']='i';
	F['k']['k']='1';
	
	F1['i']['i']=1;
	F1['i']['k']=1;
	F1['j']['i']=1;
	F1['j']['j']=1;
	F1['k']['j']=1;
	F1['k']['k']=1;
	
	int i;
	for i=1;i<=T;i++ do begin
		printf("Case #%d: ",i);
		solve();
	end;
end