#include<bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define ll long long
#define mod 1000000007
#define bitcount    __builtin_popcountll
#define pb push_back
int main()
{
    freopen("codejamdigitsin.txt","r",stdin);
    freopen("codejamdigitsout.txt","w",stdout);
    int t,n,i,j,k,a[12],b[30],x;
    char s[2002];
    sd(t);
    for(x=1;x<=t;x++)
    {
        for(i=0;i<=9;i++)
            a[i]=0;
        for(i=0;i<26;i++)
            b[i]=0;
        ss(s);
        n=strlen(s);
        for(i=0;i<n;i++)
            b[s[i]-'A']++;
        if(b[25]>0)
        {
            a[0]+=b[25];
            b['E'-'A']-=b[25];
            b['R'-'A']-=b[25];
            b['O'-'A']-=b[25];
            b[25]=0;
        }
        if(b['W'-'A']>0)
        {
            a[2]+=b['W'-'A'];
            b['T'-'A']-=b['W'-'A'];
            b['O'-'A']-=b['W'-'A'];
            b['W'-'A']=0;
        }
        if(b['U'-'A']>0)
        {
            a[4]+=b['U'-'A'];
            b['O'-'A']-=b['U'-'A'];
            b['F'-'A']-=b['U'-'A'];
            b['R'-'A']-=b['U'-'A'];
            b['U'-'A']=0;
        }
        if(b['F'-'A']>0)
        {
            a[5]+=b['F'-'A'];
            b['V'-'A']-=b['F'-'A'];
            b['I'-'A']-=b['F'-'A'];
            b['E'-'A']-=b['F'-'A'];
            b['F'-'A']=0;
        }
        if(b['X'-'A']>0)
        {
            i='X'-'A';
            a[6]+=b[i];
            b['S'-'A']-=b[i];
            b['I'-'A']-=b[i];
            b[i]=0;
        }
        if(b['S'-'A']>0)
        {
            i='S'-'A';
            a[7]+=b[i];
            b['E'-'A']-=b[i];
            b['V'-'A']-=b[i];
            b['E'-'A']-=b[i];
            b['N'-'A']-=b[i];
            b[i]=0;
        }
        if(b['G'-'A']>0)
        {
            i='G'-'A';
            a[8]+=b[i];
            b['E'-'A']-=b[i];
            b['I'-'A']-=b[i];
            b['H'-'A']-=b[i];
            b['T'-'A']-=b[i];
            b[i]=0;
        }
        if(b['I'-'A']>0)
        {
            i='I'-'A';
            a[9]+=b[i];
            b['N'-'A']-=b[i];
            b['N'-'A']-=b[i];
            b['E'-'A']-=b[i];
            b[i]=0;
        }
        if(b['O'-'A']>0)
        {
            i='O'-'A';
            a[1]+=b[i];
            b['N'-'A']-=b[i];
            b['E'-'A']-=b[i];
            b[i]=0;
        }
        if(b['T'-'A']>0)
        {
            i='T'-'A';
            a[3]+=b[i];
        }
        printf("Case #%d: ",x);
        for(i=0;i<=9;i++)
        {
            for(j=0;j<a[i];j++)
                printf("%d",i);
        }
        printf("\n");
    }
    return 0;
}
