#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <cassert>

using namespace std;

const int P = 1000;
typedef unsigned long long ull_t;

const int N=16;
const int J=50;
vector<int> ps(P);
int d[P][9][N];

bool visit(const vector<int>& x, vector<int>& divs) {
    // for each base go through all the primes
    for (int b=2; b<=10; ++b) {
        int j = b-2;
        int i;
        for (i=0; i<P; ++i) {
            int s = 0;
            const int pp = ps[i];
            for (int k=0; k<N; ++k) {
                s += x[k]*d[i][j][k];
                s %= pp;
            }
            if (s) continue;
            divs[j] = pp;
            break;
        }
        if (i==P) return false;
    }
    return true;
}

int main() {
    cout << "Case #1:\n";
    // find first P primes
    {
        const int z = 2*P*log(P);
        const int srz = sqrt(z)+1;
        vector<short> s(z, 1);
        for (int i=2; i<srz; ++i) {
            if (!s[i]) continue;
            int j=2*i;
            while (j<z) {
                s[j] = 0;
                j += i;
            }
        }
        int cp = 0;
        for (int i=2; i<z && cp<P; ++i) {
            if (!s[i]) continue;
            ps[cp++] = i;
        }
        if (cp<P) {
            cerr << "Error: cp=" << cp << endl;
            return 1;
        }
    }
    for (int i=0; i<P; ++i) {
        int p = ps[i];
        for (int j=2; j<=10; ++j) {
            d[i][j-2][0] = 1;
            for (int n=1; n<N; ++n) {
                d[i][j-2][n] = (j*d[i][j-2][n-1])%p;
            }
        }
    }

#if 0
    for (int i=0; i<P; ++i) {
        cerr << ps[i] << "\n";
        for (int j=0; j<9; ++j) {
            for (int n=0; n<N; ++n) {
                cerr << " " << d[i][j][n];
            }
            cerr << "\n";
        }
        cerr << endl;
    }
#endif

    vector<int> x(N);
    x[0] = x[N-1] = 1;
    int cnt = 0;
    for (int j=1;;) {
        while (x[j] && j<N-1) ++j;
        if (j==N-1) break;
        x[j] = 1;
        for (int i=1; i<j; ++i) x[i] = 0;
        j=1;
        vector<int> divs(9);
        if (!visit(x, divs)) continue;
        vector<int> r(N);
        for (int i=0; i<N; ++i) r[i] = x[N-1-i];
        copy(r.begin(), r.end(), ostream_iterator<int>(cout, ""));
        cout << " ";
        copy(divs.begin(), divs.end(), ostream_iterator<int>(cout, " "));
        cout << "\n";
        if (++cnt == J) break;
    }
}
