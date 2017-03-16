
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

int alg() {
    int n;
    cin >> n;
    vector<int> v(n);
    REP (i, n) {
        cin >> v[i];
    }
    int result = (int) 1e9;
    FOR (mx, 1, 1000) {
        int s = mx;
        REP (i, n) {
            s += (v[i] - 1) / mx;
        }
        result = min(result, s);
    }
    return result;
}

int main() {
    int d;
    cin >> d;
    REP (i, d) {
        cout << "Case #" << i + 1 << ": " << alg() << endl;
    }
}
