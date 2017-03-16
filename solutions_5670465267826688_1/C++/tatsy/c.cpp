#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <list>
#include <stack>
#include <tuple>
#include <utility>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <climits>                                                                                                              
#include <typeinfo>
using namespace std;

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<lint,lint> pll;

#define REP(i,n) for(int i=0; i<n; i++)
#define REPA(i,s,e) for(int i=s; i<=e; i++)
#define REPD(i,s,e) for(int i=s; i>=e; i--)
#define SIZ(a) (Integer)(a).size()
#define ALL(a) (a).begin(), (a).end()

#define PRT(a) cerr << #a << " = " << (a) << endl
#define PRT2(a, b) cerr << #a << " = " << (a) << ", " << #b << " = " << (b) << endl
#define PRT3(a, b, c) cerr << #a << " = " << (a) << ", " << #b << " = " << (b) << ", " << #c << " = " << (c) <<  endl
template <class Ty> void print_all(Ty b, Ty e) {
	cout << "[ ";
	for(Ty p=b; p!=e; ++p) {
		cout << (*p) << ", ";
	}
	cout << " ]" << endl;
}

// -----------------------------------------------------------------------------

lint L, X;
string S;

struct Q {
    int x, i, j, k;
    Q() :
        x(0), i(0), j(0), k(0)
    {
    }

    Q(int x_, int i_, int j_, int k_) :
        x(x_), i(i_), j(j_), k(k_) 
    {
    }

    Q(const Q& q) :
        x(q.x), i(q.i), j(q.j), k(q.k)
    {
    }

    Q& operator=(const Q& q) {
        this->x = q.x;
        this->i = q.i;
        this->j = q.j;
        this->k = q.k;
        return *this;
    }

    bool operator==(const Q& q) {
        return (x == q.x && i == q.i && j == q.j && k == q.k);
    }

    void print() {
        printf("(%d, %d, %d, %d)\n", x, i, j, k);
    }
};

Q operator*(const Q& q1, const Q& q2) {
    Q ret;
    ret.x = q1.x * q2.x - q1.i * q2.i - q1.j * q2.j - q1.k * q2.k;
    ret.i = q1.x * q2.i + q1.i * q2.x + q1.j * q2.k - q1.k * q2.j;
    ret.j = q1.x * q2.j - q1.i * q2.k + q1.j * q2.x + q1.k * q2.i;
    ret.k = q1.x * q2.k + q1.i * q2.j - q1.j * q2.i + q1.k * q2.x;
    return ret;
}

Q fromC(char c) {
    if (c == 'i') {
        return Q(0, 1, 0, 0);
    }
    if (c == 'j') {
        return Q(0, 0, 1, 0);
    }
    if (c == 'k') {
        return Q(0, 0, 0, 1);
    }
    return Q();
}

Q prod[10011];

bool solve() {
    int len = S.size();

    int x1 = (int)min(X, 4ll);
    string s1 = "";
    for (int i = 0; i < x1; i++) {
        s1 += S;
    }
    X -= x1;

    const int l1 = s1.size();

    prod[len] = Q(1, 0, 0, 0);
    for (int i = len - 1; i >= 0; i--) {
        prod[i] = fromC(S[i]) * prod[i + 1];
    }

    Q qi(0, 1, 0, 0);
    Q qj(0, 0, 1, 0);
    Q qk(0, 0, 0, 1);

    Q q1(1, 0, 0, 0);
    for (int i = 0; i < l1; i++) {
        q1 = q1 * fromC(s1[i]);
        if (q1 == qi) {
            string s2 = s1.substr(i + 1);
            int x2 = x1;
            lint xr = X;
            while (s2.size() < 4 * len && xr > 0) {
                s2 += S;
                x2++;
                xr--;
            }
            int l2 = s2.size();

            Q q2(1, 0, 0, 0);
            for (int j = 0; j < l2; j++) {
                q2 = q2 * fromC(s2[j]);
                if (q2 == qj) {
                    int k = i + j + 2;
                    Q q3(1, 0, 0, 0);
                    if (k % len != 0) q3 = q3 *  prod[k % len];
                    int rept = x2 - (k + len - 1) / len;
                    for (int k = 0; k < rept; k++) {
                        q3 = q3 * prod[0];
                    }

                    for (int k = 0; k < (int)(xr % 4ll); k++) {
                        q3 = q3 * prod[0];
                    }

                    if (q3 == qk) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void coding() {
    int T;
    cin >> T;
    REPA(t,1,T) {
        cin >> L >> X >> S;
        printf("Case #%d: %s\n", t, solve() ? "YES" : "NO");
    } 
}

#define _LOCAL_TEST 2

int main() {
#if _LOCAL_TEST == 0
	clock_t startTime = clock();
	freopen("c.in", "r", stdin);
#elif _LOCAL_TEST == 1
	freopen("../input/C-small-attempt1.in", "r", stdin);
    freopen("../input/C-small.out", "w", stdout);
#elif _LOCAL_TEST == 2
	freopen("../input/C-large.in", "r", stdin);
    freopen("../input/C-large.out", "w", stdout);
#endif

	coding();

#if _LOCAL_TEST == 0
	clock_t elapsedTime = clock() - startTime;
	cerr << endl;
	cerr << (elapsedTime / 1000.0) << " sec elapsed." << endl;
	cerr << "This is local test" << endl;
	cerr << "Do not forget to comment out _LOCAL_TEST" << endl << endl;
#endif

}
