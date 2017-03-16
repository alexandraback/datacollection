#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int e, r, n;

int v[100];

int dp[20][20];

int rec (int pos, int q)
{
    if (pos >= n)
        return 0;
    if (dp[pos][q] != -1) return dp[pos][q];
    
    int ret = 0; 
    int i;
    for (i = 0; i <= q; i++)
    {
        if (rec(pos + 1, min (q - i + r, e)) + v[pos]*i > ret)
            ret = rec(pos + 1, min (q - i + r, e)) + v[pos]*i;
    }
    
    return dp[pos][q] = ret;
}



int solve ()
{
    
    memset (dp, -1, sizeof (dp));
    
    cin >> e >> r >> n;
    
    int i; 
    for (i = 0; i < n ; i ++)
        cin >> v[i];
 
    return rec (0, e);
}

int main ()
{
    int t;
    scanf ("%d", &t);
    
    int i ;
    for (i = 0; i < t; i ++)
    {
        printf ("Case #%d: %lld\n", i+1, solve());
    }
    
    
    return 0;
}