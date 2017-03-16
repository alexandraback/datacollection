#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
int mark[2000];
int main() {
    int n,T,m,ans, TC=1,i,a,b,now;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        map<int, pair<int, int> > tt;
        set<pair<int, int> > s1;
        vector<pair<int, int> > ss1;
        set<pair<int, int> > s2;
        memset(mark, 0, sizeof(mark));
        for (i=0; i<n; i++) {
            scanf("%d%d", &a, &b);
            tt[i] = mp(a, b);
            ss1.pb(mp(a, i));
            s2.insert(mp(b, i));
        }
        sort(ss1.begin(), ss1.end());
        int ttt=0;
        now = 0; ans = 0;
        while (n) {
            while (s2.size()) {
                pair<int, int> x = (*s2.begin());
                if (x.first > now) break;
                if (mark[x.second] == 1) now++;
                else now += 2;
                //printf("-2 %d %d\n", now, x.second);
                s2.erase(x);
                mark[x.second] = 2;
                n--;
                ans ++;
            }
            while (ttt<ss1.size()) {
                if (ss1[ttt].first > now) break;
                if (mark[ss1[ttt].second] != 2) s1.insert(mp(tt[ss1[ttt].second].second, ss1[ttt].second));
                ttt++;
            }
            int rr=0;
            while (s1.size()) {
                    pair<int, int> x = (*s1.rbegin());
                    s1.erase(x);
                    if (mark[x.second] == 2) continue;
                    now += 1;
                    //printf("-1 %d %d\n", now, x.second);
                    rr=1;
                    mark[x.second] = 1;
                    ans ++;
                    break;
            }
            if (!rr) {
                if (n){
                   ans = -1;
                   break;
                }
            }
        }
        if (ans<0) printf("Case #%d: Too Bad\n",TC++);
        else printf("Case #%d: %d\n", TC++, ans);
    }
}
