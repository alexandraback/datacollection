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
int hist[15];
int ans;
stack<int> zero;

void dfs(int u, int special){
	ans = min(ans, special + u);
	if(u == 0) return;
	
	for(int i = 2; i < u; i++){
		int next = u-1;
		int a = (i-(u%i)) * hist[u];
		int b = (u%i) * hist[u];
		hist[u/i] += a;
		hist[u/i+1] += b;
		while(hist[next] == 0) next--;
		dfs(next, special + (i - 1)*hist[u]);
		hist[u/i] -= a;
		hist[u/i+1] -= b;
	}
	
	/*zero.push(hist[0]);
	for(int i = 1; i <= u; i++) hist[i-1] = hist[i];
	int next = u-1;
	while(hist[next] == 0) next--;
	dfs(next, special+1);
	for(int i = 1; i <= u; i++) hist[i] = hist[i-1];
	hist[0] = zero.top(); zero.pop();*/
}

void solve(int tn){
	memset(hist, 0, sizeof hist);
	int n; scanf("%d", &n);
	int max_p = 1;
	ans = 0x3f3f3f3f;
	hist[1] = 1;
	for(int i = 0; i < n; i++) {
		int p; scanf("%d", &p);
		hist[p]++;
		 max_p = max(max_p, p);
	}
	
	dfs(max_p, 0);
	
	printf("Case #%d: %d\n", tn, ans);
}

int main(){
	int tt; scanf("%d", &tt);
	for(int t = 1; t <= tt; t++)
		solve(t);
}
