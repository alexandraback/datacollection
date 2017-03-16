#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;
typedef pair<int, int> pii;

#define sz size()
#define pb push_back
#define rep(k,a,b) for (int k = (a); k < (int)(b); k++)
#define rrep(k,a,b) for (int k = (a); k >= (int)(b); k--)
#define irep(k,a) for (auto& k: a)
#define all(c) (c).begin(), (c).end()
#define clr(a) memset((a),0,sizeof(a))
#define mi(r, c, v) vvi(r, vi(c, v))
#define md(r, c, v) vvd(r, vd(c, v))
//#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

const double eps = 10e-10;
const int inf = 0x3f3f3f3f;

int war(set<double> nb, set<double> kb) {
	int result = 0;
	irep(v, nb) {
		auto it = upper_bound(all(kb), v);
		if (it == kb.end())
			kb.erase(kb.begin());
		else {
			result++;
			kb.erase(it);
		}
	}
	return result;
}

int main() {
	fastio;

	int N;
	cin >> N;
	rep(X, 1, N + 1) {
		int n;
		cin >> n;
		set<double> nb, kb;

		rep(i, 0, n) {
			double v;
			cin >> v;
			nb.insert(v);
		}
		rep(i, 0, n) {
			double v;
			cin >> v;
			kb.insert(v);
		}

		int warout = n - war(nb, kb);
		int warout2 = war(kb, nb);
		printf("Case #%d: %d %d\n", X, warout2, warout);
	}
}