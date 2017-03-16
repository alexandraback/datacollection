# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

// Input macros
#define s(n)                        scanf("%d",&n)
#define p(n)                        printf("%d\n",n)
#define pl(n)                       printf("%lld\n",n);
#define INF                         (int)1e9
#define EPS                         1e-9
// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define mod 1000000007LL

// Useful container manipulation / traversal macros
#define all(n)                      for(int i=0;i<n;i++)
#define alls(m)                     for(int j=0;j<m;j++)
#define rep(a,n)                    for(int i=a;i<n;i++)
#define each(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all1(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair
#define init(Arr) memset((Arr), 0, sizeof (Arr))

inline ll binpow(ll x,ll n){ll res=1;while(n){if(n&1)res*=x;x*=x;n>>=1;}return res;}
inline ll powmod(ll x,ll n, ll _mod){ll res=1;while(n){if(n&1)res=(res*x)%_mod;x=(x*x)%_mod;n>>=1;}return res;}
inline ll mulmod(ll x,ll n, ll _mod){ll res=0;while(n){if(n&1)res=(res+x)%_mod;x=(x+x)%_mod;n>>=1;}return res;}
inline ll gcd(ll a,ll b){ll t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int a,b,c,d,i,j,k,n,m,t,ar[1000001],flag,w[1010][1010],l;
string ch,ch2,s,word;
pii p;

double ans,cur;

bool myfunction (int i,int j) { return (i<j); }

void calc(string s)
{
	b=0;
	for(i=0;i<s.size();i++)
	{
		if(n-i>=l)
			if(s.substr(i,l)==word){
				ans+=cur;
				b++;
			}
	}
	a=max(a,b);
}



void make(string s)
{

	if(s.size()==n)
	{
		calc(s);
		return;
	}

	for(int i=0;i<k;i++){
		make(s+ch[i]);
	}


}


int main()
{
 	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int cases;
	cin>>cases;

	 for(t=1;t<=cases;t++)
	 {

		ans=0;
		cur=0;
		a=0;
		
		cout<<"Case #"<<t<<": ";
		s(k);
		s(l);
		s(n);
		cin>>ch;
		cin>>word;
		cur=1/double(pow(k,n));

		make("");

		printf("%.9f\n",a-ans);
		//cout<<ans;


	}


	return 0;

}
