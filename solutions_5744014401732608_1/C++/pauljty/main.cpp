#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
typedef long long ll;

int msp[100][100];
ll f2[65];
ll n, m;

void ans()
{
    int i, j;
    printf("POSSIBLE\n");
    for( i = 1; i <= n; i ++ ){
        for( j = 1; j <= n; j ++ ){
            printf("%d", msp[i][j]);
        }
        puts("");
    }
}

void init()
{
    ll i;
    for( i = 1, f2[0] = 1; i <= 59; i ++ )
        f2[i] = f2[i-1]*2;
}

int main()
{
    int i, j, cnt, cas = 1;
    init();
    int T;
    freopen("B-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    while( T -- ){
        scanf("%lld %lld", &n, &m);
        memset( msp, 0, sizeof(msp) );
        printf("Case #%d: ", cas++);
        if( m > f2[n-2] ){
            printf("IMPOSSIBLE\n");
            continue;
        }
        msp[1][n] = 1;m --;
        if( !m ){ ans(); continue; }
        for( i = 2; i <= n-1; i ++ ){
            for( j = i+1; j <= n-1; j ++ ){
                msp[i][j] = 1;
            }
        }
        for( i = 2; i <= n-1; i ++ ){
            msp[i][n] = 1;
        }
        int b[70];
        memset( b, 0, sizeof(b) );
        int t = n-1;
        while( m ){
            if( m & 1 ){
                b[t] = 1;
            }
            t --;
            m = m/2;
        }
        for( i = 2; i <= n-1; i ++ ){
            if( b[i] ){
                msp[1][i] = 1;
            }
        }
        ans();
    }
}
