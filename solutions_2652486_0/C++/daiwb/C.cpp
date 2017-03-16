#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <map>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long LL;

int R, N, M, K;
int vv[150];

int kk[10];

void doit() {
    FOR(i1,2,M) {
        FOR(i2,2,M) {
            FOR(i3,2,M) {
                memset(vv, 0, sizeof(vv));
                REP(j1,2) {
                    REP(j2,2) {
                        REP(j3,2) {
                            int tmp = 1;
                            if (j1 == 1) tmp *= i1;
                            if (j2 == 1) tmp *= i2;
                            if (j3 == 1) tmp *= i3;
                            vv[tmp] = 1;
                        }
                    }
                }
                bool flag = true;
                REP(i,K) {
                    if (vv[kk[i]] == 0) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    cout << i1 << i2 << i3 << endl;
                    return;
                }
            }
        }
    }
    int ii1 = rand() % (M - 1);
    cout << ii1 + 2;
    int ii2 = rand() % (M - 1);
    cout << ii2 + 2;
    int ii3 = rand() % (M - 1);
    cout << ii3 + 2 << endl;
    
}

void run() {
    cin >> R >> N >> M >> K;
    
    REP(ii,R) {
        REP(i,K) cin >> kk[i];
        doit();
    }
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ":" << endl;
        run();
    }
    return 0;
}
