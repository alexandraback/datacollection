#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
using namespace std;

#define endl '\n'
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define uniq(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef pair<int, int> P;
typedef unsigned int uint;
typedef unsigned long long ull;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};

const int inf = 1000000009;
const double eps = 1e-8;
const string yes = "YES", no = "NO";

int solve() {
    int d;
    cin >> d;
    vector<int> ps;
    int maxi = 0;
    for (int i = 0; i < d; i++) {
	int p;
	cin >> p;
	ps.push_back(p);
	maxi = max(maxi, p);
    }
    int res = inf;
    while (maxi >= 1) {
	int add = 0;
	for (int i = 0; i < d; i++) {
	    if (ps[i] > maxi) {
		add += (ps[i] / maxi - (ps[i] % maxi == 0 ? 1 : 0));
	    }
	}
	/*
	for (int i = 0; i < ps.size(); i++)
	    cerr << ps[i] << " ";
	cerr << endl << maxi << " " << (int)ps.size() - d << endl;
	*/
	res = min(res, maxi + add);
	maxi--;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
	cout << "Case #" << i << ": " << solve() << endl;
    }
}
