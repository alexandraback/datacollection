#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 28;
const int maxL = 105;
const ll MOD = 1000000007;
int vis[maxn],single[maxn],has[maxn][maxn],cy[maxn];
ll f[maxL];
void init()
{
    f[0]=1;
    for(int i=1;i<maxL;i++) f[i]=(f[i-1]*i)%MOD;
}
bool deal(char s[])
{
    int len=strlen(s);
    char st=s[0],ed=s[len-1];
    int i=0,j=len-1;
    while(i<len && s[i]==st) i++;
    while(j>=0 && s[j]==ed) j--;
    if(vis[st-'a'] || vis[ed-'a']) return false;
    //single char
    if(i>=len)
    {
        single[st-'a']++;
        has[st-'a'][st-'a']=1;
        return true;
    }
    //two chars
    for(int k=i;k<=j;k++)
    {
        if(vis[s[k]-'a']) return false;
        char tmp=s[k];
        while(k<=j&&s[k]==tmp) k++;
        k--;
        vis[s[k]-'a']++;
    }
    if(ed==st || has[ed-'a'][st-'a'])
        return false;
    has[st-'a'][ed-'a']=1;
    return true;
}
bool hasCycle(int x,int y)
{
    if(cy[y]) return x!=y;
    for(int i=0;i<maxn;i++) if(has[y][i])
    {
        cy[x]=cy[y]=1;
        return hasCycle(y,i);
    }
    return false;
}
void recycle(int x,int y)
{
    has[x][y]=0;
    for(int i=0;i<maxn;i++) if(has[i][x])
        recycle(i,x);
}
void cycle(int x,int y)
{
    has[x][y]=0;
    for(int i=0;i<maxn;i++) if(has[y][i])
        cycle(y,i);
}
int main()
{
    char s[maxL];
    int T,n,ncase=0;
    cin>>T;
    init();
    while(T--){
        cin>>n;
        memset(vis,0,sizeof(vis));
        memset(single,0,sizeof(vis));
        memset(has,0,sizeof(has));
        bool flag = true;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            if(!flag) continue;
            flag = deal(s);
        }
        ll ans=1;
        int cnt=0;
        for(int i=0;i<maxn;i++)
        {
            ans=(ans*f[single[i]])%MOD;
            //cnt+=((single[i]>0)?1:0);
        }
        for(int i=0;i<maxn&&flag;i++) for(int j=0;j<maxn&&flag;j++)
        {
            if(has[i][j])
            {
                memset(cy,0,sizeof(cy));
                if(hasCycle(i,j))
                {
                    int cc=0;
                    for(int xx=0;xx<maxn;xx++)
                    {
                        if(cy[xx]) cc++;
                        //cout<<xx<<":"<<cy[xx]<<endl;
                    }
                    if(cc>1)
                    {
                        //cout<<"cyc: "<<i<<j<<endl;
                        flag=false;
                        continue;
                    }
                }
                recycle(i,j);
                cycle(i,j);
                cnt++;
            }
        }
        ans=(ans*f[cnt])%MOD;
        if(!flag) printf("Case #%d: 0\n",++ncase);
        else
        {
            printf("Case #%d: ",++ncase);
            cout<<ans<<endl;
        }
    }
    return 0;
}
/*
5
3
ab bbbc cd
4
aa aa bc c
2
abc bcd
1
aba
2
ab ba
*/
