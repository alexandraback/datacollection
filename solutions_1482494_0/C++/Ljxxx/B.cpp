#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t;
    scanf("%d", &t);
    for(int cas = 1;cas <= t;cas ++) {
        int n;
        scanf("%d", &n);
        
        vector<pair<int,int> > vp;
        
        for(int i = 0;i < n;i ++) {
            int a, b;
            scanf("%d%d", &a, &b);
            vp.push_back(make_pair(b,a));
        }
        
        sort(vp.begin(), vp.end());
        
        vector<pair<int,int> > small;
        for(int i = 0;i < (int)vp.size();i ++) small.push_back(make_pair(vp[i].second, i));
        
        int chosen[1000];
        memset(chosen, 0, sizeof(chosen));
        
        int ok = 1, res = 0, rate = 0;
        
        for(int i = 0;i < (int)vp.size();i ++) {
            while(rate < vp[i].first&&ok) {
                int j = (int)vp.size()-1;
                while(j >= 0) {
                    if(!chosen[small[j].second]&&small[j].first <= rate) {
                        ++ rate;
                        ++ res;
                        chosen[small[j].second] = 1;
                        
                        break;
                    }
                    else -- j;
                }
                if(j < 0) ok = 0;
            }
            
            if(rate >= vp[i].first) {
                ++ res;
                if(chosen[i]) rate += 1;
                else {
                    rate += 2;
                    chosen[i] = 1;
                }
            }
        }
        
        if(ok) printf("Case #%d: %d\n", cas, res);
        else printf("Case #%d: Too Bad\n", cas);
    }
    return 0;
}
