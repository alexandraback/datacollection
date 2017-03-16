#include <cstdio>
using namespace std;
int x[6],nrt,l,i,ii,iii,numar,a[2000][3],mat[12][12][12],js[12][12],jp[12][12],ps[12][12],k,ok,j,s,p,nr;
int valid(int k)
{
    if(x[1]>j)return 0;
    if(k>=2&&x[2]>p)return 0;
    if(k>=3&&x[3]>s)return 0;
    if(k>=2)
    {
        if(jp[x[1]][x[2]]>=nr)return 0;
    }
    if(k>=3)
    {
        if(js[x[1]][x[3]]>=nr)return 0;
        if(ps[x[2]][x[3]]>=nr)return 0;
    }
    return 1;
}
int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    scanf("%d",&nrt);
    for(l=1;l<=nrt;l++)
    {
        scanf("%d%d%d%d",&j,&p,&s,&nr);
        printf("Case #%d: ",l);
        for(i=1;i<=numar;i++)
            a[i][1]=a[i][2]=a[i][3]=0;
        numar=0;
        for(i=1;i<=10;i++)
        {
            for(ii=1;ii<=10;ii++)
            {
                for(iii=1;iii<=10;iii++)
                    mat[i][ii][iii]=0;
                jp[i][ii]=js[i][ii]=ps[i][ii]=0;
            }
        }
        k=1;
        x[k]=0;
        while(k>0)
        {
            ok=0;
            while(ok==0&&x[k]<s&&k<=3)
            {
                x[k]++;
                if(valid(k))ok=1;
            }
            if(ok==1)
            {
                if(k==3)
                {
                    if(mat[x[1]][x[2]][x[3]]==0)
                    {
                        mat[x[1]][x[2]][x[3]]=1;
                        jp[x[1]][x[2]]++;
                        js[x[1]][x[3]]++;
                        ps[x[2]][x[3]]++;
                        numar++;
                        a[numar][1]=x[1];
                        a[numar][2]=x[2];
                        a[numar][3]=x[3];
                    }
                }
                else {k++;x[k]=0;}
            }
            else k--;
        }
        printf("%d\n",numar);
        for(i=1;i<=numar;i++)
            printf("%d %d %d\n",a[i][1],a[i][2],a[i][3]);
    }

return 0;
}
