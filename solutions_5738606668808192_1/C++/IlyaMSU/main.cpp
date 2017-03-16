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

vector<int> primes;

void init() {
    vector<int> a(N, 1);
    for (int i = 2; i < N; ++i) {
        if (a[i]) {
            primes.push_back(i);
            for (int j = i + i; j < N; j += i)
                a[i] = 0;
        }
    }
}

bool divide(ll x, ll b, ll p, int n) {
    ll m = 1;
    ll r = 0;
    for (int i = 0; i < n; ++i) {
        if (x & 1)
            r = (r + m) % p;
        x /= 2;
        m = (m * b) % p;
    }
    return (r == 0);
}

void solve() {
    init();
    int n, j;
    cin >> n >> j;
    ll up = (1LL) << n;
    vector<int> div(11);
    for (ll x = ((1LL) << (n - 1)) + 1; x < up; x += 2) {
        bool ok = 1;
        for (int b = 2; b <= 10; ++b) {
            ok = 0;
            for (int j = 0; j < primes.size(); ++j) {
                int p = primes[j];
                if (divide(x, b, p, n)) {
                    div[b] = p;
                    ok = 1;
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        if (ok) {
            for (int i = 0; i < n; ++i) {
                cout << ((x >> (n - i - 1)) & 1);
            }
            for (int i = 2; i <= 10; ++i) {
                cout << "\t" << div[i];
            }
            cout << endl;
            --j;
            if (j == 0)
                return;
        }
        

    }

}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cout << "Case #" << i + 1 << ": " << endl;
        solve();
		std::cerr << i << endl;
	}
	return 0;
}
