#include <iostream>
#include <cstdio>
using namespace std;

int N, J;
long long pow[11][40];
long long sum[11], MOD;
int mo[11], a[40];

const int pr[15] = {0, 2,3,5,7,11,13,17,19,23,29,31,37,41,43};

void dfs(int now)
{
    if (now == -1)
    {
        bool flag = 1;
        for (int i = 2; i <= 10; ++i)
        {
            bool cnm = 0;
            for (int j = 1; j <= 14; ++j)
                if (sum[i] % pr[j] == 0) { cnm = 1; break; }
            if (cnm == 0) { flag = 0; break; }
        }
        if (!flag) return;
        
        
        for (int i = N - 1; i >= 0; --i) printf("%d", a[i]);
        for (int i = 2; i <= 10; ++i)
        {
            for (int j = 1; j <= 14; ++j)
                if (sum[i] % pr[j] == 0)
                {
                   printf(" %d", pr[j]);
                   break;
               }
        }
        printf("\n");
        
        --J;
        return ;
    }
    
    if (now != N-1 && now != 0)
    {
        a[now] = 0;
        dfs(now - 1);
        if (J == 0) return ;
    }
    
    a[now] = 1;
    for (int i = 2; i <= 10; ++i)
        sum[i] = (sum[i] + pow[i][now]) % MOD;
    dfs(now - 1);
    if (J == 0) return ;
    for (int i = 2; i <= 10; ++i)
        sum[i] = (sum[i] - pow[i][now] + MOD) % MOD;
}

int main()
{
    
    freopen("C.out","w",stdout);
    int TestCase;
    scanf("%d", &TestCase);
    
    MOD = 1;
    for (int i = 1; i <= 14; ++i)
        MOD = MOD * (long long)pr[i];
    
    for (int i = 2; i <= 10; ++i)
    {
        pow[i][0] = 1;
        for (int j = 1; j <= 32; ++j)
            pow[i][j] = (pow[i][j - 1] * (long long)i) % MOD;
    }
    
    for (int T = 1; T <= TestCase; ++T)
    {
        printf("Case #%d: \n", T);
        
        scanf("%d%d", &N, &J);
        
        for (int i = 2; i <= 10; ++i) sum[i] = 0;
        
        dfs(N - 1); 
        
    }
    
   // cout << J << endl;
    return 0;
}
