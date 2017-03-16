#include<stdio.h>
int N,M[1001],map[1001][10],v[1001];
bool Go(int k)
{
    if(v[k]>0)
        return 1;
    v[k]++;
    for(int i=0;i<M[k];i++)
        if(Go(map[k][i]))
            return 1;;
    return 0;
}
bool DI()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
            v[j]=0;
        if(Go(i))
            return 1;
    }
    return 0;
}
int main()
{
    int T,t,i,j;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&N);
        for(i=1;i<=N;i++)
        {
            scanf("%d",M+i);
            for(j=0;j<M[i];j++)
                scanf("%d",&map[i][j]);
        }
        printf("Case #%d: %s\n",t,DI()?"Yes":"No");
    }
}
