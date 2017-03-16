#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
typedef long long LL;
#define MAXN 100

int a[1010];


int main()
{
    int T;
    
    freopen("/Users/thedream/Desktop/cpp/cpp/input","r",stdin);
    freopen("/Users/thedream/Desktop/cpp/cpp/output","w",stdout);
    
    scanf("%d",&T);
    
    for (int t=1;t<=T;t++) {
        int N;
        cin >> N;
        
        vector<int> friends[1010];
        for(int i=1;i<=N;i++){
            cin >> a[i];
            friends[a[i]].push_back(i);
        }
        int ans = 0;
        
//        NNN= N;
//        cck = false;
//        memset(ck,0,sizeof(ck));
//        int ans2=0;
//        for(int k=N;k>=2;k--){
//            NN= k;
//            dfs(0);
//            if(cck){
//                ans2 = k;
//                break;
//            }
//        }
        
        // 2-cycle
        int visit2[1010]={0,};
        int ansof2 = 0;
        int xx=0;
        for(int i=1;i<=N;i++){
            if(a[a[i]] == i && visit2[i] == 0){
                visit2[a[i]] = 1;
                visit2[i] = 1;
                
                int left = i;
                int right = a[i];
                
                int dp[1010] = {0,};
                dp[left] = 1;
                dp[right] = 1;
                queue<int> lq,rq;
                int lmax=1,rmax=1;
                
                lq.push(left);
                while(!lq.empty()){
                    int now = lq.front();
                    lq.pop();
                    for(int i=0;i<friends[now].size();i++){
                        if(dp[friends[now][i]] == 0){
                            dp[friends[now][i]] = dp[now] + 1;
                            lmax = max(lmax,dp[friends[now][i]]);
                            lq.push(friends[now][i]);
                        }
                    }
                }
                
                rq.push(right);
                while(!rq.empty()){
                    int now = rq.front();
                    rq.pop();
                    for(int i=0;i<friends[now].size();i++){
                        if(dp[friends[now][i]] == 0){
                            dp[friends[now][i]] = dp[now] + 1;
                            rmax = max(rmax,dp[friends[now][i]]);
                            rq.push(friends[now][i]);
                        }
                    }
                }
                xx += lmax+rmax;
            }
        }
        ans = xx;
        
        // cycle
        for(int i=1;i<=N;i++){
            int visit[1010] = {0,};
            visit[i] = 1;
            int now = i;
            int cnt = 1;
            while(1){
                now = a[now];
                if(visit[now]) break;
                cnt++;
                visit[now] = 1;
            }
            if(now == i){
                ans = max(ans,cnt);
            }
        }
        
        printf("Case #%d: %d\n",t,ans);
    }
    
    return 0;
}