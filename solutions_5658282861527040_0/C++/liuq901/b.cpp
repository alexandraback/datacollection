#include <cstdio>
#include <cstring>
typedef long long ll;
ll f[40][2][2][2];
int a[40],b[40],c[40];
void get(int n,int a[])
{
    for (int i=35;i;i--)
    {
        a[i]=n&1;
        n>>=1;
    }
}
int get(int a[],int len,int state,int value)
{
    if (state==0)
        return(0);
    return(a[len]<value?-1:a[len]==value?1:0);
}
void get(int len,int u,int v,int w,int p,int q,int &x,int &y,int &z)
{
    x=get(a,len,u,p);
    y=get(b,len,v,q);
    z=get(c,len,w,p&q);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int A,B,C;
        scanf("%d%d%d",&A,&B,&C);
        A--,B--,C--;
        get(A,a);
        get(B,b);
        get(C,c);
        memset(f,0,sizeof(f));
        f[0][1][1][1]=1;
        for (int i=0;i<35;i++)
            for (int j=0;j<2;j++)
                for (int k=0;k<2;k++)
                    for (int l=0;l<2;l++)
                        for (int p=0;p<2;p++)
                            for (int q=0;q<2;q++)
                            {
                                int x,y,z;
                                get(i+1,j,k,l,p,q,x,y,z);
                                if (x==-1 || y==-1 || z==-1)
                                    continue;
                                f[i+1][x][y][z]+=f[i][j][k][l];
                            }
        ll ans=0;
        for (int i=0;i<2;i++)
            for (int j=0;j<2;j++)
                for (int k=0;k<2;k++)
                    ans+=f[35][i][j][k];
        static int id=0;
        printf("Case #%d: %lld\n",++id,ans);
    }
    return(0);
}

