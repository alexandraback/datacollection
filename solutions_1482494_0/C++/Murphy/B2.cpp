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

int A[1024], B[1024], N;
map<pii, int> M;

int gao(int a, int b) {
    if (a == 0 && b == 0) return 0;
    pii p = make_pair(a, b);
    if (M.find(p) != M.end()) {
        return M[p];
    }
    int res = 3 * N, ct = __builtin_popcount(a) + __builtin_popcount(b) * 2;
    REP(i, N) {
        if (b & (1<<i)) {
            if (ct - 2 >= B[i]) {
                res = min(res, gao(a, b - (1<<i)) + 1);
            }
            if (ct - 1 >= B[i]) {
                res = min(res, gao(a + (1<<i), b - (1<<i)) + 1);
            }
        }
        if (a & (1<<i)) {
            if (ct - 1 >= A[i]) {
                res = min(res, gao(a - (1<<i), b) + 1);
            }
        }
    }
    M[p] = res;
    return res;
}

int main(){
    int caseNumber;
    scanf("%d", &caseNumber);
    //cin>>caseNumber;
    REP(caseN, caseNumber) {
        scanf("%d", &N);
        REP(i, N) {
            scanf("%d%d", A + i, B + i);
        }
        M.clear();
        int tmp = 1<<N;
        int res = gao(0, tmp - 1);
        
        if (res >= 3 * N) {
            printf("Case #%d: Too Bad\n", caseN + 1);
        } else{
            printf("Case #%d: %d\n", caseN + 1, res);
        }
    }
    return 0;
}
