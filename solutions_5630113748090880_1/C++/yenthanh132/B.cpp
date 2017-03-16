#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

map<int,int> cnt;
int n,T;

int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        printf("Case #%d:",tt);
        scanf("%d",&n); cnt.clear();
        for(int i=1; i<n*2; ++i){
            for(int j=1; j<=n; ++j){
                int v;
                scanf("%d",&v);
                ++cnt[v];
            }
        }
        vector<int> res;
        for(map<int,int>::iterator it=cnt.begin(); it!=cnt.end(); ++it){
            if(it->second & 1) res.pb(it->first);
        }
        sort(res.begin(), res.end());
        for(int i=0; i<sz(res); ++i) printf(" %d",res[i]);
        puts("");
    }
}

