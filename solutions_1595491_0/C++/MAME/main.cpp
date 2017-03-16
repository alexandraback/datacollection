#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int T;
    scanf("%d\n",&T);
    for(int r = 0;r < T;++r){
        printf("Case #%d: ", r+1);
        int N,S,P;
        scanf("%d %d %d ", &N, &S, &P);
        int ans = 0;
        for(int i = 0;i < N;++i){
            int total;
            scanf("%d",&total);
            // 素点で分岐
            int rawscore = (total+2)/3;
            int mod = total % 3;
            if( rawscore >= P ){
                // 合格
                ++ans;
            }else if( rawscore >= P - 1 ){
                // 惜しい。
                // 得点が移動可能で、かつサプライジング枠が残ってればそれで昇格。
                if( total > 1 && (mod == 0 || mod == 2) && S ){
                    ++ans;
                    --S;
                }
            }
        }
        printf("%d\n",ans);
    }
}