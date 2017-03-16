#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(A) (int)A.size()
#define RFOR(i,a,b) for (int (i) = (a); (i) >= (b); --(i))
#define ll long long
#define ld long double
#define sz(A) (int)A.size()

#define FREIN(FILE) freopen(FILE,"rt",stdin)
#define FREOUT(FILE) freopen(FILE,"wt",stdout)

#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__, 5,4,3,2,1))
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,N,...) N
#define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
#define macro_dispatcher___(macro, nargs) macro ## nargs
#define DBN1(a)         std::cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)       std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)     std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)   std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e) std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)
#define DA(a,n) cout<<#a<<"=["; printarray(a,n); cout<<"]\n"
#define DAR(a,n,s) cout<<#a<<"["<<s<<"-"<<n-1<<"]=["; printarray(a,n,s); cout<<"]\n"

typedef vector < int > vi;
typedef pair <int, int> pii;

template<typename T1, typename T2>inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){ return os << "(" << p.first << ", " << p.second << ")"; }
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::vector<T>& v){ bool first = true; os << "["; for (unsigned int i = 0; i<v.size(); i++){ if (!first)os << ", "; os << v[i]; first = false; }return os << "]"; }
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::set<T>&v){ bool first = true; os << "["; for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os, const std::map<T1, T2>& v){ bool first = true; os << "["; for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
template<typename T, typename T2>void printarray(T  a[], T2 sz, T2 beg = 0){ for (T2 i = beg; i<sz; i++) cout << a[i] << " "; cout << endl; }
const int inf = 1e9;
const int MOD = 1e9 + 7;
const int N = 4e6 + 10;
const int INF = 1000111000;
string s;
int a[55];
int n;
int xn, x, mask;
int dp[(1 << 15)];
bool bit(int mask, int x) {
	mask &= (1 << x);
	return mask > 0;
}
void generate() {
	s.resize(10);
	for (int i = 0; i < sz(s); ++i) 
		if (rand() % 2) 
			s[i] = '+';
		else
			s[i] = '-';
}
void read() {
	//generate(); return;
	cin >> s;
}
int change(int mask, int c) {
	REP(i, n) a[i] = bit(mask, i);
	REP(i, c) a[i] = 1 - a[i];
	REP(i, c) {
		int j = c - i - 1;
		if (i < j)
			swap(a[i], a[j]);
	}
	mask = 0;
	REP(i, n) mask = mask  + a[i] * (1 << i);
	return mask;
}
int stupid(string s) {
	n = sz(s);
	REP(i, (1 << n)) dp[i] = INF;
	mask = 0;
	REP(i, n) 
		if (s[i] == '+') 
			mask += (1 << i);
	dp[mask] = 0;
	vi Q;
	Q.pb(mask);
	int cur = 0;
	while (cur < sz(Q)) {
		int x = Q[cur++];
		REP(i, n) {
			xn = change(x, i + 1);
			if (dp[xn] > dp[x] + 1) {
				dp[xn] = dp[x] + 1;
				Q.pb(xn);
			}
		}
	}
	return dp[(1 << n) - 1];
}
int solve2() {
	string s;
	s = ::s;
	int n = sz(s);
	int dp[105][2];
	REP(i, n + 1)
		REP(j, 2)
			dp[i][j] = INF;
	dp[0][0] = 0;
	dp[0][1] = 0;
	REP(i, n) {
		int c = 0;
		if (s[i] == '+')
			c = 1;
		if (!c) {
			dp[i + 1][0] = min(dp[i + 1][0], dp[i][0]);
			dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + 1);
			
			dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + 1);
			dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + 3);
			continue;
		}	
		dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + 1);
		dp[i + 1][1] = min(dp[i + 1][1], dp[i][1]);
		
		dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + 3);
		dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + 1);
			
		
	}
	return dp[n][1];
}
int solve() {
	string s;
	s = ::s;
	int ans = 0;
	int n = sz(s);
	RFOR(i, n - 1, 0) {
		if (s[i] == '+')
			continue;
		if (s[0] == '+') {
			ans++;
			s[0] = '-';
		}
		REP(j, i+1) {
			int cur = i - j;
			if (cur < j)
				break;
			swap(s[j], s[cur]);
		}
		REP(j, i+1)
			if (s[j] == '+')
				s[j] = '-';
			else
				s[j] = '+';
		ans++;
		
	}
	return ans;
}
int main() {
	FREIN("input.txt");
	FREOUT("output.txt");
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	REP(it, t) {
		read();
		cout << "Case #" << it + 1 << ": " << solve2() << endl;
	}
	
	return 0;
}

