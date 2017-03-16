

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ull> vull;
typedef vector<ll> vll;

// TIMER
std::clock_t __start;
double __duration;
void start_timer() { __start = std::clock(); }
void print_timer() {
	__duration = (std::clock() - __start) / (double)CLOCKS_PER_SEC;
	std::cout << "Duration: " << __duration << '\n';
}
// END TIMER

//PI
# define M_PI		3.14159265358979323846
// fast input
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
//char _;

template <class T>
T min_(T a, T b) { return (a < b ? a : b); }
template <class T>
T max_(T a, T b) { return (a > b ? a : b); }
double EPS = 1e-9;
bool eq_(const double& lhs, const double &rhs) {
	return (fabs(lhs - rhs) < EPS);
}

const int INF = int(2e9);
const ll INF_LL = ll(1e18);
const int MAX_N = 1e7;

bool is_set(ll num, ll bit) {
	ll mask = 1;
	return (num &  (mask << bit));
}

ll MSB(ll n)
{
	ll one = 1;
	ll mask = 1;
	for (ll i = 62; i >= 0; --i)
	{
		mask = one << i;
		if ((mask & n) != 0)
			return i;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//start_timer();

	ifstream fin("b.in");
	ofstream fout("b.out");

	int T;
	ll B, M;
	fin >> T;
	for (int t = 0; t < T; ++t) {
		fin >> B >> M;
		fout << "Case #" << t + 1 << ": ";
		ll max_paths = pow(2ll, B - 2);
		if (M > max_paths) {
			fout << "IMPOSSIBLE\n";
			continue;
		}
		else {
			fout << "POSSIBLE\n";
		}
		vector<vector<char>> res(B, vector<char>(B, '0'));

		if (M == max_paths) {
			for (int i = 0; i < B; ++i) {
				for (int j = 0; j < B; ++j) {
					if (j > i)
						res[i][j] = '1';
				}
			}
		}
		else {
			ll msb_idx = B - 2 - MSB(M);

			for (int i = msb_idx; i < B-1; ++i) {
				for (int j = 0; j < B; ++j) {
					if (j > i) {
						res[i][j] = '1';
					}
				}
			}
			for (int j = 0; j <= B-3; ++j) {
				if (is_set(M, j))
					res[0][B-2-j] = '1';
			}
		}
		for (int i = 0; i < B; ++i) {
			for (int j = 0; j < B; ++j) {
				fout << res[i][j];
			}
			fout << '\n';
		}
	}

	//print_timer();
	return 0;
}
