#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>

using std::pair;
using std::stringstream;
using std::next_permutation;
using std::sqrt;
using std::priority_queue;
using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;
using std::set;
using std::swap;
using std::random_shuffle;
using std::queue;
using std::sin;
using std::cos;
using std::make_pair;
using std::cos;
using std::cerr;

typedef long long ll; 
typedef pair<ll, ll> pll;
const long double PI = 3.14159265358979323846;  
const ll N = 1000 * 1000 * 10;
vector<ll> sqpal;
vector<ll> sqpalind;

int solve() {
	ll a, b;
	cin >> a >> b;
	int res = 0;
	for (int i = 0; i < sqpal.size(); ++i)
		if ((sqpal[i] >= a) && (sqpal[i] <= b))
			++res;
	return res;
}

bool pal(ll x) {
	stringstream s;
	s << x;
	string s1 = s.str();
	int n = s1.size();
	for (int i = 0; i < n; ++i)
		if (s1[i] != s1[n - i - 1])
			return false;
	return true;
}

void precalc() {
	for (ll i = 1; i <= N; ++i) {
		if ((pal(i)) && (pal(i * i))) {
			sqpal.push_back(i * i);
			sqpalind.push_back(i);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	precalc();
	/*cout << sqpal.size() << endl;
	for (int i = 0; i < sqpal.size(); ++i)
		cout << sqpal[i].first << "\t" << sqpal[i].second << endl;
	return 0;*/
	int t;
	//scanf("%d\n", &t);
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cout << "Case #" << i + 1 << ": " << solve() << endl;
		std::cerr << i << endl;
	}
	return 0;
}
