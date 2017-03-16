#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<cassert>
#include<iomanip>
using namespace std;

#define LL long long
#define PI pair<int,int>
#define F first
#define S second
#define MP make_pair
#define VI vector<int>
#define VPI vector<PI>
#define PB push_back
#define MAXN 20
#define MAXE 10

int E,R,N;
int V[MAXN];
int dp[MAXE],temp[MAXE];

void doit()
{
    for(int i=0;i<=E;i++) dp[i] = V[N]*i;
    for(int it=N;it>1;it--){
        for(int i=0;i<=E;i++) temp[i] = dp[i];
        for(int i=0;i<=E;i++) dp[i] = -1;
        for(int i=0;i<=E;i++){
            for(int j=0;j<=i;j++){
                dp[i] = max(dp[i],j*V[it-1] + temp[min(E,i-j+R)]);
            }
        }
    }
}

int main()
{
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    int cases;
    scanf("%d", &cases);
    for(int tt=1;tt<=cases;tt++){
        scanf("%d%d%d", &E, &R, &N);
        for(int i=1;i<=N;i++) scanf("%d", &V[i]);
        doit();
        int ans = -1;
        for(int i=0;i<=E;i++) ans = max(ans,dp[i]);
        printf("Case #%d: %d\n", tt, ans);
    }
    return 0;
}
