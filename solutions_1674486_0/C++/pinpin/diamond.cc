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

int PP[1010][20];
int M[1010];
int mat[1010][1010];
int cnt[1010];
int N;

int calc(int n)
{
    int ret, i;

    if (cnt[n] != -1)
        return cnt[n];
    ret = 0;
    for(i=0;i<M[n];i++) {
        ret += calc(PP[n][i]);
    }
    cnt[n] = ret;

    return ret;
}

int
main(void)
{
    int T;
    int P;
    int i, j, k;

    cin >> T;

    for(i=1;i<=T;i++) {
        cin >> N;
        vector<int> vp;
        for(j=0;j<N;j++) {
            cin >> M[j];
            if (M[j] == 0) {
                vp.push_back(j);
            }
            for(k=0;k<M[j];k++) {
                cin >> PP[j][k];
                PP[j][k]--;
            }
        }
        bool flg = false;
        for(j=0;j<vp.size();j++) {
            for(k=0;k<N;k++) {
                cnt[k] = -1;
            }
            cnt[vp[j]] = 1;
            for(k=0;k<N;k++) {
                cnt[k] = calc(k);
                // cout << "cnt(" << k << ")=" << cnt[k] << endl;
                if (cnt[k] >= 2) {
                    flg = true;
                    break;
                }
            }
            if (flg)
                break;
        }

        printf("Case #%d: %s\n", i, flg ? "Yes" : "No");
    }
    
    return 0;
}
