/*******************
  	Rahul Bhati
	CHARUSAT UNIVERSITY
	***********************/

#include <bits/stdc++.h>

using namespace std;

/* Time saving techniques :D */

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair< int ,int > pii;
typedef istringstream iss;
typedef ostringstream oss;

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define ln              length()
#define rep(i,n)        for(int i=0;i<n;i++)
#define fu(i,a,n)       for(int i=a;i<=n;i++)
#define fd(i,n,a)       for(int i=n;i>=a;i--)
#define foreach(it,v)   for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
#define all(a)          a.begin(),a.end()
#define INF             (int)1e9
#define EPS             (1e-9)
#define INF_MAX         2147483647
#define INF_MIN         -2147483647
#define pi              acos(-1.0)
#define countones(s)    __builtin_popcount(s)
#define N               1000000
#define si(n)           scanf("%d",&n)
#define sll(n)          scanf("%lld",&n)
#define dbg(x)          { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y)       { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define mset(a, s)      memset(a, s, sizeof (a))
#define precout(a,b)    cout<<fixed << setprecision((b)) << (a)
#define FI              freopen("in.txt", "r", stdin);
#define FO              freopen("out.txt", "w", stdout);

int revint(int n){
	int sum = 0;
	while(n!=0){
		sum = sum*10 + n%10;
		n/=10;
	}
	return sum;
}

ll dp[1000005];
ll calc()
{
   dp[0]=0;
   for(int  i=1;i<=10;i++){
   	dp[i]=dp[i-1]+1;
   }
   for(int i=11;i<=1000000;i++){
   		ll r=revint(i);
   		if(r!=i && dp[r]!=-1 && i%10!=0){
			dp[i]=min(dp[i-1]+1,dp[r]+1);
   		}
   		else{
   			dp[i]=dp[i-1]+1;
   		}
   }
}
// Ya its Dp :D
int main(){     FI FO
    ios::sync_with_stdio(false);
    cin.tie(0);
    mset(dp,-1);
    calc();
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        int n;
		cin>>n;
        cout<<"Case #"<<cs<<": "<<dp[n]<<endl;
    }
    return 0;
}

