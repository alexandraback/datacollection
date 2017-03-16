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
#include <queue>
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
typedef pair<int, int> pip;

const int inf = 0x3f3f3f3f;
const int64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const real eps = 1e-8;

const int maxn = 1010;
vector<int> g[maxn];
int cnt[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	int T; cin >> T;
    for(int it = 1; it <= T; it++) {
        int n; cin >> n;
        for(int i = 0; i < n; i++) {
            g[i].clear();
            int m; cin >> m;
            for(int j = 0; j < m; j++) {
                int t; cin >> t; t--;
                g[i].push_back(t);
            }
        }

        bool ok = true;
        for(int i = 0; i < n; i++) {
            memset(cnt, 0, sizeof(cnt));
            cnt[i] = 1;
            queue<int> q;
            q.push(i);
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(int j : g[u]) {
                    if(!cnt[j]) q.push(j);
                    else {
                        ok = false;
                        break;
                    }
                    cnt[j]++;
                }
            }
            if(!ok) break;
        }
        printf("Case #%d: %s\n", it, !ok?"Yes":"No");
	}

	return 0;
}
