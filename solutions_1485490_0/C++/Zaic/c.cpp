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

int main() {
	ios_base::sync_with_stdio(false);
	int T; cin >> T;
	for(int it = 1; it <= T; it++) {
        cerr << it << endl;
        int n, m; cin >> n >> m;
        vector<pip> a, b;
        read(n, a);
        read(m, b);
        n = Sz(a);
        m = Sz(b);
        int64 res = 0;
        if(n == 1 || (n == 3 && a[0].second == a[2].second)) {
            for(auto i: b)
                if(i.second == a.front().second)
                    res += i.first;
            int64 limit = a[0].first;
            if(n == 3) limit += a[2].first;
            res = min(res, limit);
        }
        if(n == 2 || n == 3) {
            if(n < 3) a.push_back(pip(0, -1));
            for(int i = 0; i <= m; i++)
                for(int j = i; j <= m; j++) {
                    int64 curres[3] = {0, 0, 0};
                    for(int k = 0; k < m; k++) {
                        if(k < i) {
                            if(b[k].second == a[0].second) curres[0] += b[k].first;
                        } else if(k < j) {
                            if(b[k].second == a[1].second) curres[1] += b[k].first;
                        } else {
                            if(b[k].second == a[2].second) curres[2] += b[k].first;
                        }
                    }
                    int64 cres = 0;
                    for(int k = 0; k < 3; k++) cres += min(curres[k], a[k].first);
                    res = max(res, cres);
                }
        }
        cout << "Case #" << it << ": " << res << endl;
	}

	return 0;
}
