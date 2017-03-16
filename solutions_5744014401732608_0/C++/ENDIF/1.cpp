#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int dp[55], sum[55], b, m;
int M[55][55];
bool judge(){
    for(int i = 0; i <= b-2; i++)
        if( ((1LL)<<i)  >= m) return true;
    return false;
}
int main(){
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T, ca = 1;
    cin>>T;
    while(T--){
        cin>>b>>m;
        printf("Case #%d: ", ca++);
//        if(judge() == false)
//        int wei = (m&-m) == m? 0 : 1, mm = m;
//        while(mm)
//            wei++, mm >>= 1;

        if(judge() == false){
            puts("IMPOSSIBLE");
            continue ;
        }

        memset(M, 0, sizeof(M));
        for(int j = 1; j < b; j++)
            for(int i = 1; i < j; i++)
                M[i][j] = 1;

        if( ((1LL)<<(b-2)) == m){
            for(int i = 1; i < b; i++)
                M[i][b] = 1;
        }
        else{
            for(int i = 1; m; m >>= 1, i++)
                if(m&1) M[i+1][b] = 1;
        }
        puts("POSSIBLE");
        for(int i = 1; i <= b; i++){
            for(int j = 1; j <= b; j++)
                printf("%d", M[i][j]);
            puts("");
        }
    }
    return 0;
}
