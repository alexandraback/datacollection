#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#define mod 1000000007
using namespace std;


int t;
int n;
string s[110];
int nxt[110];
int ans;
int gao()
{
    int li,lj;
    int pans=0;
    for(int i=1;i<=n;++i)
    {
        li=(int)s[i].length();
        for(int j=i+1;j<=n;++j)
        {
            lj=(int)s[j].length();
            if(s[i][li-1]==s[j][0])
            {
                if(nxt[i])return 0;
                nxt[i]=j;
            }
            if(s[j][lj-1]==s[i][0])
            {
                if(nxt[j])return 0;
                nxt[j]=i;
            }
        }
    }
}
bool ok()
{
    int tm[30];
    int x;
    memset(tm,0,sizeof(tm));
    int l=(int)s[0].length();
    tm[s[0][0]-'a'+1]=1;
    for(int i=1;i<l;++i)
    {
        if(s[0][i]!=s[0][i-1])
        {
            x=s[0][i]-'a'+1;
            if(tm[x])return false;
            tm[x]++;
        }
    }
    return true;
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&t);
    int __=0;
    while(t--){

        scanf("%d",&n);
        //getchar();
        for(int i=1;i<=n;++i)
            cin>>s[i];
        //memset(nxt,0,sizeof(nxt));
        //ans=gao();
        ans=0;
        for(int i=1;i<=n;++i)nxt[i]=i;
        do
        {
            s[0]="";
            for(int i=1;i<=n;++i)
                s[0]+=s[nxt[i]];
            if(ok()){ans++;ans%=mod;}
        }while(next_permutation(nxt+1,nxt+n+1));
        printf("Case #%d: %d\n",++__,ans);

    }
    return 0;
}
