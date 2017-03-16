#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

#define ROUNDS 27

bool isGuaranteed(vector<int> S, int X, int co, double Y) {
    double me = S[co] + X * Y;
    double pool = 1 - Y;
    for (int i = 0; i < (int)S.size(); i++) {
        if (i == co) continue;
        if (S[i] < me) {
            double theirY = (me - S[i]) / X;
            if (theirY <= pool) pool -= theirY;
            else return true;
        }
    }
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int caseno = 1; caseno <= T; caseno++) {
        int N;
        scanf("%d", &N);
        int X = 0;
        vector<int> S(N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &S[i]);
            X += S[i];
        }
        printf("Case #%d:", caseno);
        for (int co = 0; co < N; co++) {
            double begin = 0, end = 1;
            for (int r = 0; r < ROUNDS; r++) {
                double mid = (begin + end) / 2;
                if (isGuaranteed(S, X, co, mid))
                    end = mid;
                else
                    begin = mid;
            }
            printf(" %.8lf", (begin+end)/2*100);
        }
        printf("\n");
    }
    return 0;
}