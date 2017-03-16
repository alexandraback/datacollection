#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mii;

// Input macros
#define RI                          ({int a; scanf("%d", &a); a;})
#define RL                          ({long long a; cin >> a; a;})
#define RS                          ({string a; cin >> a; move(a)})
#define RD                          ({double a; scanf("%lf", &a); a;})
#define RC                          ({char a; cin >> a; a;})

// Useful constants
const int INF =                     numeric_limits<int>::max();
const int HINF =                    (INF/2-1);
const double EPS =                     1e-9;
const int dy [] =                   {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx [] =                   {0, 1, 1, 1, 0, -1, -1, -1};
const double pi =                      3.1415926535897932384626;

// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define bitfirst                    __builtin_ctz // count trailing zeros
#define bitlast                     __builtin_clz // count leading zeros

// Useful comparation
#define bet(x,a,b) (a<x&&x<b)
#define beti(x,a,b) (a<=x&&x<=b)
#define remax(a,b) (a)=max((a),(b)) // set a to the maximum of a and b
#define remin(a,b) (a)=min((a),(b));

// Useful container manipulation / traversal macros
#define rep(i,a,b)               for(int i=a;i<b;i++)
#define repi(i,a,b)              for(int i=a;i<=b;i++)
#define rrep(i,a,b)              for(int i=a;i>b;i--)
#define rrepi(i,a,b)             for(int i=a;i>=b;i--)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define ms(a,v)                     memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair

// Bit ops
#define bit(x,i) ((x>>i)&1ull)  //select the bit of position i of x
#define bitset(x, i) (x|(1ull<<i))
#define bittog(x, i) (x^(1ull<<i))
#define bitclear(x,i) (x&(0ull<<i))
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x


// Global Variables and Constants
int d[10000001];
//

int revert(ll x){
	string s = to_string(x);
	int res = 0;
	for(int i = s.size()-1; i >= 0; i--){
		res = (res*10) + (s[i]-'0');
	}
	return res;
}

void solve(int tn){
	memset(d, 0x3f3f3f3f, sizeof d);

	ll n; cin >> n;
	int cur = 1;
	queue<int> q;
	q.push(1);
	d[1] = 0;

	while(!q.empty()){
		int u = q.front(); q.pop();

		if(u+1 < 10*n && d[u]+1 < d[u+1]) {
			d[u+1] = d[u]+1, q.push(u+1);
		}
		int rev = revert(u);
		if(rev < 10*n && d[u]+1 < d[rev]) {
			d[rev] = d[u]+1, q.push(rev);
		}
	}

	int ans = d[n]+1;
	cout << "Case #" << tn << ": " << ans << endl;
}

int main(){
	int tt; scanf("%d", &tt);
	for(int t = 1; t <= tt; t++)
		solve(t);
}
