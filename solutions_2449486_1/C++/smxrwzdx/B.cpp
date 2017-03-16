#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int N,M;
int A[110][110];
int Y[110],X[110];
int main()
{
    freopen("bb.in","r",stdin);
    freopen("bb.out","w",stdout);
    int i,j,k;
    int T;
    scanf("%d",&T);
    int tt=0;
    while(T--)
    {tt++;
        scanf("%d%d",&N,&M);
        for(i=0;i<=N;i++) Y[i]=0;
        for(j=0;j<=M;j++) X[j]=0;
        for(i=0;i<N;i++)
        {
            for(j=0;j<M;j++)
            {
                scanf("%d",&A[i][j]);
                Y[i]=max(Y[i],A[i][j]);
                X[j]=max(X[j],A[i][j]);
            }
        }
        bool jud=true;
        for(i=0;i<N;i++)
        {
            for(j=0;j<M;j++)
            {
                if(A[i][j]!=min(Y[i],X[j])) jud=false;
            }
        }
        printf("Case #%d: ",tt);
        if(jud) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
