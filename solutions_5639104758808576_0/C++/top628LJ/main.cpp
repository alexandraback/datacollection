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
int a[mnx];
int main(){
    freopen( "tt.txt", "r", stdin );
    freopen( "out.txt", "w", stdout );
    int cas, kk = 1;
    scanf( "%d", &cas );
    while( cas-- ){
        int n;
        scanf( "%d", &n );
        scanf( "%s", s );
        for( int i = 0; i <= n; ++i )
            a[i] = s[i] - '0';
        int sum = 0, ans = 0;
        for( int i = 1; i <= n; ++i ){
            sum += a[i-1];
            if( sum < i && a[i] ){
                ans += i - sum;
                sum = i;
            }
        }
        printf( "Case #%d: %d\n", kk++, ans );
    }
    return 0;
}
