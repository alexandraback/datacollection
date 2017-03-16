#include <cstdio>
#include <iostream>

#define ABS(x) (((x)>=0)?(x):-(x))

using namespace std;

typedef unsigned long long ULL;

#ifdef _DEBUG_
static const bool _debug_ = true;
#else
static const bool _debug_ = false;
#endif

#define derr if (_debug_) cerr

void preprocess() {
}

void doTest(int tt) {
    printf("Case #%d: ", tt);
    int X, Y;
    scanf("%d%d", &X, &Y);

    int xx, yy;
    char *xdirs;
    char *ydirs;
    for (xx=0; xx<ABS(X); ++xx) {
        if (X<0) {
            printf("EW");
        } else {
            printf("WE");
        }
    }
    for (yy=0; yy<ABS(Y); ++yy) {
        if (Y<0) {
            printf("NS");
        } else {
            printf("SN");
        }
    }
    printf("\n");
}

int main() {
    preprocess();
    int T;
    scanf("%d", &T);
    for (int tt=1; tt<=T; ++tt) {
        doTest(tt);
    }
    return 0;
}

