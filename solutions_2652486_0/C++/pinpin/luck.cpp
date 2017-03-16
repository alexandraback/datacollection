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

int dp[12][6];
int cnt[6][6][6][126];

int
main(void)
{
    int T;
    int i, j, ret;
    int a, b, c, e, f;
    int R, N, M, K;
    int v[10];
    int dat[126];
    int msk, odd, flg;
    int msk_3, msk_5, msk_2;

    memset(cnt, 0, sizeof(cnt));
    for(a=1;a<=5;a++) {
        for(b=a;b<=5;b++) {
            for(c=b;c<=5;c++) {
                cnt[a][b][c][1] = 1;
                cnt[a][b][c][a] = 1;
                cnt[a][b][c][b] = 1;
                cnt[a][b][c][c] = 1;
                cnt[a][b][c][a*b] = 1;
                cnt[a][b][c][b*c] = 1;
                cnt[a][b][c][c*a] = 1;
                cnt[a][b][c][a*b*c] = 1;
            }
        }
    }

    cin >> T;
    cout << "Case #1:" << endl;
    cin >> R >> N >> M >> K;
    for(i=1;i<=R;i++) {
        msk_3 = msk_5 = msk_2 = 0;
        for(j=0;j<K;j++) {
            cin >> v[j];
            if ((v[j] % 2) == 0) msk_2 = 1;
            if ((v[j] % 3) == 0) msk_3 = 1;
            if ((v[j] % 5) == 0) msk_5 = 1;
        }
        int ok_cnt = 0;
        int ok;
        sort(&v[0], &v[K]);
        for(a=1;a<=5;a++) {
            for(b=a;b<=5;b++) {
                for(c=b;c<=5;c++) {
                    bool flg = true;
                    for(j=0;j<K;j++) {
                        if (!cnt[a][b][c][v[j]]) {
                            flg = false;
                        }
                        if (!flg)
                            break;
                    }
                    if (flg) {
                        ok = 100*a+10*b+c;
                        ok_cnt++;
                        // cout << "ok_cnt=" << ok_cnt << "," << ok << endl;
                    }
                }
            }
        }
        if (ok_cnt == 1) {
            cout << ok << endl;
            continue;
        } else {
            if (msk_3 && msk_5 && msk_2) {
                cout << "235" << endl;
            } else if (msk_3 && msk_5 && msk_2) {
                cout << "235" << endl;
            } else {
                cout << "235" << endl;
            }
        }
    }
    
    return 0;
}
