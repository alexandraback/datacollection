#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>
#include<cmath>
using namespace std;

#define LL long long int 
#define PII pair<int,int> 
#define PB push_back
#define MP make_pair
#define INF 1000000000
vector<int> dp[(1<<20)];
int n;
int curkeys[100],req[1000];
vector<vector<int>  > avail;
int calc[(1<<20)];
vector<int> dfs(int bmask){
    if(calc[bmask]){
        return dp[bmask];
    }
    vector<int> ret; 
    if(bmask == 0){
        ret.PB(1000);
        return ret;
    }
    for(int i=0;i<n;i++){
        if((bmask & (1<<i)) == 0)continue;
        if(curkeys[req[i]] > 0 ){
            curkeys[req[i]]--;
            for(int j=0;j<avail[i].size();j++)
                curkeys[avail[i][j]]++;
            ret = dfs((bmask^(1<<i)));
            for(int j=0;j<avail[i].size();j++)
                curkeys[avail[i][j]]--;
            curkeys[req[i]]++;
            if(ret.size() > 0){
                ret.PB(i);
                return dp[bmask]  = ret;
            }
        }
    }
    calc[bmask] =1 ;
    return dp[bmask] = ret;
}
int main(){
    int t,i,k,j,num,x;
    scanf("%d",&t);
    int ct = 0;
    while(t--){
        memset(calc,0,sizeof(calc));
        printf("Case #%d: ",++ct);
        avail.clear();
        avail.resize(1000);
        memset(curkeys,0,sizeof(curkeys));
        for(i=0;i<(1<<20);i++){
            dp[i].clear();
        }
        scanf("%d %d",&k,&n);

        for(i=0;i<k;i++){
            scanf("%d",&x);
            curkeys[x-1] ++;
        }
 
        for(i=0;i<n;i++){
            scanf("%d %d",&req[i],&num);
            req[i]--;
            while(num--){
                scanf("%d",&x);
                avail[i].PB(x-1);
            }
        }
        vector<int> fin  = dfs((1<<n)-1);
        if(fin.size() == 0){
            printf("IMPOSSIBLE\n");
            continue;
        }
        for(i=fin.size()-1;i>0;i--)
            cout<<fin[i] +1<<" ";
        cout<<endl;
    }
    return 0;
}

