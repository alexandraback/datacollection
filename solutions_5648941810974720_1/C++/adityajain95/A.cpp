#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f first
#define s second
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define CLR(x)  memset(x,0,sizeof(x))
#define RESET(x,a) memset(x,a,sizeof(x))
#define pi pair<int,int>
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<">value ("<<#x<<") : "<<x<<endl;

int cnt[30];
char s[2500];
int dig[20];

int main()
{
    freopen("1.in","r",stdin);
    freopen("A-out.txt","w",stdout);
    int tt,t,j,n,m,i;
    si(tt);
    for(t=1;t<=tt;t++)
    {
        scanf("%s",s);
        CLR(cnt);
        CLR(dig);
        n=strlen(s);
        for(i=0;i<n;i++)
        {
            cnt[s[i]-'A']++;
        }
        if(cnt['Z'-'A'])
        {
            dig[0]=cnt['Z'-'A'];
            cnt['E'-'A']-=cnt['Z'-'A'];
            cnt['R'-'A']-=cnt['Z'-'A'];
            cnt['O'-'A']-=cnt['Z'-'A'];
            cnt['Z'-'A']=0;
        }
        if(cnt['W'-'A'])
        {
            dig[2]=cnt['W'-'A'];
            cnt['T'-'A']-=cnt['W'-'A'];
            cnt['O'-'A']-=cnt['W'-'A'];
            cnt['W'-'A']=0;
        }
        if(cnt['X'-'A'])
        {
            dig[6]=cnt['X'-'A'];
            cnt['S'-'A']-=cnt['X'-'A'];
            cnt['I'-'A']-=cnt['X'-'A'];
            cnt['X'-'A']=0;
        }
        if(cnt['U'-'A'])
        {
            dig[4]=cnt['U'-'A'];
            cnt['F'-'A']-=cnt['U'-'A'];
            cnt['O'-'A']-=cnt['U'-'A'];
            cnt['R'-'A']-=cnt['U'-'A'];
            cnt['U'-'A']=0;
        }
        if(cnt['R'-'A'])
        {
            dig[3]=cnt['R'-'A'];
            cnt['T'-'A']-=cnt['R'-'A'];
            cnt['H'-'A']-=cnt['R'-'A'];
            cnt['E'-'A']-=cnt['R'-'A'];
            cnt['E'-'A']-=cnt['R'-'A'];
            cnt['R'-'A']=0;
        }
        if(cnt['F'-'A'])
        {
            dig[5]=cnt['F'-'A'];
            cnt['I'-'A']-=cnt['F'-'A'];
            cnt['V'-'A']-=cnt['F'-'A'];
            cnt['E'-'A']-=cnt['F'-'A'];
            cnt['F'-'A']=0;
        }
        if(cnt['V'-'A'])
        {
            dig[7]=cnt['V'-'A'];
            cnt['S'-'A']-=cnt['V'-'A'];
            cnt['E'-'A']-=cnt['V'-'A'];
            cnt['E'-'A']-=cnt['V'-'A'];
            cnt['N'-'A']-=cnt['V'-'A'];
            cnt['V'-'A']=0;
        }
        if(cnt['G'-'A'])
        {
            dig[8]=cnt['G'-'A'];
            cnt['E'-'A']-=cnt['G'-'A'];
            cnt['I'-'A']-=cnt['G'-'A'];
            cnt['H'-'A']-=cnt['G'-'A'];
            cnt['T'-'A']-=cnt['G'-'A'];
            cnt['G'-'A']=0;
        }
        if(cnt['O'-'A'])
        {
            dig[1]=cnt['O'-'A'];
            cnt['N'-'A']-=cnt['O'-'A'];
            cnt['E'-'A']-=cnt['O'-'A'];
            cnt['O'-'A']=0;
        }
        if(cnt['I'-'A'])
        {
            dig[9]=cnt['I'-'A'];
            cnt['N'-'A']-=cnt['I'-'A'];
            cnt['N'-'A']-=cnt['I'-'A'];
            cnt['E'-'A']-=cnt['I'-'A'];
            cnt['I'-'A']=0;
        }
        for(i=0;i<30;i++)
        {
            if(cnt[i])
            {
                cerr<<i<<": "<<cnt[i]<<endl;
            }
        }
        printf("Case #%d: ",t);
        for(i=0;i<10;i++)
        {
            if(dig[i])
            {
                for(int j=0;j<dig[i];j++)
                    printf("%d",i);
            }
        }
        printf("\n");
    }
    return 0;
}
