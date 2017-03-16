
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

LL revn(LL c) {
    LL rev = 0;
    while (c > 0) {
        rev = 10LL * rev + (c % 10);
        c /= 10;
    }
    return rev;
}

map<LL, LL> dist;

LL alg() {
    queue<LL> q;
    dist[1LL] = 1;
    q.push(1LL);
    while (!q.empty()) {
        LL c = q.front();
        int cd = dist[c];
        q.pop();
        if (c + 1 <= 1000000) {
            if (dist.find(c + 1) == dist.end()) {
                dist[c + 1] = cd + 1;
                q.push(c + 1);
            }
        }
        LL rev = revn(c);
        if (rev <= 1000000) {
            if (dist.find(rev) == dist.end()) {
                dist[rev] = cd + 1;
                q.push(rev);
            }
        }
    }
}

int p10(LL x) {
    int res = 1;
    while (x >= 10) {
        x /= 10;
        ++res;
    }
    return res;
}

bool isp10(LL x) {
    while (x > 1) {
        if (x % 10) {
            return false;
        }
        x /= 10;
    }
    return true;
}

LL alg2(LL n) {
    if (n < 10) {
        return n;
    }
    int p = p10(n);
    int c = 0;
    LL res = -1;
    for (int i = 0; i < p; ++i) {
        res += c;
        if (i % 2 == 1) {
            c = 10 * c + 9;
        }
        res += c;
        ++res;
    }
    LL a = n;
    LL cp = 1;
    for (int i = 0; i < (p + 1) / 2; ++i) {
        a /= 10;
        cp *= 10;
    }
    if (!isp10(n) && n == a * cp) {
        --n;
        a = n;
        cp = 1;
        for (int i = 0; i < (p + 1) / 2; ++i) {
            a /= 10;
            cp *= 10;
        }
        ++res;
    }
    res += n - a * cp + revn(a);
    if (isp10(a)) {
        --res;
    }
    return res;
}

int main() {
    int d;
    cin >> d;
    FOR (i, 1, d + 1) {
        LL n;
        cin >> n;
        cout << "Case #" << i << ": " << alg2(n) << endl;
    }
}
