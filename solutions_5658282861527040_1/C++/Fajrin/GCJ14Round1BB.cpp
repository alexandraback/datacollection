#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"

using namespace std;

int vis[33][3][3][3],now;
long long dp[33][3][3][3];
bool en[33], em[33], ky[33];

long long solve(int,bool,bool,bool);

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        now = test;
        
        long long n,m,k;
        cin >> n >> m >> k;
        
        for(int i=0;i<=32;i++)
        {
            en[i] = n%2;
            em[i] = m%2;
            ky[i] = k%2;
            n/=2LL;
            m/=2LL;
            k/=2LL;
        }
        
        printf("Case #%d: ",test);
        cout << solve(32,false,false,false) << endl;
    }
    return 0;
}

long long solve(int idx,bool a,bool b,bool c)
{
    if(idx==-1 && a && b && c)
        return 1LL;
    if(idx==-1)
        return 0LL;
    
    if(vis[idx][a][b][c] == now)
        return dp[idx][a][b][c];
    
    vis[idx][a][b][c] = now;
    long long ans = 0LL;
        
    bool nAble = a || en[idx];
    bool mAble = b || em[idx];
    bool kAble = c || ky[idx];
    
    // 0 0
    ans += solve(idx-1, a||en[idx], b||em[idx], c||ky[idx]);
    // 1 0
    if(nAble)
        ans += solve(idx-1, a||!en[idx], b||em[idx], c||ky[idx]);
    // 0 1
    if(mAble)
        ans += solve(idx-1, a||en[idx], b||!em[idx], c||ky[idx]);
    // 1 1
    if(nAble && mAble && kAble)
        ans += solve(idx-1, a||!en[idx], b||!em[idx], c||!ky[idx]);
    
    //printf("%d %d %d %d ",idx,a,b,c);
    //cout << ans << endl;
    
    return dp[idx][a][b][c] = ans;
}
