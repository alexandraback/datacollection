#include <cstdio>
#include <algorithm>
using namespace std;
int i,j,k,T,N,ok,X,v1[1001],v2[1001],Min,x1,x2,y1,y2,S1,S2;
float q;
void afisare();
int main()
{
    freopen("ProblemD.in","r",stdin);
    freopen("ProblemD.out","w",stdout);
    scanf("%d",&T);
    for(k=1;k<=T;k++)
    {
        S1=0;
        S2=0;
        scanf("%d",&N);
        for(i=1;i<=N;i++)
        {
            scanf("%f",&q);
            v1[i]=int(q*10000+0.5);
        }
        for(i=1;i<=N;i++)
        {
            scanf("%f",&q);
            v2[i]=int(q*10000+0.5);
        }
        sort(v1+1,v1+N+1);
        sort(v2+1,v2+N+1);
        x1=1;
        y1=N;
        x2=1;
        y2=N;
        while(y1-x1+1>=1 && y2-x2+1>=1)
        {
            if(v1[y1]>v2[y2])
            {
                S2++;
                x2++;
                y1--;
            }
            else
            {
                y1--;
                y2--;
            }
        }

        X=0;
        ok=1;
        for(i=1;i<=N && ok;i++)
        {
            if(v1[i]>v2[1])
            ok=0;
            else
            X++;
        }

        for(i=1;i<=X;i++)
        {
            v1[i]=0;
            v2[N-i+1]=1;
        }
        sort(v1+1,v1+N+1);
        sort(v2+1,v2+N+1);
        while(X<N)
        {
            Min=v2[X+1];
            ok=1;
            for(i=X+1;i<=N && ok;i++)
            {
                if(v1[i]>v2[X+1])
                {
                    ok=0;
                    v1[i]=1;
                    v2[X+1]=0;
                }
            }
            if(ok)
            {
                v1[X+1]=0;
                v2[X+1]=1;
            }
            X++;
            sort(v1+1,v1+N+1);
            sort(v2+1,v2+N+1);
        }
        for(i=1;i<=N;i++)
        S1+=v1[i];
        printf("Case #%d: %d %d\n",k,S1,S2);
    }
    return 0;
}
void afisare()
{
    int l;
    for(l=1;l<=N;l++)
    printf("%d ",v1[l]);
    printf("\n");
    for(l=1;l<=N;l++)
    printf("%d ",v2[l]);
}
