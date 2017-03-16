#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <queue>
#include <vector>
#include <set>
#define maxn 200
#define oo 1000000000
#define clearAll(a) memset(a,0,sizeof(a))
#define sq(a) ((a)*(a))

using namespace std;

typedef long long ll;

ll dp[50][2][2][2];

int a[50],b[50],k[50];
int la,lb,lk;
int mxl;
int A,B,K;

void deal(int x,int a[50],int &l){
    while (x){
        a[l++]=x&1;
        x>>=1;
    }
}

int main()
{
    freopen("E:\\codejam\\input.txt","r",stdin);
    freopen("E:\\codejam\\output.txt","w",stdout);

    int tt;
    cin >> tt;
    int id = 0;
    while (tt--)
    {
        cin >>A >> B >> K;
        la=lb=lk=0;
        clearAll(a);
        clearAll(b);
        clearAll(k);
        clearAll(dp);

        deal(A,a,la);
        deal(B,b,lb);
        deal(K,k,lk);
        mxl = max(la,max(lb,lk));

        dp[mxl][0][0][0] = 1;

        for (int i=mxl-1;i>=0;i--)
            for (int sa=0;sa<2;sa++)
                for (int sb=0;sb<2;sb++)
                    for (int sk=0;sk<2;sk++)
                        for (int d1=0;d1<2;d1++)
                            for (int d2=0;d2<2;d2++)
                            {
                                if (sa==0&&d1>a[i]) continue;
                                if (sb==0&&d2>b[i]) continue;
                                if (sk==0&&(d1&d2)>k[i]) continue;

                                int na,nb,nk;
                                if (sa==1||d1<a[i]) na=1; else na=0;
                                if (sb==1||d2<b[i]) nb=1; else nb=0;
                                if (sk==1||(d1&d2)<k[i]) nk=1; else nk=0;

                                dp[i][na][nb][nk] += dp[i+1][sa][sb][sk];

                            }
        ll ans = dp[0][1][1][1];


        id++;
        printf("Case #%d: %I64d\n",id,ans);
    }
    return 0;
}
