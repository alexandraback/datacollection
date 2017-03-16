
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

int e[4][4] = {
    {0,1,2,3},
    {1,0,3,2},
    {2,3,0,1},
    {3,2,1,0}
};

bool neg[4][4] = {
    {0,0,0,0},
    {0,1,0,1},
    {0,1,1,0},
    {0,0,1,1}
};

string alg() {
    string s;
    LL x;
    int n;
    cin >> n >> x >> s;
    x = min(x, 128LL + x % 64);
    n *= x;
    string t;
    REP (i, x) {
        t += s;
    }
    s = t;
    int c = 0;
    bool sgn = 0;
    bool goti = false;
    bool gotk = false;
    REP (i, n) {
        int cr = 0;
        if (s[i] != '1') {
            cr = s[i] - 'i' + 1;
        }
        sgn ^= neg[c][cr];
        c = e[c][cr];
        if (c == 1 && !sgn) {
            goti = true;
        }
        if (c == 3 && !sgn && goti) {
            gotk = true;
        }
    }
    if (c == 0 && sgn && gotk) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int d;
    cin >> d;
    REP (i, d) {
        cout << "Case #" << i + 1 << ": " << alg() << endl;
    }
}
