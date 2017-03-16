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

int circle[15];
int ck[15];
int NN,cck,NNN;
int a[1010];
void dfs(int x){
    if(x==NN){//7 9 3 10 4 1
        if(NN==6 && circle[0] == 1 && circle[1] == 7 && circle[2] == 9 &&
           circle[3] == 3 && circle[4] == 10 && circle[5] == 4){
            NN=NN;
        }
        for(int i=0;i<NN;i++){
            if(circle[(i+1)%NN] == a[circle[i]] || circle[(i-1+NN)%NN] == a[circle[i]]){
                continue;
            }
            return;
        }
        cck= true;
        return;
    }
    
    for(int i=1;i<=NNN;i++){
        if(!ck[i]){
            ck[i] = 1;
            circle[x] = i;
            dfs(x+1);
            if(cck) return;
            ck[i]= 0;
        }
    }
}

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
        
        NNN= N;
        cck = false;
        memset(ck,0,sizeof(ck));
        int ans2=0;
        for(int k=N;k>=2;k--){
            NN= k;
            dfs(0);
            if(cck){
                ans2 = k;
                break;
            }
        }
        
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
        
        //non cycle
        for(int root=1;root<=N;root++){
            if(friends[root].size() < 2) continue;
            int sz = friends[root].size() ;
            for(int li=0;li<sz;li++){
                for(int ri = li + 1; ri < sz;ri ++){
                    int left = friends[root][li];
                    int right = friends[root][ri];
                    
                    if(a[root] != left && a[root] != right){
                        continue;
                    }
                    int dp[1010] = {0,};
                    dp[root] = 1;
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
                    
                    ans = max(ans,lmax+rmax+1);
                }
            }
        }
        
        printf("Case #%d: %d\n",t,ans2);
    }
    
    return 0;
}