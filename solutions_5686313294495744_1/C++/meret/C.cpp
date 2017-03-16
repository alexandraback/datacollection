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

vector<int> e[1005];
int matched[2005];
bool visited[1005];
int n1, n2;

bool dfs(int x) {
    visited[x] = true;
    FORE (it, e[x]) {
        int c = *it + n1;
        if (matched[c] == -1) {
            matched[c] = x;
            matched[x] = c;
            return true;
        } else if (!visited[matched[c]]) {
            if (dfs(matched[c])) {
                matched[c] = x;
                matched[x] = c;
                return true;
            }
        }
    }
    return false;
}

int improve() {
    CLR(visited, 0);
    int added = 0;
    REP (i, n1) {
        if (!visited[i] && matched[i] == -1) {
            if (dfs(i)) {
                ++added;
            }
        }
    }
    return added;
}

int turbo() {
    REP (i, n1 + n2) {
        matched[i] = -1;
    }

    int result = 0;
    while (true) {
        int a = improve();
        if (a == 0) {
            break;
        }
        result += a;
    }
    return result;
}

int alg() {
    int m;
    cin >> m;
    map<string, int> m1;
    map<string, int> m2;
    n1 = n2 = 0;
    REP (i, m) {
        string s1, s2;
        cin >> s1 >> s2;
        if (m1.find(s1) == m1.end()) {
            m1[s1] = n1++;
        }
        if (m2.find(s2) == m2.end()) {
            m2[s2] = n2++;
        }
        e[m1[s1]].PB(m2[s2]);
    }
    int result = m - (n1 + n2 - turbo());
    if (result < 0) {
        cerr << m << " " << n1 << " " << n2 << " " << turbo() << endl;
        exit(0);
    }
    REP (i, n1) {
        e[i].clear();
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
