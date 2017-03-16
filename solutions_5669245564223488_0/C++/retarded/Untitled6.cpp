/* HellGeek */
/* Shiva Bhalla */
/* iit2012077 */


#include<stdio.h>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<set>
#include<string>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<math.h>

#define LL long long
#define FIT(i,t) for(i=0;i<t;i++)
#define FIN(i,n) for(i=0;i<n;i++)
#define FJT(j,t) for(j=0;j<t;j++)
#define FJN(j,n) for(j=0;j<n;j++)
#define MAX2(a,b) a>b?a:b
#define MIN2(a,b) a>b?b:a
#define REP(i,a,b) for(i=a;i<=b;i++)

#define mod 1000000007



using namespace std;

LL narr[100005];

LL nikalo(int aa,int b)
{
    LL result=1;
    LL a=aa*1LL;
    while(b)
    {
        if(b&1)
            result=(result*1LL*a)%mod;
        a=(a*1LL*a)%mod;
        b=b/2;
    }
    return result;
}
LL inverse(int a)
{
    return nikalo(a,mod-2);
}

 
int arrrr[27][27],noun[27],visit[27],counter[27];
LL factoralla[108];
int fg;
LL dfs(int node)
{
    visit[node]=1;
 
    LL ret=factoralla[noun[node]];
    for(int j=0;j<27;j++)
    {
        if(arrrr[node][j])
        {
            if(visit[j]&&!counter[j])
                return 0;
            else
                ret=(ret*1LL*dfs(j))%mod;
        }
    }
    return ret;
}
 
 
int main()
{
    int m,t,i,j,k,l,n;
    int tt;
    freopen("alpha1.in","w",stdout);
    //freopen("b.out","w",stdout);
 
    cin >> t;
    factoralla[0]=1LL;
    tt=1;
    for(i=1;i<=100;i++)
    {
        factoralla[i]=(factoralla[i-1]*1LL*i)%mod;
    }
    while(t--)
    {
 
        memset(arrrr,0,sizeof(arrrr));
        memset(noun,0,sizeof(noun));
        cin >> n;
        fg=1;
        string s[n+9];
        int indeg[27];
 
        memset(indeg,0,sizeof(indeg));
        memset(visit,0,sizeof(visit));
        map<int,int>ma;
        ma.clear();
        for(i=0;i<n;i++)
        {
            cin>>s[i];
            int st=s[i][0]-'a';
            int gg=0;
            ma[st]=1;
            for(j=1;j<s[i].length();j++)
            {
                int val=s[i][j]-'a';
                if(val==st)
                    continue;
                gg=1;
                arrrr[st][val]++;
                indeg[val]++;
                if(arrrr[st][val]>1)
                    fg=0;
                st=val;
            }
            if(!gg)
                noun[st]++;
        }
 
        for(i=0;i<26;i++)
        {
            int c=0;
            for(j=0;j<26;j++)
            {
                if(i==j)
                    continue;
                if(arrrr[i][j])
                    c++;
            }
            if(c>1)
                fg=0;
        }
 
        for(i=0;i<26;i++)
        {
            int c=0;
            for(j=0;j<26;j++)
            {
                if(arrrr[i][j])
                    c++;
            }
            int g=0;
            if(c!=0&&indeg[i]>1)
                g=1;
 
            if(noun[i]&&g)
            fg=0;
        }
        
        cout<<"Case #"<<tt++<<": ";
 
        memset(counter,0,sizeof(counter));
        
        if(!fg)
            cout<<"0\n";
        else
        {
            LL result=1LL;
            int c=0;
            for(i=0;i<26;i++)
            {
                if(visit[i]||indeg[i])
                   continue;
 
                if(!ma[i])
                    continue;
                LL zo=dfs(i);
                result=(result*1LL*zo)%mod;
                c++;
            }
           
            result=(result*1LL*factoralla[c])%mod;
            cout<<result<<"\n";
        }
    }
    return 0;
}
