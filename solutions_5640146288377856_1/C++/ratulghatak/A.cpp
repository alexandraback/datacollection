#include<bits/stdc++.h>

using namespace std;

#define ll long long int 
#define ss1(a) scanf("%d",&a)
#define ss2(a,b) scanf("%d %d",&a,&b)
#define ss3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loope(i,a,b) for(int i=a;i<=b;i++)
#define loopd(i,a,b) for(int i=a;i>=b;i--)
#define Loop(i,a,b) for(ll i=a;i<b;i++)
#define Loope(i,a,b) for(ll i=a;i<=b;i++)
#define Loopd(i,a,b) for(ll i=a;i>=b;i--)

#define pii pair<int,int>
typedef vector<int> vi; 
typedef vector< vi > vvi;  
#define setzero(a) fill(a,a+sizeof(a),0);
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define DEBUG if(0)

ll gcd(ll a,ll b){ return (b==0)?a:gcd(b,a%b); } ll lcm(ll a, ll b) { return (a*b)/gcd(a,b); }
ll modpow(ll a, ll n, ll mod){ ll res=1; while(n){ if(n&1)res=(res*a)%mod; a=(a*a)%mod; n>>=1; } return res; }
ll lpow(ll a, ll n){ ll res=1; while(n){ if(n&1)res*=a; a*=a; n>>=1; } return res; }
/*******************************MAIN CODE STARTS*******************************/

int r,c,w;
void Scan()
{
	cin>>r>>c>>w;
	return;
}

int Out()
{
	int res=(r-1)*(c/w);
	res+=(c/w); res--;
	if(c%w!=0) res++;
	res+=w;
	return res;
}
int main()
{
	int t;cin>>t;
	loope(z,1,t)
	{
		Scan();
		printf("Case #%d: %d\n",z,Out());
	}
	return 0;
}
