#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<ctime>
#include<queue>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=next[p])  
#define Lson (x<<1)
#define Rson ((x<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define MAXT (100+10)
#define MAXD (2000+10)
#define MAXPi (2000+10)
typedef long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int T,n,a[MAXD];
int main()
{
//	freopen("B-small-attempt3.in","r",stdin);
//	freopen("B-small-attempt3.out","w",stdout);
	
	cin>>T;
	For(kcase,T)
	{
		
		scanf("%d",&n);
		For(i,n) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		
		int ans=a[n];
		
		For(k,1000)
		{
			int sp=0;
			For(i,n)
				if (a[i]>k)
				{
					int l=ceil((double)a[i]/(double)k);
					sp+=l-1; 
				}
			
			
			ans=min(ans,sp+k);
		}
		
		
		printf("Case #%d: %d\n",kcase,ans);
	}
	
	return 0;
}

