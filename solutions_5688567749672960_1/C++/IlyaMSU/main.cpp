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

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 100;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll N = 1001;
//const int M = 10000000;



int rev(int x) {
    int res = 0;
    while (x) {
        res = 10 * res + (x % 10);
        x /= 10;
    }
    return res;
}
ll solve(ll n);

ll solve() {
    ll n;
    cin >> n;
    if (n < 10)
        return n;
    if ((n % 10) == 0)
        return 1 + solve(n - 1);
    else
        return solve(n);
}

ll solve2(ll n) {
    if (n < 10)
        return n;
    int sz = 0;
    ll m = n;
    ll xx = 1;
    vector<int> vn;
    while (m) {
        vn.push_back(m % 10);
        m /= 10;
        ++sz;
        xx *= 10;
    }
    xx /= 10;
    --sz;
    ll res = 0;
    if (sz == 0)
        res++;
    for (int i = 0; i < sz; ++i) {
        ll add = 1;
        for (int j = 0; j < (i + 2) / 2; ++j) {
            add *= 10;
        }
        if (i & 1) {
            res += add + add - 1;
        }
        else
            res += add + (add / 10) - 1;
    }
    //return res;
    ++sz;
    ll res1 = res + n - xx;
    ll x1 = 0;
    for (int i = 0; i * 2 < sz; ++i) {
        x1 = x1 * 10 + vn[(sz - 1) / 2 - i];
    }
    ll x2 = 0;
    for (int i = 0; i * 2 + 1 < sz; ++i) {
        x2 = x2 * 10 + vn[(sz + 1) / 2 + i];
    }
    ll res2 = res + x1 + x2;
    return min(res1, res2);
}

ll solve1(ll n) {
    vector<ll> res(n + 1, n + 2);
    res[1] = 1;
    for (int i = 1; i < n; ++i) {
        res[i + 1] = min(res[i] + 1, res[i + 1]);
        int x = rev(i);
        if (x < res.size())
            res[x] = min(res[x], res[i] + 1);
    }
    return res[n];

}

ll solve(ll n) {
    assert(solve1(n) == solve2(n));
    if (n < INF) {
        return solve1(n);        
    }
    return solve2(n);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tt;
	
	cin >> tt;
	for (int i = 0; i < tt; ++i) {
		cout << "Case #" << i + 1 << ": " << solve() << endl;
		std::cerr << i << endl;
	}
	return 0;
}
