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

int W, H, D;
int x, y;
int res = 0;



inline int sgn(int x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}
/*vector<pii> pnts;
void add2(int x, int y) {
    if (x == 0 && y == 0)
        return;
    //if (x != y)
    if (x * x + y * y <= 4 * D * D) {
        printf("%d %d %d\n", x, y, D);
        REP(i, pnts.size()) {
            if (pnts[i].first * y == pnts[i].second * x) {
                if (x == 0) {
                    if (sgn(pnts[i].second) == sgn(y)) {
                        return;
                    }
                } else {
                    if (sgn(pnts[i].first) == sgn(x)) {
                        return;
                    }
                }
            }
        }
        puts("A");
        res++;
        pnts.pb(make_pair(x, y));
    }
}
*/
vector<pair<int,pii> > pnts;
void add(int x, int y) {
    if (x == 0 && y == 0)
        return;
    if (x * x + y * y <= 4 * D * D) {
        pnts.pb(make_pair(x * x + y * y, make_pair(x, y)));
    }
}

int main() {
    int T;
    cin>>T;
    REP(Z, T) {
        pnts.clear();
        cin>>W>>H>>D;
        string s;
        REP(i, W) {
            cin>>s;
            REP(j, H) {
                if (s[j] == 'X') {
                    x = i;
                    y = j;
                }
            }
        }
        W -= 2; H -= 2;
        W *= 2; H *= 2;
        x--;y--;
        x *= 2; y *= 2;
        x++; y++;
        int dx1 = 2 * x, dx2 = 2 * (W - x);
        //cout<<W<<H<<x<<y<<endl;
        //printf("XXXXX %d %d\n", dx1, dx2);
        res = 0;
        int x2 = 0;
        REP(p, 2) {
            for (int i = 0; i <= 1000; i++) {
                int y2 = 0;
                int dy1 = 2 * y, dy2 = 2 * (H - y);
                REP(p2, 2) {
                    for (int i2 = 0; i2 <= 1000; i2++) {
                        //if (i + cnt1 != i2 + cnt2)
                        //printf("%d:%d %d:%d ", p, i, p2, i2);
                        add(x2, y2);
                        if (i2 & 1) {
                            y2 += dy1;
                        } else {
                            y2 += dy2;
                        }
                        if(y2 > D * 2 + 2 || y2 < -2 * D - 2) {
                            break;
                        }
                    }
                    swap(dy1, dy2);
                    dy1 *= -1; dy2 *= -1;
                    y2 = 0;
                }
                //printf("X2 %d i %d %d %d\n", x2, i, dx1, dx2);
                if (i & 1) {
                    x2 += dx1;
                } else {
                    x2 += dx2;
                }
                if(x2 > D * 2 + 2 || x2 < -2 * D - 2) {
                    break;
                }
            }
            swap(dx1, dx2);
            dx1 *= -1; dx2 *= -1;
            x2 = 0;
        }
        //res--;
        sort(pnts.begin(), pnts.end());
        REP(k, pnts.size()) {

            int& x = pnts[k].second.first; int& y = pnts[k].second.second;
            for(int i = 0; i < k; i++) {
                if (pnts[i].second.first * y == pnts[i].second.second * x) {
                    if (x == 0) {
                        if (sgn(pnts[i].second.second) == sgn(y)) {
                            goto next;
                        }
                    } else {
                        if (sgn(pnts[i].second.first) == sgn(x)) {
                            goto next;
                        }
                    }
                }
            }
            res++;
            //printf("%d %d %d\n", x, y, D);
            next:;
        }
        
        printf("Case #%d: %d\n", Z + 1, res);
    }
}
