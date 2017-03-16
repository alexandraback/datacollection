#include <cstdio>
#include <iostream>

using namespace std;

int B;
long long int M;

int mat[60][60];

long long int dp[60];

long long int cal(int x)
{
    if(dp[x]!=-1) return dp[x];
    long long int ans = 0;
    for(int i=0;i<B;++i)
        if(mat[x][i])
            ans += cal(i);
    return dp[x] = ans;
}

void input(void)
{
    cin >> B >> M;
}

void check(void)
{
    for(int i=0;i<B;++i)
        dp[i] = -1;
    dp[B-1] = 1;
    if(cal(0)!=M)
        puts("NOTSAME");
}

void solve(void)
{
    // cout << B << ' ' << M << endl;
    if(M>1LL<<(B-2)) {
        puts(" IMPOSSIBLE");
        return;
    }
    puts(" POSSIBLE");
    for(int i=0;i<B;++i)
        for(int j=0;j<B;++j)
            mat[i][j] = 0;
    for(int i=B-2;i>=1;--i)
        for(int j=B-1;j>i;--j)
            mat[i][j] = 1;
    if(M==1LL<<(B-2)) {
        for(int i=1;i<B;++i)
            mat[0][i] = 1;
    } else {
        for(int i=0;i<B-1;++i)
            mat[0][B-2-i] = ((M>>i)&1);
    }
    // check();
    for(int i=0;i<B;++i) {
        for(int j=0;j<B;++j)
            putchar('0'+mat[i][j]);
        puts("");
    }
}

int main(void)
{
    int T; scanf("%d",&T);
    for(int i=1;i<=T;++i) {
        printf("Case #%d:",i);
        input();
        solve();
    }
    return 0;
}
