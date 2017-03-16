#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int max(int a,int b) { return a>b?a:b; }
int min(int a,int b) { return a<b?a:b; }
int main()
{
    int t,tt;
    scanf("%d",&tt);
    for(t=0;t < tt;t++)
    {
        int E,R,N;
        scanf("%d %d %d",&E,&R,&N);
        int v[N];
        for(int i = 0;i < N;i++) {
            scanf("%d",&v[i]);
        }
        int ans[2][E+1];
        for(int i = 0;i <= E;i++)
            ans[0][i] = 0;
        for(int i = 0;i <= E;i++) // USE ENERGY until left I
        {
            ans[0][i] = v[0] * (E-i);
            //printf("%d ",ans[0][i]);
        }
        //printf("\n");
        int cur = 1;
        int prev = 0;
        for(int j = 0;j < N-1;++j) {
            // reset
            for(int i = 0;i <= E;i++)
                ans[cur][i] = 0;
            for(int i = 0;i <= E;i++) // loop all prev to fill this
            {
                int enReg = min(i+R,E);
                for(int x = 0;x <= E;x++) // REGEN +R and use -x
                {
                    if(enReg-x < 0)
                        break;
                    ans[cur][enReg-x] = max(ans[cur][enReg-x],ans[prev][i] + (x * v[j+1]));
                    //printf("[%d][%d] + %d = %d\n",prev,i,(x * v[j+1]));
                }
            }
            /*for(int i = 0;i <= E;i++)
                printf("%d ",ans[cur][i]);
            printf("\n");*/
            prev = cur;
            cur = 1 - cur;
        }
        //printf("%d",ans[prev][0]);
        /*for(int i = -R+1;i <= E-R;i++) {// USE EN AND REGEN (i)
            //printf("%d %d %d\n",E,i,R);
            if(E-i <= E) {
                ans[0][E-i] = (i+R)*v[0];
                printf("%d(%d) ",ans[0][E-i],E-i);
            }
        }
        printf("\n");
        int cur = 1;
        int prev = 0;
        for(int i = 1;i < N;i++)
        {
            for(int j = -R+1;j <= E-R;j++) // j = diff from the before
            {
                if(E-j <= E) {
                    if(E-j == E)
                    {

                    }
                    ans[cur][E-j] = max((j+R) * v[i] + ans[prev][E-j],-1);
                    printf("[]%d -> (%d)\n",E-j,(j+R)*v[i]);
                }
            }
            prev = cur;
            cur = 1 - cur;
        }*/
        printf("Case #%d: %d\n",t+1,ans[prev][0]);
    }
}
