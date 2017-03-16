#include <stdio.h>
#include <string.h>
#include <iostream>
#define MAXN 103
using namespace std;
int a[MAXN][MAXN],row[MAXN], col[MAXN];

int main()
{
    int t,N,M,tc,i;

    freopen("B-small-attempt0.in","r",stdin);
    freopen("ansB.out","w",stdout);

    scanf("%d",&t);
    tc = 0;
    while(tc<t)
    {
        tc++;
        scanf("%d %d",&N,&M);

        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));

    int j;
        for(i = 0; i < N; i++){
            for(j = 0; j< M; j++){
                scanf("%d",&a[i][j]);
                row[i] = max(row[i],a[i][j]);
                col[j] = max(col[j], a[i][j]);
            }
        }



      bool  flag = true;
        for(i = 0 ; i < N; i++){
            for(j = 0; j < M; j++){
                if(row[i]>a[i][j] && col[j]>a[i][j])
                    flag = false;
            }
        }

        printf("Case #%d: ",tc);
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
