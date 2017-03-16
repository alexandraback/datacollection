#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef long long ll;

struct Atk{
    ll day;
    ll xf;
    ll xt;
    ll str;
};

Atk data[ 10000 ];
int adnum = 0;

const int GWSIZE = 10000000;
const int GWHALF = GWSIZE / 2;
int gwIndex = 0;
ll gw[2][ GWSIZE ];

void gwClear()
{
    memset(gw[0],0,sizeof(ll) * GWSIZE);
    memset(gw[1],0,sizeof(ll) * GWSIZE);
    gwIndex = 0;
}

bool gwAttack(ll f,ll t,ll w)
{
    bool attacked = false;
    for(ll p = f;p < t;++p){
        if( gw[ gwIndex ][ p + GWHALF ] < w ){
            if( w > gw[ 1 - gwIndex ][ p + GWHALF ] ){
            gw[ 1 - gwIndex ][ p + GWHALF ] = w;
            attacked = true;
            }
        }
    }
    return attacked;
}

int comp(const void* a, const void* b){
    return (int)(((const Atk*)a)->day - ((const Atk*)b)->day);
}

int main(void){

    int T;
    scanf("%d",&T);

    for(int round = 0;round < T;++round){
        int N;
        scanf("%d",&N);
        adnum = 0;
        for(int i = 0;i < N;++i){
            ll day;
            ll numAtk;
            ll xf,xt;
            ll str;
            ll dd,dp,ds;
            scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&day,&numAtk,&xf,&xt,&str,&dd,&dp,&ds);
            // 必要なだけアタックデータを作って詰め込む
            for(int ad = 0;ad < numAtk;++ad){
                Atk& a = data[ adnum++ ];
                a.day = day;
                a.xf = xf;
                a.xt = xt;
                a.str = str;

                day += dd;
                xf += dp;
                xt += dp;
                str += ds;
            }
        }
        // アタックデータが出そろったところでソート
        qsort( data, adnum, sizeof(Atk), comp );
        // アタック開始
        gwClear();
        ll ans = 0;
        ll lastAttack = 0;
        for(int i = 0; i < adnum;++i){
            // 日付が変わったら、アタック前に壁を成長させます
            Atk& a = data[ i ];
            //printf("%lld [%lld, %lld] %lld ",a.day,a.xf,a.xt,a.str);
            if( lastAttack != a.day ){
                memcpy(gw[gwIndex],gw[1-gwIndex],sizeof(ll)*GWSIZE);
                //gwIndex = 1 - gwIndex;
            }
            // アタックします
            bool atkSucc = gwAttack( a.xf, a.xt, a.str );
            if( atkSucc ){
                ++ans;
            }
            //printf("%d\n",atkSucc);
        }
        printf("Case #%d: %lld\n",round+1,ans);
    }
    return 0;
}