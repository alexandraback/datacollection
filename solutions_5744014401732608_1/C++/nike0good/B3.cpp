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
ll m, n;
int b[100][100];
ll f[56];
void go(int l,int r){
	Fork(i,l,r)
		Fork(j,i+1,r)
			b[i][j]=1;
	Fork(i,l,r) b[i][n]=1;
} 
int p2[55];
int c[100][100]; 
int main()
{
	freopen("B.in","r",stdin);
	freopen("b.out","w",stdout);
	
	f[0]=0;
	f[1]=f[2]=1;
	Fork(i,3,50) f[i]=f[i-1]*2LL;
	
	p2[0]=1;
	For(i,50) p2[i]=p2[i-1]*2ll;
	
	int T=read();
	For(kcase,T) {
		printf("Case #%d: ",kcase); 
		cin>>n>>m;
		
		if (m>f[n]) {puts("IMPOSSIBLE");
			continue;
		}	
		puts("POSSIBLE");
		
		MEM(b) 
		go(2,n);
		ll t=f[n];
		Fork(i,2,n){
			if (t-f[n-i+1]>=m) {
				t-=f[n-i+1];
			}else b[1][i]=1;
			if (!t) break;
		}
		
		For(i,n) Fork(j,i,n) b[j][i]=0;
		memcpy(c,b,sizeof(b));
		For(k,n)
			For(i,n) For(j,n)
				c[i][j]=c[i][j]+c[i][k]*c[k][j];
			
		
		For(i,n){
			For(j,n) if (b[i][j]&&i<j) putchar('1'); else putchar('0');puts("");
		}
//		cout<<c[1][n]<<endl;
		
		
	}
	
	
	return 0;
}

