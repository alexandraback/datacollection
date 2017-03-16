/*
ID: jwzh.hi2
PROG: stall4
LANG: C++
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <cstdio>

using namespace std;

double p[100000];

/*
 最前面的是第k个数，一共A个数,
 2^100
 c(A-k,0..A-k)种情况，概率 p0*..pk-1*(1-pk)
 2^A行，A+2列
*/
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T,A,B;
    int ncase = 0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&A,&B);
        for(int i = 1; i <= A; i++){
            cin >> p[i];
        }
        double ans = 2 + B;
        p[A+1] = 0;
        for(int nb = 0; nb <= A; nb++){  //后退nb次
            double p1 = 1;
            double ret = 0;
            if(nb == 1)
                nb = 1;
            int maxv = nb + (B-A+nb) + 1 + B + 1;
            int minv = nb + (B-A+nb) + 1;
            for(int k = 1; k <= A+1; k++){ //最前面错的是第k个数
                double f  = p1 * (1-p[k]);
                if(k + nb <= A) {
                    ret += f * maxv;
                }else{
                    ret += f * minv;
                }
                p1 *= p[k];
            }
            ans = min(ans,ret);
        }
        printf("Case #%d: %lf\n",++ncase,ans);
    }
    return 0;
}
