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
int cnt[26];
double dp[101][101][101];
int trans[101][26];
//

double solve(){
	int K;
	int L, S;
	cin >> K >> L >> S;
	string a, b;
	cin >> a >> b;

	memset(cnt, 0, sizeof cnt);

	for(char c : a){
		cnt[c-'A']++;
	}

	for(char c : b){
		if(!cnt[c-'A']) return 0.0;
	}

	//cout << b << endl;
	// preprocess table
	memset(trans, 0, sizeof trans);
	for(int i = 1; i <= L; i++){
		// cout << i << " " ;
		for(int k = 0; k < 26; k++){
			char c = k+'A';
			int res = 0;
			for(int j = 0; j < i; j++){
				// match
				bool ok = true;
				if(j == 0){
					ok &= b[0] == c;
				}else{
					ok &= b[j] == c;
					for(int z = 0; z < j; z++){
						ok &= b[z] == b[i-j];
					}
				}
				if(ok) res = j+1;
			}
			trans[i][k] = res;
			//cout << c << " " << trans[i][k] << " ";
		}
		//cout << endl;
	}

	// count max occur
	int cntmax = 0;
	int x = 0;
	while(x + L-1 < S){
		cntmax++;
		x = x + L - trans[L-1][b[L-1]-'A'];

	}
		//cout << "TRANS" << " " << trans[L-1][b[L-1]-'A'] << endl;
	 //cout << "CNT MAX " << cntmax << endl;

	// dp
	memset(dp, 0, sizeof dp);
	dp[0][0][0] = 1.0;

	for(int i = 0; i < S; i++){
		for(int j = 0; j < L; j++){
			for(int z = 0; z <= S; z++){
				if(j < L-1){
					dp[i+1][j+1][z] += dp[i][j][z] * (double)cnt[b[j]-'A']/K;
				}else if(j == L-1){
					dp[i+1][trans[L-1][b[L-1]-'A']][z+1] += dp[i][j][z] * (double)cnt[b[j]-'A']/K;
				}

				// cada prefixo uma transição distinta
				for(int k = 0; k < 26; k++){
					char c = k+'A';
					if(c != b[j] && cnt[k] > 0)
						dp[i+1][trans[j][k]][z] += dp[i][j][z] * (double)cnt[k]/K;
				}
			}
		}
	}

	double ans = 0.0;
	for(int j = 0; j <= L; j++)
		for(int z = 1; z <= S; z++){
			ans += dp[S][j][z]*z;
		}

	return (double)cntmax - ans;
}

void solve(int tn){
	printf("Case #%d: %.11lf\n", tn, solve());
}

int main(){
	int tt; cin >> tt;
	for(int t = 1; t <= tt; t++)
		solve(t);
}
