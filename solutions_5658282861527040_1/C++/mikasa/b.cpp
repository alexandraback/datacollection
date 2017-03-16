#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<cstdio>

using namespace std;

typedef long long ll;
const int maxn = 30;

vector<int> dA, dB, dC;

vector<int> digitIt(int D)
{
    vector<int> dD(maxn);
    for (int i = 0; i <maxn; i++)
        dD[i] = ( (D & (1<<i)) != 0 );
    return dD;
}

ll dp[maxn+ 1][2][2][2];

ll rec(int t, int eqA, int eqB, int eqC)
{
    ll & res = dp[t][eqA][eqB][eqC];
    if (res == -1)
    {
        res = 0;
        if (t == 0)
            res = 1;
        else
        {
            res = 0;
            for (int x = 0; x < 2; x++)
            {
                for (int y = 0; y < 2; y++)
                {
                    int z = x & y;
                    if (    (!eqA || (x <= dA[t-1]) )
                            && (!eqB || (y <= dB[t-1]) )
                            && (!eqC || (z <= dC[t-1]) )
                       )
                    {
                        res += rec(
                                   t-1,
                                   eqA && (x == dA[t-1] ),
                                   eqB && (y == dB[t-1] ),
                                   eqC && (z == dC[t-1] )
                               );
                    }
                }
            }
        }
    }
    return res;
}

ll sol(int A, int B, int C)
{
    dA = digitIt(A), dB = digitIt(B), dC = digitIt(C);
    return rec(maxn, 1,1,1 );
}

int main()
{
    int t,cas=0,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
	memset(dp,-1,sizeof(dp));
        scanf("%d%d%d",&a,&b,&c);
        printf("Case #%d: %lld\n",++cas,sol(a-1,b-1,c-1));
    }
}
