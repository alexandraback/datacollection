#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef long long ll;

char data[ 2000000 ];

int main(void){

    int T;
    scanf("%d",&T);

    for(int round = 0;round < T;++round){
        // 読み取ったデータを逆から読む。
        // 子音連続数をカウントする。母音に出会ったら連続数は０になる。
        // 要求連続数を超えていたら、そこから、自分自身１と残りの文字数を加算。
        // 未満だったら、今まで発生した、子音による現象カウントの積算値を足す。
        ll n;
        scanf("%s %lld",data,&n);
        ll slen = strlen(data);
        ll cc = 0;
        ll nvByCons = 0;
        ll ans = 0;
        for(ll z = 0;z < slen;++z){
            ll i = slen - 1 - z;
            bool isVow = false;
            switch(data[i])
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                isVow = true;
            }
            if( isVow ){
                // 母音に出会ってしまった
                cc = 0;
            }else{
                // 子音だった。ラッキー。
                ++cc;
            }
            if( cc >= n ){
                // 条件達成
                ll subans = z + 1 - (n - 1);
                ans += subans;
                nvByCons = subans;
            }else{
                // 足りない。
                // でも今まで成立したものがあれば、それを利用することができる。
                ans += nvByCons;
            }
        }
        printf("Case #%d: %lld\n",round+1,ans);
    }

    return 0;
}