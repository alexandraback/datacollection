#include <cstdio>
#include <cstring>
#include <cmath>

#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;
typedef double db;

const int Max = 2048;

int A[Max],B[Max],U[Max];

int main(){
    freopen("W:\\B-small-attempt2.in","r",stdin);
    freopen("W:\\B-small-attempt2.out","w",stdout);
    int tCase;
    scanf("%d",&tCase);
    for (int ct = 1;ct <= tCase;ct++){
        int N;
        scanf("%d",&N);
        for (int i = 0;i < N;i++)
            scanf("%d%d",&A[i],&B[i]);
        int c = 0;
        int res = 0;
        int star = 0;
        memset(U,0,sizeof(U));
        while (c < N){
            int md = -1,mi = -1;
            for (int i = 0;i < N;i++){
                int v = 0;
                if (U[i] == 1){
                    if (star >= B[i])
                        v = 1;
                }else if (U[i] == 0){
                    if (star >= B[i])
                        v = 2;
                    else if (star >= A[i])
                        v = 1;
                }
                if (v >= md){
                    if (v > md)
                        md = v,mi = -1;
                    if (v == 2){
                        mi = i;
                        break;
                    }else if (v == 1){
                        if (U[i] == 1){
                            mi = i;
                        }
                    }
                    if (mi == -1)
                        mi = i;
                }
            }
            if (md == 0) break;
            U[mi] += md;
            star += md;
            c += U[mi] == 2;
            ++res;
            //printf("Round %d : %d %d=> %d\n",res,md,mi,star);for (int i = 0;i < N;i++)printf("%d ",U[i]);puts("");
        }
        printf("Case #%d: ",ct);
        if (c < N) puts("Too Bad");
        else printf("%d\n",res);
    }
    return 0;
}
