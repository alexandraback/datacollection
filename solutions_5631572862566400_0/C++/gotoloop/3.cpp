#include <stdio.h>
#include <algorithm>

using namespace std;

int nex[200];
bool flg[200];
int ma[200];
pair<int,int> d[200];

int dfs(int n,int w,int k){
    if(flg[n]){
        ma[n] = max(ma[n],k);
        return 0;
    }
    else if(d[n].first == w){
        return k - d[n].second;
    }
    else{
        d[n] = make_pair(w,k);
        return dfs(nex[n],w,k + 1);
    }
}

int main(){
    int t;
    scanf("%d",&t);
    for(int tw = 1; tw <= t; tw++){
        int n;
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            scanf("%d",nex + i);
            nex[i]--;
        }
        for(int i = 0; i < n; i++){
            flg[i] = (nex[nex[i]] == i);
            ma[i] = 0;
            d[i] = make_pair(-1,-1);
        }
        int maw = 0;
        for(int i = 0; i < n; i++){
            maw = max(maw,dfs(i,i,1));
        }
        int all = 0;
        for(int i = 0; i < n; i++){
            all += ma[i];
        }
        printf("Case #%d: %d\n", tw, max(maw,all));
    }
}
