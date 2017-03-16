#include<bits/stdc++.h>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define ForkD(i,k,n) for(int i=n;i>=k;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=Pre[x];p;p=Next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=Next[p])  
#define Lson (o<<1)
#define Rson ((o<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define pb push_back
#define mp make_pair 
#define fi first
#define se second
#define vi vector<int> 
#define pi pair<int,int>
#define SI(a) ((a).size())
typedef long long ll;
typedef unsigned long long ull;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+llabs(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
ll check(ll x,ll P) {
	ll ans=0,p=1;
	while(x) {
		ans+=x%2*p;
		x/=2; p*=P;
	}
//	cout<<ans<<endl;
	return ans;
}
ll calc(ll x){
	for(ll i=2;i*i<=x;i++) 
		if (x%i==0) return i;
	return 0;
}
void print(ll x) {
	if (x==1) {
		putchar('1');
	} else {
		print(x/2);cout<<x%2;
	}
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	
		
	int T=read();
	For(kcase,T) {
		printf("Case #%d:\n",kcase);
		int n=read(),J=read();
		ll t[20];
		Fork(S,1<<(n-1),(1<<n)-1) {
			if (!J) break; 
			if (S%2==0) continue;
			bool flag=0;
			Fork(i,2,10) if ((t[i]=calc(check(S,i)))==0) {flag=1;break;}
			if (flag) continue;
			J--;
			print(S);
			Fork(i,2,10) cout<<' '<<t[i];
			puts("");
		}
	}
	return 0;
}

