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
#define MAXL (50000+10)
#define MAXX (1000000000000)
#define MAXLX (10000000000000000)
typedef long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int T;
char s[MAXL];
int a[MAXL];
bool b[MAXL]={0};
int f[5][5]={{},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};
int calc(int i,int j)
{
	int ans=a[i];
	Fork(t,i+1,j) ans=ans/abs(ans)*f[abs(ans)][a[t]];
	return ans;
}
int head[MAXL],s1=0,tail[MAXL],s2=0;
int main()
{
//	freopen("C-large.in","r",stdin);
//	freopen("C-large.out","w",stdout);
	
	cin>>T;
	For(kcase,T)
	{
		printf("Case #%d: ",kcase);
		
		int n;
		ll x;
		scanf("%d%lld",&n,&x);
		scanf("%s",s+1);
		For(i,n) a[i]=s[i]-'i'+2; 
		Fork(i,n+1,5*n) a[i]=a[i-n];
		
		int t=calc(1,n);
		
//		cout<<endl<<t<<endl;
		
		
		if (t==1|| (t>1&& x%4!=2 ) || (t<-1 && x%4!=2) || (t==-1 && x%2!=1 ) )
		{
			printf("NO\n");
			continue;
		}
		
		
		
		
		ll maxloop=0;
		if (t==1) maxloop=1;
		else if (t==-1) maxloop=2;
		else maxloop=4;
		maxloop=min(maxloop,x)*n;
		
		int flag1=0,flag2=0,flag=0;
		
		int ans=1;
		For(i,maxloop)
		{
			ans=ans/abs(ans)*f[abs(ans)][a[i]];
			if (ans==2) {flag1=i;break;	}			
		}
		
		ans=1;
		ForD(i,maxloop)
		{
			ans=ans/abs(ans)*f[a[i]][abs(ans)];
			if (ans==4) {flag2=n*x-maxloop+i;break;	}			
		}
		
		
		if (flag1==0||flag2==0) flag=0;
		else if (flag1+1<flag2) flag=1;
		else flag=0;
		
		if (flag) printf("YES\n"); else printf("NO\n");

	//	cout<<flag1<<' '<<flag2<<' '<<maxloop<<endl;
	}
	
	return 0;
}

