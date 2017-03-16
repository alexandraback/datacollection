#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
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
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<functional>




using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll N = 1001;

ll toNum(const vector<int> x, ll b) {
    ll res = 0;
    ll m = 1;
    for (int i = 0; i < x.size(); ++i) {
        res += m * x[i];
        m *= b;
    }
    return res;
}

void solve() {
    ll k, s, c;
    cin >> k >> c >> s;
    if (k > c * s) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<int> x;
    for (int i = 0; i < k; ++i) {
        x.push_back(i);
        if (x.size() == c) {
            ll r = toNum(x, k);
            cout << r + 1 << "\t";
            x.clear();
        }
    }
    if (!x.empty()) {
        ll r = toNum(x, k);
        cout << r + 1 << "\t";
    }

    cout << endl;
  
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {		
		cout << "Case #" << i + 1 << ": ";
        solve();
		std::cerr << i << endl;
	}
	return 0;
}
