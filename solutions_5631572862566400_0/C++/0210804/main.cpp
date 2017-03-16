#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define N 1005

int love[N];
int indegree[N];
int dp[N];

void solve(){

    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        indegree[i] = 0;
        dp[i]=0;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&love[i]);
        indegree[love[i]]++;
    }
    queue<int> que;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            que.push(i);
        }
    }
    while(!que.empty()){
        int discuss = que.front();
        que.pop();
        dp[love[discuss]] = max(dp[love[discuss]],dp[discuss]+1);
        if(--indegree[love[discuss]]==0) que.push(love[discuss]);
    }
    int ans = 0;
    int single = 0;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0) continue;
        if(i==love[love[i]]){
            single += dp[i]+dp[love[i]]+2;
            indegree[i]=indegree[love[i]]=0;
            continue;
        }
        dp[i] = 0;
        indegree[i] = 0;
        int discuss = love[i];
        int length = 1;
        while(discuss!=i){
            dp[discuss] = 0;
            indegree[discuss] = 0;
            discuss = love[discuss];
            length++;
        }
        ans = max(ans,length);
    }
    printf("%d\n",max(ans,single));
}

int main()
{
    freopen("C-small-attempt3.in","r",stdin);
    freopen("c_output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("Case #%d: ",i+1);
        solve();
    }
    return 0;
}

/*
int makeCircle(int length,int n){
    if(length>n){
        return 0;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(incycle[i]) continue;
        endof[i] = love[endof[i]];
        if(endof[i]==i){
            incycle[i] = 1;
            ans = length;
            if(ans==3) printf("%d is the head\n",i);
        }
    }
    ans = max(ans,makeCircle(length+1,n));
    return ans;
}
*/
/*
void solve(){

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        incycle[i] = 0;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&love[i]);
        endof[i] = love[i];
    }
    int single = 0;
    for(int i=1;i<=n;i++){
        if(endof[endof[i]]==i){
            incycle[i] = 1;
            single++;
        }
    }
    int ans = makeCircle(2,n);
    printf("%d\n",max(single*2,ans));
}
*/
