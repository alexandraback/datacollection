#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

bool dp[2000001];

int main(void){
    
    freopen("CSin.txt", "r", stdin);
    freopen("CSout.txt", "w", stdout);
    
    int cas, c=0, a, b, base;
    
    scanf("%d", &cas);
    while( cas-- ){
        printf("Case #%d: ", ++c);
        scanf("%d %d", &a, &b);
        memset(dp,0,sizeof(dp));
        
        int ans=0, cnt;
        int quo, now;
        for(int i=a; i<=b; ++i){
            if( dp[i] )   continue;
            
            base = 1;
            while( base*10 <= i )
                base *= 10;
            
            now = i;
            cnt = 1;
            dp[now] = true;
            while(1){
                quo = now % 10;
                now = now/10 + base*quo;
                if( quo ){
                    if( now>b || now<a )    continue;
                    else if( dp[now] )      break;
                    else{
                        dp[now] = true;
                        ++cnt;
                    }
                }
            }
            ans += (cnt*(cnt-1)/2);
        }
        cout << ans << endl;
    }
    
    return 0;
}
