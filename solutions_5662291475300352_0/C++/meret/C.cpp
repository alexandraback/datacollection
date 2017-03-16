
#include <bits/stdc++.h>
#include <sys/time.h>

using namespace std;

#define FI first
#define SE second
#define X first
#define Y second
#define ST first
#define ND second
#define MP make_pair
#define PB push_back

typedef long long LL;
typedef vector<int> VI;
typedef long double LD;
typedef pair<int,int> PII;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))

double getTime() {
	timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec + tv.tv_usec * 1e-6;
}

const int N = 500005;

int start[N];
int lap[N];
double speed[N];

double time_encounter(int i, int j, double t) {
    if (lap[i] > lap[j]) {
        swap(i, j);
    }
    double posi = start[i] / 360.0 + t * speed[i];
    double posj = start[j] / 360.0 + t * speed[j];
    posi -= round(posi);
    posj -= round(posj);
    double dist = posj - posi;
    if (dist < 0) {
        dist += 1.0;
    }
    return t + dist / (speed[i] - speed[j]);
}

int n;

int dfs(int c, double t, int z = 0) {
    if (z > n) {
        return z;
    }
    double nx = t + 1e20;
    int meet = -1;
    REP (i, n) {
        if (lap[i] != lap[c]) {
            double cr = time_encounter(i, c, t);
            if (cr < nx) {
                nx = cr;
                meet = i;
            }
        }
    }
    if (meet == n - 1) {
        return z;
    }
    return min(dfs(c, nx + 1e-9, z + 1), dfs(meet, nx + 1e-9, z + 1));
}

int alg() {
    int n_groups;
    cin >> n_groups;
    n = 0;
    REP (i, n_groups) {
        int di, hi, mi;
        cin >> di >> hi >> mi;
        REP (j, hi) {
            start[n] = di;
            lap[n] = mi + j;
            speed[n] = 1.0 / lap[n];
            ++n;
        }
    }
    start[n] = 0;
    lap[n] = (int) 2e9;
    speed[n] = 0.0;
    ++n;
    int c = 0;
    REP (i, n - 1) {
        if (start[i] < start[c] || (start[i] == start[c] && lap[i] > lap[c])) {
            c = i;
        }
    }
    return dfs(c, 1e-9);
}

int main() {
    int d;
    cin >> d;
    FOR (i, 1, d + 1) {
        cout << "Case #" << i << ": " << alg() << endl;
    }
}
