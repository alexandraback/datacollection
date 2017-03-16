#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string.h>
#define INT64 long long
using namespace std;

int dp[10000000];

INT64 reverse(INT64 x){
    int t = 1;
    INT64 i = 10, y = 0;
    INT64 a[100];
    for (t = 0; t < 16;  ++t)
    {   
        if(x == 0)
            break;
        a[t] = x % 10;
        x /= 10; 
    }
    for (int j = 0; j < t; ++j)
    {
        y = y*10 + a[j];
    }
    return y;

}


int main(){
    int T;
    scanf("%d",&T);
    int n;

    for (int i = 1; i <= 1000000; ++i)  
        dp[i] = 1e9;

    dp[1] = 1;
    for (int i = 1; i <= 1000000; ++i)
    {   
        int y = reverse(i);
        if(y <= 1000000)
            dp[y] = min(dp[y],dp[i] + 1);
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);

    }
    /*for (int i = 0; i < 100; ++i)
    {
        printf("%d:%d\n",i+1,dp[i+1] );
    }*/
    for(int _T = 0; _T < T; ++_T)
    {
        scanf("%d",&n);
        INT64 now = 1, ans = 0;
        
        printf("Case #%d: %d\n", _T+1, dp[n]);



    }
}