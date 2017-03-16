#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;


char s[] = "aeiou";
char a[1111111];
int  b[300];

inline int ok() {
       for( int i = 0 ; i < strlen(s); ++i ) {
            if( b[ s[i] ] != 0 ) return 0;
       }
       return 1;
}

int main() {
    int T, n;
    cin>>T;
    for( int tc = 1; tc <= T; ++tc ) {
         scanf("%s%d", a, &n );
         LL ans = 0, start = 0;
         int len = strlen( a );
         memset( b, 0, sizeof(b));
         
         for( int i = 0; i < n; ++i ) b[ a[i] ]++;
         for( int i = n; i <= len; ++i ) {
              if( ok() ) {
                  ans += 1LL*(i-start-n+1)*(len-i+1);
                  start = i-n+1;
                  //cout<<i<<" "<<ans<<endl;
              }
              if( i == len ) break;
              b[ a[i] ]++;
              b[ a[i-n] ]--;
         }
         printf("Case #%d: %lld\n",tc, ans );
    }
    return 0;
}
