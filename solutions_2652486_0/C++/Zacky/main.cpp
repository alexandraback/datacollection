#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
using namespace std;

double match(int p,int a,int b,int c) {
    if(p == 1) return true;
    if(p == a) return true;
    if(p == b) return true;
    if(p == c) return true;
    if(p == a * b) return true;
    if(p == a * c) return true;
    if(p == b * c) return true;
    if(p == a * b * c) return true;
    return false;
}

int main()
{
    freopen("C-small.in","r",stdin);
    freopen("C-small.out","w",stdout);
    int cas,T,R,N,M,K,i,j,k,l;
    int product[10];
    bool flag;
    scanf("%d",&T);
    for(cas = 1;cas <= T;++cas) {
        scanf("%d %d %d %d",&R,&N,&M,&K);
        printf("Case #%d:\n",cas);
        while(R--) {
            for(i = 1;i <= K;++i) {
                scanf("%d",&product[i]);
            }
            flag = false;
            for(i = 2;i <= M;++i) {
                for(j = 2;j <= M;++j) {
                    for(k = 2;k <= M;++k) {
                        for(l = 1;l <= K;++l) {
                            if(!match(product[l],i,j,k))
                                break;
                        }
                        if(l > K) {
                            flag = true;
                            break;
                        }
                    }
                    if(flag) break;
                }
                if(flag) break;
            }
            if(flag) printf("%d%d%d\n",i,j,k);
            else {
                srand((unsigned)time(0));
                printf("%d",rand() % 4 + 2);
                printf("%d",rand() % 4 + 2);
                printf("%d\n",rand() % 4 + 2);
            }
        }
    }
}
