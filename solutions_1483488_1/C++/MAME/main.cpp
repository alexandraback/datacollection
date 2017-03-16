#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
#if 0
    char* table = new char[ 10000 * 10000 ];
    int da,db;
    int cnt = 0;
    for(int r = 0;r < 10000;++r ){
        for(int c = 0;c < 10000;++c ){
            table[r + c * 10000] = 0;
        }
    }
    while( scanf("%d %d", &da,&db) == 2 ){
        table[ da + db * 10000 ]++;
        if( table[ da + db * 10000 ] > 1 ){
            printf("wrong pair\n");
        }
        ++ cnt;
    }
    printf("%d\n",cnt);
    return 0;
#endif

    int T;
    scanf("%d\n",&T);
    for(int r = 0;r < T;++r){
        printf("Case #%d: ",r+1);
        int A,B;
        int dig = 0;
        scanf("%d %d",&A,&B);
        // 桁数を特定
        int t = A;
        int unit = 1;
        while( t > 0 ){ ++dig; t /= 10; unit *= 10; }
        int ans = 0;
        unit /= 10;
        for(int n = A;n <= B;++n)
        {
            // n の dig 回転をまじめに調べる。
            // で Ri > n かつ A <= Ri <= B なる回転があったら、ペア成立。カウントアップ。
            t = n;
            int dup[10];
            int dupNum = 0;
            for(int i = 1;i < dig;++i){
                // まず回転させる
                t = t / 10 + (t % 10) * unit;
                // 条件に合致？
                // 周期性のある数字列だと重複カウントしてしまうことがあるので
                // この可能性を力業で排除
                if( t > n && (A <= t && t <= B) ){
                    bool isDup = false;
                    for(int z = 0;z < dupNum;++z){
                        if( t == dup[z] ){
                            isDup = true;
                            break;
                        }
                    }
                    dup[ dupNum++ ] = t;
                    if( isDup == false ){
                        //printf("(%04d,%04d)%c",n,t,((ans+1)%10)==0?'\n':' ');
                        ++ans;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}