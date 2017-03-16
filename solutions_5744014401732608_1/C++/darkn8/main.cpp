#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    FILE *ptrin,*ptrout;
    ptrin=fopen("C:\\Users\\debrup\\Desktop\\in.txt","r");
    ptrout=fopen("C:\\Users\\debrup\\Desktop\\out.txt","w");
    int t,T,i,j,b,p;
    ll m,pwr[55];
    for(i=pwr[0]=1;i<=50;i++)
        pwr[i]=2*pwr[i-1];
    fscanf(ptrin,"%d",&T);
    for(t=1;t<=T;t++)
    {
        fscanf(ptrin,"%d%lld",&b,&m);
        int adj[50][50]={};
        if(m>pwr[b-2])
            fprintf(ptrout,"Case #%d: IMPOSSIBLE\n",t);
        else
        {
            fprintf(ptrout,"Case #%d: POSSIBLE\n",t);
            for(i=1;i<b;i++)
                for(j=i+1;j<b;j++)
                    adj[i][j]=1;
            adj[1][b]=1;
            m--;
            while(m)
            {
                p=upper_bound(pwr,pwr+50,m)-1-pwr;
                adj[p+2][b]=1;
                m-=pwr[p];
            }
            for(i=1;i<=b;i++)
            {
                for(j=1;j<=b;j++)
                    fprintf(ptrout,"%d",adj[i][j]);
                fprintf(ptrout,"\n");
            }
        }
    }
    fclose(ptrin);
    fclose(ptrout);
    return 0;
}
