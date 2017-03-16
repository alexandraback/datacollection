#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<lint,lint> pll;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 1010;

double naomi[MAXN], ken[MAXN];

int main() {
    int t=1,T;
    for(scanf("%d",&T);t<=T;++t) {
        int n;
        scanf("%d",&n);
        for(int a=0;a<n;++a) scanf("%lf",&naomi[a]);
        set<double> cj;
        for(int a=0;a<n;++a) {
            scanf("%lf",&ken[a]);
            cj.insert(ken[a]);
        }
        int ans2 = 0;
        sort(naomi,naomi+n,greater<double>());
        for(int a=0;a<n;++a) {
            if(cj.upper_bound(naomi[a]) == cj.end()) ans2++;
            else cj.erase(cj.upper_bound(naomi[a]));
        }
        reverse(naomi,naomi+n);
        sort(ken,ken+n);
        int ans1 = 0;
        int l=0,r=n-1;
        for(int a=0;a<n;++a) {
            if(naomi[a] < ken[r]) {
                if(naomi[a] > ken[l]) {
                    ans1++;
                    l++;
                }
                else r--;
            }
            else {
                ans1++;
                r--;
            }                
        }                
        printf("Case #%d: %d %d\n",t,ans1,ans2);
    }        
    return 0;
}
