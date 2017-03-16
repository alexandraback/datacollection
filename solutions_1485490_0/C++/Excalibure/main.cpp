#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAXN 120

typedef long long lint;

lint dp[MAXN][MAXN];
lint fdp[MAXN][MAXN];

struct Packeg{
    lint num;
    int flag;
};
Packeg pa[MAXN] ,pb[MAXN];

void manage (int n ,int m);
lint minnum (lint a ,lint b);
lint maxnum (lint a ,lint b);
void init (int m);

int main (){
    int t ,n ,m;
    freopen ("in.in","r",stdin);
    freopen ("out.out","w",stdout);
    cin >> t;
    for (int test=1 ;test<=t ;test++){
        cin >> n >> m;
        for (int ni=1 ;ni<=n ;ni++){
            cin >> pa[ni].num >> pa[ni].flag;
        }
        for (int mi=1 ;mi<=m ;mi++){
            cin >> pb[mi].num >> pb[mi].flag;
        }
        init (m);
        manage (n ,m);
        cout << "Case #" << test << ": " << dp[n][m] << endl;
        /*
        for (int i=1 ;i<=n ;i++){
            cout << i << endl;
            for (int j=0 ;j<=m ;j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        */
    }
    return 0;
}
void manage (int n ,int m){
    //边缘数据处理
    lint temp = pa[1].num;
    lint val = 0;
    lint used ,kk ,pp;
    for (int i=0 ;i<=m ;i++){
        if (pa[1].flag == pb[i].flag){
            kk = minnum (temp ,pb[i].num);
            val += kk;
            temp -= kk;
            fdp[1][i] = pb[i].num-kk;
        }
        else
            fdp[1][i] = pb[i].num;
        dp[1][i] = val;
    }
    //处理
    for (int ni=2 ;ni<=n ;ni++){
        for (int lm=0 ;lm<=m ;lm++){
            temp = pa[ni].num;
            val = dp[ni-1][lm];
            fdp[ni][lm] = fdp[ni-1][lm];
            for (int mi=lm ;mi<=m ;mi++){
                if (pa[ni].flag == pb[mi].flag){
                    if (mi == lm) used = fdp[ni][lm];
                    else used = pb[mi].num;
                    kk = minnum (temp ,used);
                    val += kk;
                    temp -= kk;
                    pp = used-kk;
                    
                    if (val > dp[ni][mi] || (val == dp[ni][mi] && fdp[ni][mi] < pp)){
                        dp[ni][mi] = val;
                        fdp[ni][mi] = pp;
                    }
                }
                else{
                    if (val > dp[ni][mi]){
                        dp[ni][mi] = val;
                        fdp[ni][mi] = pb[mi].num;
                    }
                }
            }
        }
    }
    return ;
}
lint minnum (lint a ,lint b){
    return (a<b?a:b);
}
lint maxnum (lint a ,lint b){
    return (a>b?a:b);
}
void init (int m){
    for (int i=0 ;i<=m ;i++){
        dp[0][i] = 0;
    }
    pb[0].num = 0;
    pb[0].flag = -1;

    for (int i=0 ;i<=100 ;i++){
        for (int j=0 ;j<=100 ;j++){
            dp[i][j] = 0;
            fdp[i][j] = pb[j].num;
        }
    }
    return ;
}