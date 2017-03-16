#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define debug(args...) fprintf(stderr,args);

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppp;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 1010;

int l[MAXN][2];

int main() {
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
        int n;
        scanf("%d",&n);
        set< ppp,greater<ppp> > pq;
        for(int a=0;a<n;++a) {
            scanf("%d%d",&l[a][0],&l[a][1]);
            if(l[a][0]==0) pq.insert(ppp(pii(1,l[a][1]),pii(0,a)));
            if(l[a][1]==0) pq.insert(ppp(pii(2,l[a][1]),pii(1,a)));
        }
        int ans = 0;
        int now = 0;
        bool pos = 1;
        while(!pq.empty()) {
            int gain = pq.begin()->first.first;
            pii p = pq.begin()->second;
            pq.erase(pq.begin());
            if(l[p.second][p.first]==-1) continue;
            //printf("gets (%d,%d), has %d stars\n",p.second,p.first,now);
            now += gain;
            ++ans;
            if(p.first == 0) {
                l[p.second][0] = -1;
            }
            else {
                l[p.second][1] = l[p.second][0] = -1;
            }
            for(int a=0;a<n;++a) {
                if(l[a][1] != -1 && l[a][1] <= now) {
                    if(l[a][0] == -1) pq.insert(ppp(pii(1,INF),pii(1,a)));
                    else pq.insert(ppp(pii(2,l[a][1]),pii(1,a)));
                }
                else if(l[a][0] != -1 && l[a][0] <= now) {
                    pq.insert(ppp(pii(1,l[a][1]),pii(0,a)));
                }
            }            
        }
        for(int a=0;a<n;++a) {
            if(l[a][1] != -1) {
                pos = 0;
            }
        }
        printf("Case #%d: ",t);
        if(pos==0) printf("Too Bad\n");
        else printf("%d\n",ans);
    }
    return 0;
}
