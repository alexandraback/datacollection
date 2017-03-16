#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

int T, N;
bool taken[1005];
vector<double> V, V1;
multiset<double> S, S1;

int main() {
    freopen("D-large.in", "r", stdin);
    freopen("D-large.out", "w", stdout);
    scanf("%d", &T);
    for ( int tc = 1; tc <= T; tc++ ) {
        memset(taken, 0, sizeof(taken));
        V.clear();
        V1.clear();
        S.clear();
        S1.clear();
        scanf("%d", &N);
        for ( int i = 0; i < N; i++ ) {
            double D;
            scanf("%lf", &D);
            V.push_back(D);
        }
        for ( int i = 0; i < N; i++ ) {
            double D;
            scanf("%lf", &D);
            V1.push_back(D);
        }
        sort(V.begin(), V.end());
        sort(V1.begin(), V1.end());
        int ptr_left = 0, ptr_right = 0;
        for ( ;ptr_right < N; ptr_right++ ) if ( V1[ptr_right] > V[ptr_left] ) ptr_left++;
        for ( int i = 0; i < N; i++ ) S.insert(V[i]);
        for ( int i = 0; i < N; i++ ) S1.insert(V1[i]);
        bool done = false;
        int ans = 0;
        while ( S.size() > 0 ) {
            done = true;
            for ( multiset<double>::iterator it = S.begin(); it != S.end(); it++ ) {
                if ( (*it) > *(--S1.end()) ) {
                    done = false;
                    ans++;
                    S1.erase(--S1.end());
                    S.erase(it);
                    break;
                }
            }
            if ( done ) {
                S.erase(S.begin());
                S1.erase(--S1.end());
            }
        }
        printf("Case #%d: %d %d\n", tc, ans, N - ptr_left);
    }
    //system("PAUSE");
}
