#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<algorithm>

using namespace std;

typedef long long ll;

char str[200][200] = {};
int strn[200];

int main(void){

    int T;
    scanf("%d",&T);

    for(int r = 0;r < T;++r){
        bool solved = true;
        int ans = 0;

        int n;
        int idx[200];
        scanf("%d",&n);
        for(int i = 0;i < n;++i){
            scanf("%s ",str[i]);
            strn[i]=strlen(str[i]);
            idx[i] = i;
        }

        // 全パターン回そうじゃないか
        do{
            // 文字が分断されてなければOK
            ll left=0;
            int last = str[idx[0]][0];
            for(int i = 0;i < n;++i){
                for(int z = 0;z < strn[idx[i]];++z){
                    int cc = str[idx[i]][z];
                    // すでに leave した文字が出てきたらアウト
                    if((left >> (cc-'a'))&1){
                        goto NEXTPM;
                    }
                    // 文字が切れたら left 登録
                    if(cc != last){
                        left |= (1LL << (last - 'a'));
                    }
                    last = cc;
                }
            }
            // ここまできてたらOK
            ++ans;
            NEXTPM:
            printf("");
        }while(next_permutation(idx,idx+n));

ANS:
        printf("Case #%d: ",r+1);
        if(solved){
            printf("%d",ans);
        }else{
            printf("impossible");
        }
        printf("\n");
    }

}
