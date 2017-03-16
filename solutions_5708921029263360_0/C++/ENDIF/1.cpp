#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
typedef long long ll;
using namespace std;

int dp[55], sum[55];
ll b, m;
int M[55][55];
bool judge(){
    for(int i = 0; i <= b-2; i++)
        if( ((1LL)<<i)  >= m) return true;
    return false;
}
int j, p, s, k;
int ab[11][11], ac[11][11], bc[11][11];
int main(){
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("out", "w", stdout);
    int T, ca = 1;
    cin>>T;
    while(T--){
        printf("Case #%d: ", ca++);
        cin>>j>>p>>s>>k;
        memset(ab, 0, sizeof(ab));
        memset(ac, 0, sizeof(ac));
        memset(bc, 0, sizeof(bc));
        int ans = 0;
        for(int a = 1; a <= j; a++)
            for(int b = 1; b <= p; b++)
                for(int c = 1; c <= s; c++)
                    if(ab[a][b] < k&&ac[a][c] < k&&bc[b][c] < k)
                        ab[a][b]++, ac[a][c]++, bc[b][c]++, ans++;
        cout<<ans<<endl;

        memset(ab, 0, sizeof(ab));
        memset(ac, 0, sizeof(ac));
        memset(bc, 0, sizeof(bc));
        for(int a = 1; a <= j; a++)
            for(int b = 1; b <= p; b++)
                for(int c = 1; c <= s; c++)
                    if(ab[a][b] < k&&ac[a][c] < k&&bc[b][c] < k)
                        ab[a][b]++, ac[a][c]++, bc[b][c]++, printf("%d %d %d\n", a, b, c);


//        continue ;
//        printf("Case #%d: ", ca++);
//
//        if(judge() == false){
//            puts("IMPOSSIBLE");
//            continue ;
//        }
//
//        memset(M, 0, sizeof(M));
//        for(int j = 1; j < b; j++)
//            for(int i = 1; i < j; i++)
//                M[i][j] = 1;
//
//        if( ((1LL)<<(b-2)) == m){
//            for(int i = 1; i < b; i++)
//                M[i][b] = 1;
//        }
//        else{
//            for(int i = 1; m; m >>= 1, i++)
//                if(m&1) M[i+1][b] = 1;
//        }
//        puts("POSSIBLE");
//        for(int i = 1; i <= b; i++){
//            for(int j = 1; j <= b; j++)
//                printf("%d", M[i][j]);
//            puts("");
//        }
    }
    return 0;
}
