#include <bits/stdc++.h>

#define gcd __gcd
#define bitcount __builtin_popcountll
#define getcx getchar_unlocked
#define rep(i,j,n) for(i=j;i<n;i++)
#define tr(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define pb push_back
#define mp make_pair
#define uset unordered_set
#define umap unordered_map
#define fi first
#define sc second
#define ft first
#define DEBUG 0
#define sum(a) accumulate(all(a),0)
#define unique(a) unique(all(a))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pill;
typedef pair<int, pi> pii;

template <class T> T& get(T &n) {
	cin >> n;
	return n;
}

#ifdef TRACE
template<class T> ostream& printContainer(ostream &o, const T &c) {
	tr(it, c) {
		o << *it << ' ';
	}
	return o;
}

template<class T> ostream& operator<<(ostream &o, const vector<T> &c) {return printContainer(o, c);}
template<class T> ostream& operator<<(ostream &o, const deque<T> &c) {return printContainer(o, c);}
template<class T> ostream& operator<<(ostream &o, const list<T> &c) {return printContainer(o, c);}
template<class T> ostream& operator<<(ostream &o, const set<T> &c) {return printContainer(o, c);}
template<class T> ostream& operator<<(ostream &o, const uset<T> &c) {return printContainer(o, c);}
template<class T> ostream& operator<<(ostream &o, const multiset<T> &c) {return printContainer(o, c);}
template<class T, class V> ostream& operator<<(ostream &o, const map<T, V> &c) {return printContainer(o, c);}
template<class T, class V> ostream& operator<<(ostream &o, const umap<T, V> &c) {return printContainer(o, c);}
template<class T, class V> ostream& operator<<(ostream &o, const pair<T, V> &c) {return (o << "(" << c.ft << "," << c.sc << ")");}

#define trace(x)                 cerr << #x << ": " << x << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace(x)
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif

const ll hell = 1000000007;
const ll INF = (ll)hell * hell;
const int MAXN = 1e6 + 5;

ll dp[7][7];
void print_array(int B){
	for(int i = 0; i < B; ++i){
		for(int j = 0; j < B; ++j){
			cout << dp[i][j];
		}
		cout << "\n";
	}
}
int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cout << "Case #" << tc << ": ";
		ll B, M;
		cin >> B >> M;
		vector< vector<ll> > dp(B);
		if(1LL << (B-2) < M){
			cout <<"IMPOSSIBLE\n";
			continue;
		}
		cout << "POSSIBLE\n";
		for(int i = 0; i < B; ++i){
			dp[i].resize(B, 0);
			for(int j = i+1; j < B - 1; ++j){
				dp[i][j] = 1;
			}
		}
		ll K = M;
		if(K == (1LL << (B - 2))) {
			for(int i = 0; i < B -1; ++i){
				dp[i][B-1] = 1;
			}	
		}
		else{
			for(int i = 0; i < B; ++i){
				if(i == 1) continue;
				dp[i][B-1] = (K & 1LL);
				K >>= 1;
			}
		}
		for(int i = 0; i < B; ++i){
			for(int j = 0; j < B; ++j){
				cout << dp[i][j];
			}
			cout << "\n";
		}
	}
}
