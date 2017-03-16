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
int n, cnt;
vi ans;
bool bit(ll mask, int x) {
	mask &= (1LL << x);
	return mask > 0;
}
long long prime(long long n) {
	if (n == 0 || n == 1)
		return -1;
	for (long long i = 2; i * i <= n; ++i) 
		if (n % i == 0) 
			return i;
	return -1;
}
bool check(int mask) {
	FOR(d, 2, 11) {
		long long pw = 1;
		long long cur = 0;
		REP(i, n) {
			if (bit(mask, i)) 
				cur += pw;
			pw *= d;
		}
		if (prime(cur) != -1) continue;
		return false;
	}
	return true;
}
int main() {
	FREIN("input.txt");
	FREOUT("output.txt");
	ios::sync_with_stdio(false);
	int t; cin >> t;
	cout << "Case #1:" << endl;
	cin >> n >> cnt;
	REP(i, (1 << n)) {
		if (!bit(i, 0) || !bit(i, n-1))
			continue;
		if (sz(ans) == cnt)
			break;
		if (check(i)) {
			ans.pb(i);
		}
	}
	REP(i, sz(ans)) {
		int mask = ans[i];
		RFOR(j,n-1,0)
			if(bit(mask,j))
				cout<<1;
			else
				cout<<0;
		FOR(d, 2, 11) {
			long long pw = 1;
			long long cur = 0;
			REP(i, n) {
				if (bit(mask, i)) 
					cur += pw;
				pw *= d;
			}
			cout << " " << prime(cur);
		}
		cout << endl;
	}
	return 0;
}

