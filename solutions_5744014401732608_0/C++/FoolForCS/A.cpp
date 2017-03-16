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

int dp[7][7];
string get_s(int mask, int bits) {
	string ret;
	for (int i = 0; i < bits; ++i) {
		if (mask & 1) ret.push_back('1');
			else ret.push_back('0');
		mask >>= 1;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
void row_set(int x, int noOfzero, int mask, int bits) {
	for (int i = 0; i < noOfzero; ++i) dp[x][i] = 0;
	string s = get_s(mask, bits);
	for (int i = noOfzero, j = 0; j < bits; ++j, ++i) {
		dp[x][i] = s[j] - '0';
	}
}
int solve(int N) {
	int ans[N + 1];
	ans[1] = 1;
	for (int i = 2; i <= N; ++i) ans[i] = 0;
	for (int i = 2; i <= N; ++i) {
		for (int j = 1; j < i; ++j) {
			if (dp[j - 1][i - 1]) ans[i] += ans[j];
		}
	}
	return ans[N];
}
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
		int B, M;
		cin >> B >> M;
		if (B == 2) {
			int ma = 1 << (B - 1);
			for (int i1 = 0; i1 < ma; ++i1) {
							row_set(0, 1, i1, 1);
							row_set(1, 2, 0, 0);
							int ret = solve(B);
							if (ret == M) {
								cout << "POSSIBLE\n";
								print_array(B);
								goto beg;
							}
			}
		} else if (B == 3) {
			int ma = 1 << (B - 1);
			for (int i1 = 0; i1 < ma; ++i1) {
				for (int i2 = 0, ma2 = (ma >> 1); i2 < ma2; ++i2) {
							row_set(0, 1, i1, 2);
							row_set(1, 2, i2, 1);
							row_set(2, 3, 0, 0);
							int ret = solve(B);
							if (ret == M) {
								cout << "POSSIBLE\n";
								print_array(B);
								goto beg;
							}
				}
			}	
		} else if (B == 4) {
			int ma = 1 << (B - 1);
			for (int i1 = 0; i1 < ma; ++i1) {
				for (int i2 = 0, ma2 = (ma >> 1); i2 < ma2; ++i2) {
					for (int i3 = 0, ma3 = (ma2 >> 1); i3 < ma3; ++i3) {
							row_set(0, 1, i1, 3);
							row_set(1, 2, i2, 2);
							row_set(2, 3, i3, 1);
							row_set(3, 4, 0, 0);
							int ret = solve(B);
							if (ret == M) {
								cout << "POSSIBLE\n";
								print_array(B);
								goto beg;
							}
					}
				}
			}			
		} else if (B == 5) {
			int ma = 1 << (B - 1);
			for (int i1 = 0; i1 < ma; ++i1) {
				for (int i2 = 0, ma2 = (ma >> 1); i2 < ma2; ++i2) {
					for (int i3 = 0, ma3 = (ma2 >> 1); i3 < ma3; ++i3) {
						for (int i4 = 0, ma4 = (ma3 >> 1); i4 < ma4; ++i4) {
							row_set(0, 1, i1, 4);
							row_set(1, 2, i2, 3);
							row_set(2, 3, i3, 2);
							row_set(3, 4, i4, 1);
							row_set(4, 5, 0, 0);
							int ret = solve(B);
							if (ret == M) {
								cout << "POSSIBLE\n";
								print_array(B);
								goto beg;
							}
						}
					}
				}
			}
		} else if (B == 6) {
			int ma = 1 << (B - 1);
			for (int i1 = 0; i1 < ma; ++i1) {
				for (int i2 = 0, ma2 = (ma >> 1); i2 < ma2; ++i2) {
					for (int i3 = 0, ma3 = (ma2 >> 1); i3 < ma3; ++i3) {
						for (int i4 = 0, ma4 = (ma3 >> 1); i4 < ma4; ++i4) {
							for (int i5 = 0, ma5 = (ma4 >> 1); i5 < ma5; ++i5) {
								row_set(0, 1, i1, 5);
								row_set(1, 2, i2, 4);
								row_set(2, 3, i3, 3);
								row_set(3, 4, i4, 2);
								row_set(4, 5, i5, 1);
								row_set(5, 6, 0, 0);
								int ret = solve(B);
								if (ret == M) {
									cout << "POSSIBLE\n";
									print_array(B);
									goto beg;
								}
							}
						}
					}
				}
			}
		}
		cout << "IMPOSSIBLE\n";
		beg:
		;
	}
}
