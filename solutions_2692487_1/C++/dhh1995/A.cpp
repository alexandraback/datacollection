#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
int A,n,ans,res,a[1000005];
void read(int &x)
{
	#define CH getchar()
	char ch; x=0; for (ch=CH;ch<'0' || ch>'9';ch=CH);
	for (;ch>='0' && ch<='9';x=x*10+ch-48,ch=CH);
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T,Case=0; read(T);
	while (T--){
		read(A),read(n),ans=n,res=0;
		rep(i,n) read(a[i]); sort(a,a+n);
		if (A>1) rep(i,n){
			while (A<=a[i]) A+=A-1,res++;
			A+=a[i],ans=min(ans,res+n-1-i);
			}
		printf("Case #%d: %d\n",++Case,ans);
		}
	return 0;
}
