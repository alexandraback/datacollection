#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<string>
#include<queue>
#include<cmath>

using namespace std;

#define mnx 10050
#define LL long long
#define inf 0x3f3f3f3f
#define MP make_pair
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
#define mod 9973

char s[mnx];
int ch[mnx*30], g[20][20];
void init(){
    g[1][1] = 1, g[1][2] = 2, g[1][3] = 3, g[1][4] = 4;
    g[2][1] = 2, g[2][2] = -1, g[2][3] = 4, g[2][4] = -3;
    g[3][1] = 3, g[3][2] = -4, g[3][3] = -1, g[3][4] = 2;
    g[4][1] = 4, g[4][2] = 3, g[4][3] = -2, g[4][4] = -1;
}
int main(){
    freopen( "tt.txt", "r", stdin );
    freopen( "out.txt", "w", stdout );
    int cas, kk = 1;
    init();
    scanf( "%d", &cas );
    while( cas-- ){
        int n, len = 0;
        LL m;
        cin >> n >> m;
        scanf( "%s", &s );
        if( m > 20 ){
            m %= 4;
            while( m < 20 )
                m += 4;
        }
        for( int i = 1; i <= m; ++i )
            for( int j = 0; j < n; ++j )
                ch[len++] = s[j] - 'g';
        int i = 0, tmp = ch[i];
        bool ok1 = 0, ok2 = 0, ok3 = 0;
        for( i = 1; i < len; ++i ){
            if( tmp == 2 ){
                ok1 = 1; break;
            }
            if( tmp < 0 ){
                tmp = -g[-tmp][ch[i]];
            }
            else{
                tmp = g[tmp][ch[i]];
            }
        }
        tmp = ch[i];
        for( i = i+1; i < len; ++i ){
            if( tmp == 3 ){
                ok2 = 1; break;
            }
            if( tmp < 0 ){
                tmp = -g[-tmp][ch[i]];
            }
            else{
                tmp = g[tmp][ch[i]];
            }
        }
        tmp = ch[i];
        for( i = i+1; i < len; ++i ){
            if( tmp < 0 ){
                tmp = -g[-tmp][ch[i]];
            }
            else{
                tmp = g[tmp][ch[i]];
            }
        }
        if( tmp == 4 ) ok3 = 1;
        printf( "Case #%d: ", kk++ );
        if( ok1 && ok2 && ok3 )
            puts( "YES" );
        else puts( "NO" );
    }
    return 0;
}
