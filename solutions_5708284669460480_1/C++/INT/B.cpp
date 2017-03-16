#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<iostream>
using namespace std;

double a[26];
char s[110],t[110];
int p[110];

double f[110][110];
double g[110][110];
double v[110][110];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    for (int tt=1;tt<=T;tt++)
    {
        int n,m,q;
        scanf("%d%d%d",&m,&n,&q);
        memset(a,0,sizeof(a));
        scanf("%s",t);
        for (int i=0;i<m;i++)
            a[t[i]-'A']+=1.0/m;
        scanf("%s",s);
        p[0]=-1;
        int j=-1;
        for (int i=1;i<n;i++)
        {
            while (j>=0 && s[j+1]!=s[i]) j=p[j];
            if (s[j+1]==s[i]) j++;
            p[i]=j;
        }


        memset(f,0,sizeof(f));
        memset(v,0,sizeof(v));
        v[0][0]=1.0;
        for (int i=0;i<q;i++)
            for (int j=0;j<n;j++)
                for (int k=0;k<26;k++)
                    if (a[k]>1e-9 && v[i][j]>1e-9)
                    {
                        int u=j-1;
                        while (u>=0 && s[u+1]!='A'+k) u=p[u];
                        if (s[u+1]=='A'+k) u++;
                        int cnt=0;
                        if (u==n-1)
                        {
                            u=p[u];
                            cnt=1;
                        }
                        f[i+1][u+1]+=a[k]*(f[i][j]+cnt*v[i][j]);
                        v[i+1][u+1]+=a[k]*v[i][j];
                    }
        double mean=0;
        for (int j=0;j<=n;j++)
            mean+=f[q][j];

        //for (int i=0;i<=q;i++)
        //    for (int j=0;j<n;j++)
        //        printf("MEAN %d %d: %.7lf %.7lf\n",i,j,v[i][j],f[i][j]);

        memset(f,0,sizeof(f));
        memset(v,0,sizeof(v));
        v[0][0]=1.0;
        for (int i=0;i<q;i++)
            for (int j=0;j<n;j++)
                for (int k=0;k<26;k++)
                    if (a[k]>1e-9 && v[i][j]>1e-9)
                    {
                        int u=j-1;
                        while (u>=0 && s[u+1]!='A'+k) u=p[u];
                        if (s[u+1]=='A'+k) u++;
                        int cnt=0;
                        if (u==n-1)
                        {
                            u=p[u];
                            cnt=1;
                        }
                        f[i+1][u+1]=max(f[i+1][u+1],f[i][j]+cnt);
                        v[i+1][u+1]=1;
                    }
        double worst=0;
        for (int j=0;j<n;j++)
            worst=max(worst,f[q][j]);


        //for (int i=0;i<26;i++)
        //    printf("%d %.7lf\n",i,a[i]);

        //for (int i=0;i<=q;i++)
        //    for (int j=0;j<n;j++)
        //        printf("WORST %d %d: %.7lf %.7lf\n",i,j,v[i][j],f[i][j]);
        //printf("%.7lf %.7lf\n",worst,mean);
        printf("Case #%d: %.7lf\n",tt,worst-mean);
    }
    return 0;
}
