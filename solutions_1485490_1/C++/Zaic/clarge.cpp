#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>

#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

#ifdef ILIKEGENTOO
#define Eo(x) { cerr << #x << " = " << (x) << endl; }
#define E(x) { cerr << #x << " = " << (x) << "   "; }
#else
#define Eo(x)
#define E(x)
#endif
#if defined ILIKEGENTOO || !(defined __GNUC__ ) || (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 6))
template<typename T, size_t N> struct array { T val[N]; T& operator[](size_t n) { if(n >= N) assert(false); return val[n]; } T* begin() { return &val[0]; } T* end() { return &val[0]+N; } };
#else
#include <array>
#endif
#define EO(x) Eo(x)
#define Sz(x) (int((x).size()))
#define All(x) (x).begin(),(x).end()

template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }

typedef double real;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int64, int> pip;
typedef pair<int64, int64> piip;

const int inf = 0x3f3f3f3f;
const int64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const real eps = 1e-8;

void read(int n, vector<pip>& v) {
    v.clear();
    for(int i = 0; i < n; i++){
        int64 cnt; cin >> cnt;
        int type; cin >> type;
        if(Sz(v) && v.back().second == type)
            v.back().first += cnt;
        else
            v.push_back(pip(cnt, type));
    }
}

const int maxn = 111;
map<piip, int64> dp[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(false);
	int T; cin >> T;
	for(int it = 1; it <= T; it++) {
        cerr << it << endl;
        int n, m; cin >> n >> m;
        for(int i = 0; i < maxn; i++) for(int j = 0; j < maxn; j++) dp[i][j].clear();
        vector<pip> a, b;
        read(n, a);
        read(m, b);
        n = Sz(a);
        m = Sz(b);

        dp[0][0][piip(0, 0)] = 0;
        for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++) for(auto k : dp[i][j]) {
            if(i != n) {
                int64 res = k.second;
                piip ost = k.first;
                ost.first = a[i].first;
                if(j) {
                    int typea = a[i].second;
                    int typeb = b[j-1].second;
                    if(typea == typeb) {
                        int64 req = min(ost.first, ost.second);
                        res += req;
                        ost.first -= req;
                        ost.second -= req;
                    }
                }
                int64& t = dp[i+1][j][ost];
                t = max(t, res);
            }
            if(j != m) {
                int64 res = k.second;
                piip ost = k.first;
                ost.second = b[j].first;
                if(i) {
                    int typea = a[i-1].second;
                    int typeb = b[j].second;
                    if(typea == typeb) {
                        int64 req = min(ost.first, ost.second);
                        res += req;
                        ost.first -= req;
                        ost.second -= req;
                    }
                }
                int64& t = dp[i][j+1][ost];
                t = max(t, res);
            }
        }

        int64 res = 0;
        for(auto k : dp[n][m]) res = max(res, k.second);

        cout << "Case #" << it << ": " << res << endl;
	}

	return 0;
}
