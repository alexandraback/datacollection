#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
double a[26][10],b[26][10],x[26];
char in[2005];
void init()
{
    b['Z'-'A'][0]=1;b['E'-'A'][0]=1;b['R'-'A'][0]=1;b['O'-'A'][0]=1;
    b['O'-'A'][1]=1;b['N'-'A'][1]=1;b['E'-'A'][1]=1;
    b['T'-'A'][2]=1;b['W'-'A'][2]=1;b['O'-'A'][2]=1;
    b['T'-'A'][3]=1;b['H'-'A'][3]=1;b['R'-'A'][3]=1;b['E'-'A'][3]=2;
    b['F'-'A'][4]=1;b['O'-'A'][4]=1;b['U'-'A'][4]=1;b['R'-'A'][4]=1;
    b['F'-'A'][5]=1;b['I'-'A'][5]=1;b['V'-'A'][5]=1;b['E'-'A'][5]=1;
    b['S'-'A'][6]=1;b['I'-'A'][6]=1;b['X'-'A'][6]=1;
    b['S'-'A'][7]=1;b['E'-'A'][7]=2;b['V'-'A'][7]=1;b['N'-'A'][7]=1;
    b['E'-'A'][8]=1;b['I'-'A'][8]=1;b['G'-'A'][8]=1;b['H'-'A'][8]=1;b['T'-'A'][8]=1;
    b['N'-'A'][9]=2;b['I'-'A'][9]=1;b['E'-'A'][9]=1;
}
void gauss()
{
    int i,j,u,v;
    for(u=0,v=0;u<26&&v<10;++u,++v)
    {
        j=u;
        for(i=u+1;i<26;++i)
            if(fabs(a[i][v])>fabs(a[j][v]))
                j=i;
        if(fabs(a[j][v])<1e-8)
        {
            --u;
            continue;
        }
        if(j!=u)
        {
            for(i=v;i<10;++i)
                swap(a[j][i],a[u][i]);
            swap(x[j],x[u]);
        }
        for(i=u+1;i<26;++i)
        {
            if(!a[i][v])continue;
            double tmp=a[i][v]/a[u][v];
            for(j=v+1;j<10;++j)
                a[i][j]-=tmp*a[u][j];
            a[i][v]=0;
            x[i]-=tmp*x[u];
        }
    }
    for(u=9;u>=0;--u)
    {
        for(v=u+1;v<10;++v)
            x[u]-=a[u][v]*x[v];
        x[u]/=a[u][u];
    }
}
int main()
{
    int T;
    init();
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
    {
        scanf(" %s",in);
        memset(x,0,sizeof(x));
        for(char*p=in;*p;++p)
            ++x[*p-'A'];
        memcpy(a,b,sizeof(b));
        gauss();
        printf("Case #%d: ",i);
        int j,k,tt;
        for(j=0;j<10;++j)
        {
            for(k=1,tt=round(x[j]);k<=tt;++k)
                putchar(j+'0');
        }
        putchar('\n');
    }
    return 0;
}
