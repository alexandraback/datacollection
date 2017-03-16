#include <cstdio>
#include <algorithm>

using namespace std;

struct aWeight {
    int w;
    bool t;
    aWeight (int __w=0, bool _t=0) {
        w = __w; t = _t;
    }
    bool operator < (const aWeight &_a) const {
        return w < _a.w;
    }
};

int _T, N, w;
double _w;

aWeight allM[2005];
bool dead[2005];

int nKen, ans, nMe;

void reset() {
    for (int i = 0; i < 2005; i++) {
        dead[i] = false;
    }
    nKen = ans = nMe = 0;
    return;
}


int main() {
    freopen ("q4.in", "r", stdin);
    freopen ("q4.out", "w", stdout);
    scanf ("%d", &_T);
    for (int _z = 1; _z <= _T; _z++) {
        reset();
        printf ("Case #%d: ", _z);
        scanf ("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf ("%lf", &_w);
            w = _w*100000;
            allM[i] = aWeight (w, 0);
        }
        for (int i = 0; i < N; i++) {
            scanf ("%lf", &_w);
            w = _w*100000;
            allM[N+i] = aWeight (w, 1);
        }
        sort (allM, allM+2*N);
        //Deceitful war:
        for (int i = 0; i < 2*N; i++) {
            if (dead[i]) continue;
            if (allM[i].t == 0) {
                if (nKen != 0) {
                    nKen--;
                    ans++;
                } else {
                    for (int p = 2*N-1; p >= 0; p--) {
                        if (allM[p].t == 1 && !dead[p]) {
                            dead[p] = true;
                            break;
                        }
                    }
                }
            
            } else {
                nKen++;
            }
        }
        printf ("%d ", ans);
        ans = 0;
        //Normal war:
        for (int i = 0; i < 2*N; i++) {
            if (allM[i].t == 0) {
                nMe++;
            } else {
                nMe = max (0, nMe-1);
            }
        }
        printf ("%d\n", nMe);
    }
    return 0;
}
