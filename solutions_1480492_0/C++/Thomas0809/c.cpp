#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int T,n,num,num1,zt,maxzt,a[100],b[100];
bool h[100][1000],ok;
double s[100],p[100],c[100],t[3000],s1,s2,p1,p2;
char cc[10];

bool check(double t)
{
    num1=0;
    for (int i=1; i<=n; i++)
        if (b[i]==0)
            c[++num1]=p[i]+s[i]*t;
    sort(c+1,c+num1+1);
    for (int i=2; i<=num1; i++)
        if (c[i]-c[i-1]<5) return false;
    num1=0;
    for (int i=1; i<=n; i++)
        if (b[i]==1)
            c[++num1]=p[i]+s[i]*t;
    sort(c+1,c+num1+1);
    for (int i=2; i<=num1; i++)
        if (c[i]-c[i-1]<5) return false;
    num1=0;
    for (int i=1; i<=n; i++)
        if (a[i]!=b[i])
            c[++num1]=p[i]+s[i]*t;
    sort(c+1,c+num1+1);
    for (int i=2; i<=num1; i++)
        if (c[i]-c[i-1]<5) return false;
    return true;
}

int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    scanf("%d",&T);
    for (int tt=1; tt<=T; tt++)
    {
        scanf("%d",&n);
        printf("Case #%d: ",tt);
        zt=0; maxzt=(1<<n);
        for (int i=1; i<=n; i++)
        {
            scanf("%s%lf%lf",cc,&s[i],&p[i]);
            zt*=2;
            if (cc[0]=='R') zt++;
        }
        num=0;
        for (int i=1; i<=n; i++)
            for (int j=i+1; j<=n; j++)
                if (s[i]!=s[j])
                {
                    s1=s[i],p1=p[i],s2=s[j],p2=p[j];
                    if (p1>p2)
                    {
                        swap(p1,p2); swap(s1,s2);
                    }
                    if (p2<=p1+5.0)
                    {
                        if (s2>s1)
                        t[++num]=(p1+5.0-p2)/(s2-s1);    
                        else
                        t[++num]=(p2-p1+5.0)/(s1-s2);
                    }
                    else
                        if (s1>s2)
                        {
                        t[++num]=(p2-p1-5.0)/(s1-s2);
                        t[++num]=(p2+5.0-p1)/(s1-s2);
                        }
                }
        sort(t+1,t+num+1);
        t[num+1]=t[num]+1; num++;
        memset(h,false,sizeof h);
        h[0][zt]=true;
        for (int i=1; i<=num; i++)
        {
            ok=false;
            for (int j=0; j<maxzt; j++)
            if (h[i-1][j])
            for (int k=0; k<maxzt; k++)
            if (!h[i][k])
            {
                int x=j,y=k;
                for (int q=n; q>=1; q--)
                {
                    a[q]=x%2; x/=2;
                    b[q]=y%2; y/=2;
                }
                if (check(t[i]))
                {
                    h[i][k]=true;
                    ok=true;
                }
            }
            if (ok==false)
            {
                printf("%.6lf\n",t[i-1]);
                break;
            }
        }
        if (ok)
            printf("Possible\n");
    }
}
