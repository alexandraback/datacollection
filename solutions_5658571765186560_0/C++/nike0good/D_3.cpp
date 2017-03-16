#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<ctime>
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
#define MAXN (20+10)
typedef long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int T,x,n,m; 
int main()
{
	freopen("D-small-attempt2.in","r",stdin);
	freopen("D-small-attempt2.out","w",stdout);
	
	cin>>T;
	For(kcase,T)
	{
		printf("Case #%d: ",kcase);
		
		scanf("%d%d%d",&x,&n,&m);
		if (n>m) swap(n,m); //n<=m
		
		if (x>=7 || n*m%x!=0 || max(n,m)<x ) 
		{
			printf("RICHARD\n");
		}		
		else 
		{
			if (n>x&&m>x) printf("GABRIEL\n");
			else if (n==x&&m>=x) printf("GABRIEL\n");
			else if (n==x-1&&m==x) printf("GABRIEL\n");
			else if (n<=x&&m<=x) printf("RICHARD\n");
			else printf("GABRIEL\n");
		}
		

		
		
		
	}
	
	
	return 0;
}

