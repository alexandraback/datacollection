#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

unsigned char map[1000][1000];
int N;

void dump()
{
    printf("\n");
    for(int n = 0;n < N;++n){
        for(int c = 0;c < N;++c){
            printf("%d ",map[n][c]);
        }printf("\n");
    }printf("\n");
}

int solve(int preN, int n, int c)
{
    if(n >= N) return 0;
    if(c >= N) return 0;
    for(int dc = c;dc < N;++dc){
        // 新規開拓をチェック
        if(dc == n)continue;
        if(preN >= 0 && n > 0){
            if( map[n][dc] ){
                // preN->n->dc は接続されている。
                // preN->dc を短絡させる。
                // でもすでに短絡されていたら、
                // diamond を発見したと応答する。
                if( map[preN][dc] ){
                    return 1;
                }else{
                    map[preN][dc] = 2;
                }
            }
        }
        // 掘り下げ確認
        if( map[n][dc] == 1 ){
            // 掘り下げて確認
            if( solve(n,dc,0) ){
                // diamond が見つかったらしいので返答
                return 1;
            }
        }
    }
    return 0;
}

int solve()
{
    for(int n = 0;n < N - 1;++n){
        if( solve(-1,n,0) ){
            return 1;
        }
    }
    return 0;
}

int main(void)
{
    int T;
    scanf("%d\n",&T);
    for(int r = 0;r < T;++r){
        printf("Case #%d: ", r+1);
        int ans = 0;

        // a to b の道を行列で表現して、
        // あとはその中を地道につないでいくだけ
        memset(map,0,1000*1000);
        scanf("%d\n",&N);
        //printf("\n%d\n",N);
        for(int n = 0;n < N;++n){
            int PN;
            scanf("%d\n",&PN);
            //printf("%d ",PN);
            for(int c = 0;c < PN;++c){
                int V;
                scanf("%d",&V);
                //printf("%d ",V);
                V -= 1;
                map[n][V] = 1;
            }
            //printf("\n");
        }

        // ０行目から深さ優先で探索して、
        // 連結性を新規開拓
        //dump();
        ans = solve();
        //dump();

        printf("%s\n",ans?"Yes":"No");
    }
    return 0;
}