#include <bits/stdc++.h>
using namespace std;

#define repu(i, a, b) for (int i = (a); i < (b); ++i)
#define repd(i, a, b) for (int i = (a); i > (b); --i)
#define mem(a, x) memset(a, x, sizeof(a))
#define all(a) a.begin(), a.end()
#define uni(a) a.erase(unique(all(a)), a.end())
#define count_bits(x) __builtin_popcount(x)
#define count_bitsll(x) __builtin_popcountll(x)
#define least_bits(x) __builtin_ffs(x)
#define least_bitsll(x) __builtin_ffsll(x)
#define most_bits(x) 32 - __builtin_clz(x)
#define most_bitsll(x) 64 - __builtin_clz(x)

vector<string> split(const string &s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c)) v.push_back(x);
	return v;
}

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }

void err(vector<string>::iterator it) {}

template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
	cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
	err(++it, args...);
}

typedef long long ll;
const int MOD = 1000000007;

template<class T, class U> inline T tmin(T a, U b) {return (a < b) ? a : b;}
template<class T, class U> inline T tmax(T a, U b) {return (a > b) ? a : b;}
template<class T, class U> inline void amax(T &a, U b) {if (b > a) a = b;}
template<class T, class U> inline void amin(T &a, U b) {if (b < a) a = b;}
template<class T> inline T tabs(T a) {return (a > 0) ? a : -a;}
template<class T> T gcd(T a, T b) {while (b != 0) {T c = a; a = b; b = c % b;} return a;}

const int N = 1000005, INF = 1e8;
int dp[N];

inline int rev(int x) {
	int ans = 0;
	while (x) {
		ans = 10 * ans + (x % 10);
		x /= 10;
	}
	return ans;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    
	int ntest;
	ll n;
	
	cin >> ntest;
	
	repu(t, 1, ntest + 1) {
		cin >> n;
		fill(dp, dp + n + 1, INF);
		dp[n] = 1;
		repd(i, n - 1, 0) {
			amin(dp[i], dp[i + 1] + 1);
			int x = rev(i);
			if (x > i && x <= n) amin(dp[i], dp[x] + 1);
		}
		
		printf("Case #%d: %d\n", t, dp[1]);
	}
	
    return 0;
}
