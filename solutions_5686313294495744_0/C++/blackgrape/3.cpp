#include<bits/stdc++.h>
#define rep(i,x,y) for(i=x;i<y;i++)
#define rrep(i,x,y) for(i=x;i>=y;i--)
#define trv(y,x) for(typeof(x.begin())y=x.begin();y!=x.end();y++)
#define trvr(y,x) for(typeof(x.rbegin())y=x.rbegin();y!=x.rend();y++)
#define pb(f) push_back(f)
#define pi_ printf("\n")
#define pi(a) printf("%d\n",a)
#define pil(a) printf("%lld\n",a)
#define sc(a) scanf("%d",&a)
#define ll long long
#define scl(a) scanf("%lld",&a)
#define scs(a) scanf("%s",a)
#define mp make_pair
#define fi first
#define se second
#define mod 1000000007
#define inf 1000000009
#define maxn 100009
using namespace std;
//#include<windows.h>
FILE *fin = freopen("3.in","r",stdin);
FILE *fout = freopen("out.txt","w",stdout);
using namespace std;
typedef pair<int,int> pii;
typedef vector<int > vi;
typedef vector< pii > vpii;
string A[100],B[100];
int n,lans=0;
void rec(map<string,int> m1,map<string,int> m2,int i,int ans)
{
	if(i==n+1)
	{
		lans=max(lans,ans);
		return;
	}
	rec(m1,m2,i+1,ans);
	if(m1[A[i]]>=2&&m2[B[i]]>=2)
	{
		m1[A[i]]--;m2[B[i]]--;
		rec(m1,m2,i+1,ans+1);
	}
}
int main()
{
	int t,i,j,k,cas=0;
	sc(t);while(t--)
	{
		cas++;	printf("Case #%d: ",cas);
		lans=0;
		cin>>n;
		map<string,int> m1,m2;
		
		rep(i,1,n+1)
		{
			string a,b;cin>>a>>b;
			A[i]=a;B[i]=b;
			m1[a]++;m2[b]++;
		}
	//	pil(1);
		rec(m1,m2,1,0);
		cout<<lans<<endl;
	}
}
