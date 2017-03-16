#include<cstdio>
#include<algorithm>
#include<cstring>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
int s[40],n,j,ans[40],p[100000],top,bz[100000];
int check(int x)
{
	int ans=1;
	while (ans<=top)
	{
		int tp=0,t1=0;
		fo(i,1,n) 
		{
			t1=t1*x+s[i];
			tp=tp*x%p[ans]+s[i];
		}
		if (t1!=tp && tp%p[ans]==0) return p[ans];
		ans++;
	}
	return -1;
}
int main()
{
	//freopen("D.in","r",stdin);
	//freopen("mybig.out","w",stdout);
	int T,pp=0;
	fo(i,2,100000)
		if (!bz[i]) {
			p[++top]=i;
			fo(j,2,100000/i) bz[i*j]=1;
		}
	scanf("%d",&T);
	while (T--)
	{
		pp++;
		scanf("%d%d",&n,&j);
		printf("Case #%d:\n",pp);
		s[n]=s[1]=1;
		fo(i,1,j)
		{
			int ok=1;
			fo(k,2,10) 
			{
				ans[k]=check(k);
				if (ans[k]==-1) ok=0;
			}
			if (ok==0)
			{
				s[n-1]++;
				fd(i,n-1,1) s[i-1]+=s[i]/2,s[i]%=2; 
				i--;
				continue;
			}
			fo(k,1,n) printf("%d",s[k]);
			fo(k,2,10) printf(" %d",ans[k]); 
			printf("\n");
			s[n-1]++;
			fd(i,n-1,1) s[i-1]+=s[i]/2,s[i]%=2; 
		}
	}
}
