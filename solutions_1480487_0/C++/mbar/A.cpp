#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cassert>

using namespace std;

typedef vector<int> vi;
typedef vector<double> vd;

struct cmp {
    const vd& v;
    cmp(const vd& w) : v(w) {}
    bool operator()(int i, int j) const { return v[i] < v[j]; }
};

int main() {
    int T;
    cin >> T;
    for (int cs=1; cs<=T; ++cs) {
        int N;
        cin >> N;
        vd s(N);
        double X = 0;
        for (int i=0; i<N; ++i) {
            cin >> s[i];
            X += s[i];
        }
        double Xi = 1.0/X;
        vd rs(N, 1);
        for (;;) {
            double sp = 0;
            double ms = -1;
            bool has_zeros = false;
            bool changed = false;
            int nn=0;
            for (int i=0; i<N; ++i) {
                if (rs[i]==0) continue;
                if (ms<s[i]) ms=s[i];
                ++nn;
            }
            for (int i=0; i<N; ++i) {
                if (rs[i]==0) continue;
                sp += ms - s[i];
            }
            sp *= Xi;
            double y = (1.0-sp)/nn;
            for (int i=0; i<N; ++i) {
                if (rs[i]==0) continue;
                double r = y + (ms-s[i])*Xi;
                if (r<0) {
                    r = 0;
                    has_zeros = true;
                }
                changed = true;
                rs[i] = r;
            }
            if (!has_zeros || !changed) break;
        }
        printf("Case #%d: ", cs);
        for (int i=0; i<N; ++i) printf("%.8f ", 100*rs[i]);
        printf("\n");
    }
}
