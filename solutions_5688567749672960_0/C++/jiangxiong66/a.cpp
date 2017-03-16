#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<iostream>
#include<set>
#include<cstring>

using namespace std;

const int N = 1001000;

int dp[N];
bool vis[N];

int rev(int x) {
    char str[10];
    sprintf(str,"%d",x);
    int s=0;
    int e=strlen(str)-1;
    while(s<e) {
        char temp = str[s];
        str[s]=str[e];
        str[e]=temp;
        s++,e--;
    }
    int ans;
    sscanf(str,"%d",&ans);
    return ans;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a.out","w",stdout);

    fill(dp,dp+N,0);
    dp[1]=1;
    queue<int> q;
    while(!q.empty()) q.pop();
    q.push(1);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        int nx=x+1;
        if(nx<N && dp[nx]==0) {
            dp[nx]=dp[x]+1;
            q.push(nx);
        }
        nx=rev(x);
        if(nx<N && dp[nx]==0) {
            dp[nx]=dp[x]+1;
            q.push(nx);
        }
    }

    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++) {
        int k;
        scanf("%d",&k);
        printf("Case #%d: %d\n",cas,dp[k]);
    }
    return 0;
}
