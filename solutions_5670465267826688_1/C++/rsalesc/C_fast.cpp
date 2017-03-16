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
char mult[257][257];
char neg[257];
//

bool is_neg(char x){
	if(x == '-' || (x >= 'a' && x <= 'c')) return true;
	return false;
}

char multiply(char a, char b){
	if(is_neg(a) && is_neg(b))
		return mult[neg[a]][neg[b]];
	else if(is_neg(a))
		return neg[mult[neg[a]][b]];
	else if(is_neg(b))
		return neg[mult[a][neg[b]]];
	else
		return mult[a][b];
}

void solve(int tn){
	long long L, X;
	cin >> L >> X;
	
	long long n = min(8ll, X) * L;
	string s; cin >> s;
	
	long long f1, last_f3;
	f1 = 0, last_f3 = 0;
	set<long long> f2, f3;
	char cur = '1';
	for(long long i = 1; i <= n; i++){
		cur = ::multiply(cur, s[(i-1)%L]);
		if(!f1){
			if(cur == 'i') f1 = i;
		}
		
		if(cur == 'k') f2.insert(i);
		else if(cur == '-') f3.insert(i), last_f3 = i;
	}
	
	bool ok = false;
	if(X <= 8ll){
		if(f1 > 0){
			set<long long>::iterator it2 = f2.upper_bound(f1);
			if(it2 != f2.end())
				ok = (last_f3 == n);
		}
	}else{
		if(f1 > 0 && f2.size() > 0 && f3.find((L*X-1)%(8ll*L)+1) != f3.end()) ok = true;
	}
	
	cout << "Case #" << tn << ": ";
	
	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main(){
	mult['1']['1'] = '1';
	mult['1']['i'] = 'i';
	mult['1']['j'] = 'j';
	mult['1']['k'] = 'k';
	
	mult['i']['1'] = 'i';
	mult['i']['i'] = '-';
	mult['i']['j'] = 'k';
	mult['i']['k'] = 'b';
	
	mult['j']['1'] = 'j';
	mult['j']['i'] = 'c';
	mult['j']['j'] = '-';
	mult['j']['k'] = 'i';
	
	mult['k']['1'] = 'k';
	mult['k']['i'] = 'j';
	mult['k']['j'] = 'a';
	mult['k']['k'] = '-';

	neg['1'] = '-';
	neg['i'] = 'a';
	neg['j'] = 'b';
	neg['k'] = 'c';
	neg['-'] = '1';
	neg['a'] = 'i';
	neg['b'] = 'j';
	neg['c'] = 'k';
	
	int tt; cin >> tt;
	for(int t = 1; t <= tt; t++)
		solve(t);
}
