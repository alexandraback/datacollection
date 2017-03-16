#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int N,E,R,rr;
int mark[15][15],save[15][15],v[15],T;
int re(int e,int n)
{
        if(n==N) return 0;
        if(mark[e][n]==rr) return save[e][n];
        mark[e][n]=rr;
        save[e][n]=-1;
        //printf("%d %d\n",e,n);
        for(int i=0;i<=e;i++)
        {
                if(e-i+R>E)
                {
                        save[e][n]=max(save[e][n],re(E,n+1)+v[n]*i);
                }
                else
                {
                        save[e][n]=max(save[e][n],re(e-i+R,n+1)+v[n]*i);
                }
        }
        //printf("%d %d %d\n",e,n,save[e][n]);
        return save[e][n];
}
main()
{
        freopen("B-small-attempt1.in","r",stdin);
        freopen("outBBB.txt","w",stdout);
        scanf("%d",&T);
        for(rr=1;rr<=T;rr++)
        {
                scanf("%d %d %d",&E,&R,&N);
                for(int i=0;i<N;i++)
                {
                        scanf("%d",&v[i]);
                }
                printf("Case #%d: %d\n",rr,re(E,0));
        }
        //system("pause");
}
