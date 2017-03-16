#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>

#define LL long long 

using namespace std;
const int inf = 1e9+7;
const int maxn = 55;

int b;
LL m;
int ans[maxn][maxn];

int main(){

    int T; scanf("%d", &T);
    for(int it=1;it<=T;it++){
        printf("Case #%d: ", it);
        scanf("%d%lld", &b, &m);

        if ( ((LL)1<<(b-2)) < m ){
            printf("IMPOSSIBLE\n");
        }
        else {
            printf("POSSIBLE\n");
            memset(ans,0,sizeof(ans));
            for(int i=1;i<b;i++)
                for(int j=i+1;j<b;j++)
                    ans[i][j] = 1;

            int now = 2;
            while( m>0 ){
                if ( m&1 ){
                    if ( now==b ){
                        for(int i=1;i<b;i++)
                            ans[i][b] = 1;
                    }
                    else 
                        ans[now][b]++;
                }
                m >>= 1; now++;
            }

            for(int i=1;i<=b;i++){
                for(int j=1;j<=b;j++)
                    printf("%d",ans[i][j]);
                printf("\n");
            }

        }
    }   

    return 0;
}

