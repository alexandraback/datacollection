#include<cstdio>
#include<algorithm>
using namespace std;
int T,Case,n,x,y,z,S,a[10005];
char d[]={'N','S','E','W'};
bool work(int n)
{
	z=abs(x);
	for (int i=n;i;i--) {a[i]=0; if (z>=i) z-=i,a[i]=2+(x<0);}
	for (int i=n;i;i--) if (!a[i]) if (z<y) z+=i; else z-=i,a[i]=1;
	return z==y;
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&x,&y),S=0,z=abs(x);
		for (n=1,S=1;S<z+abs(y) || (x+y&1)!=(S&1);S+=++n);
		while (!work(n)) n++;
		printf("Case #%d: ",++Case);
		for (int i=1;i<=n;i++) putchar(d[a[i]]); puts("");
		}
	return 0;
}


