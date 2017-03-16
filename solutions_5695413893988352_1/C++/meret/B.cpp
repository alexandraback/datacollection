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

string r1, r2;
LL ir1, ir2;
bool min_first;

void check(string c1, string c2) {
    if (!min_first) {
        swap(c1, c2);
    }
    stringstream ss1(c1);
    stringstream ss2(c2);
    LL ic1, ic2;
    ss1 >> ic1;
    ss2 >> ic2;
    if (r1.empty()) {
        r1 = c1;
        r2 = c2;
        ir1 = ic1;
        ir2 = ic2;
        return;
    }
    if (abs(ic1 - ic2) > abs(ir1 - ir2)) {
        return;
    }
    if (abs(ic1 - ic2) == abs(ir1 - ir2)) {
        if (ic1 > ir1) {
            return;
        }
        if (ic1 == ir1 && ic2 > ir2) {
            return;
        }
    }
    ir1 = ic1;
    ir2 = ic2;
    r1 = c1;
    r2 = c2;
}

// a >= b
string a, b;
void go(int i, bool greater = false) {
    if (i == a.size()) {
        check(a, b);
        return;
    }
    if (a[i] == '?' && b[i] == '?') {
        a[i] = b[i] = '0';
        go(i + 1, greater);
        if (!greater) {
            a[i] = '1';
            b[i] = '0';
            go(i + 1, true);
        } else {
            a[i] = '0';
            b[i] = '9';
            go(i + 1, true);
        }
        a[i] = b[i] = '?';
    } else if (a[i] == '?') {
        a[i] = b[i];
        go(i + 1, greater);
        if (!greater) {
            if ('9' > b[i]) {
                a[i] = b[i] + 1;
                go(i + 1, true);
            }
        } else {
            a[i] = '0';
            go(i + 1, true);
        }
        a[i] = '?';
    } else if (b[i] == '?') {
        b[i] = a[i];
        go(i + 1, greater);
        if (!greater) {
            if ('0' < a[i]) {
                b[i] = a[i] - 1;
                go(i + 1, true);
            }
        } else {
            b[i] = '9';
            go(i + 1, true);
        }
        b[i] = '?';
    } else {
        if (!greater && a[i] < b[i]) {
            return;
        }
        go(i + 1, greater || (a[i] > b[i]));
    }
}

void alg() {
    string s1, s2;
    cin >> s1 >> s2;
    a = s1;
    b = s2;
    min_first = true;
    r1 = "";
    go(0);
    a = s2;
    b = s1;
    min_first = false;
    go(0);
    cout << r1 << " " << r2 << endl;
}

int main() {
    int d;
    cin >> d;
    REP (i,d) {
        cout << "Case #" << i+1 << ": ";
        alg();
    }
}
