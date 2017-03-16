#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <fstream>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;

vector<pii> X;
int D[1024];

int main(){
    int caseNumber;
    scanf("%d", &caseNumber);
    //cin>>caseNumber;
    REP(caseN, caseNumber) {
        int N;
        scanf("%d", &N);
        X.clear();
        REP(i, N) {
            int A, B;
            scanf("%d%d", &A, &B);
            X.pb(make_pair(-B, A));
        }
        sort(X.begin(), X.end());
        int res = 0, accu = 0;
        REP(i, N) {
            X[i] = make_pair(X[i].second, -X[i].first);
        }
        memset(D, 0, sizeof D);
        while (1) {
            int fd = 0;
            REP(i, N) {
                if (D[i] != 2) {
                    if (accu >= X[i].second) {
                        accu += D[i] == 1 ? 1: 2;
                        D[i] = 2;
                        res++;
                        fd = 1;
                    }
                }
            }
            if (fd) {
                continue;
            }
            REP(i, N) {
                if (D[i] == 0) {
                    if (accu >= X[i].first) {
                        D[i] = 1;
                        accu ++;
                        res++;
                        fd = 1;
                        break;
                    }
                }
            }
            if (!fd) {
                break;
            }
        }
        if (accu != 2 * N) {
            printf("Case #%d: Too Bad\n", caseN + 1);
        } else{
            printf("Case #%d: %d\n", caseN + 1, res);
        }
    }
    return 0;
}
