#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int N, M;
int A[200];
int B[200];
long long a[200];
long long b[200];
long long memo[110][110];

long long calc(int na, int nb, bool flg)
{
    long long ret, tmp;

    // if (flg && (memo[na][nb] != -1))
    //     return memo[na][nb];

    if ((na == N) || (nb == M))
        return 0;

    if (A[na] == B[nb]) {
        if (a[na] > b[nb]) {
            tmp = b[nb];
            a[na] -= tmp;
            ret = calc(na, nb+1, false) + tmp;
            a[na] += tmp;
        } else {
            tmp = a[na];
            b[nb] -= tmp;
            ret = calc(na+1, nb, false) + tmp;
            b[nb] += tmp;
        }
    } else {
        ret = 0;
        ret = max(ret, calc(na, nb+1, false));
        ret = max(ret, calc(na+1, nb, false));
        // if (flg) {
        //     memo[na][nb] = ret;
        //     // cout << "memo[" << na << "][" << nb << "]=" << memo[na][nb] << endl;
        // }
    }


    return ret;
}

int
main(void)
{
    int T;
    int i, j, k;
    long long ret;

    cin >> T;

    for(i=1;i<=T;i++) {
        cin >> N >> M;
        for(j=0;j<N;j++) {
            cin >> a[j] >> A[j];
        }
        for(j=0;j<M;j++) {
            cin >> b[j] >> B[j];
        }
        for(j=0;j<110;j++) {
            for(k=0;k<110;k++) {
                memo[j][k] = -1;
            }
        }
        ret = calc(0, 0, true);
        printf("Case #%d: ", i);
        cout << ret << endl;
    }
    
    return 0;
}
