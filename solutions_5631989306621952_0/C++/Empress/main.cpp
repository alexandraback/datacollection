#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> PI;
typedef pair<PI, PI > PII;
const double eps=1e-5;
const int inf=1e5;
const double pi=acos(-1.0);
const int N=1e6+5;

char s[1005];
int len;
vector<int> pos;
//vector<string> ans;
int dp[2005][30];
bool vis[1005];
void init()
{
    memset(dp, -1, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    for(int i=1; i<=len; i++)
    {
        for(int j=0; j<26; j++)
            dp[i][j]=dp[i-1][j];
        dp[i][s[i]-'A']=i;
    }
}
string dfs(int l, int r)
{
    string ans="";
    for(int i=r; i>=l; i--)
    {
        char maxn=s[i];
        if(i>1)
        {
            for(char j='Z'; j>='A'; j--)
                if(dp[i-1][j-'A']!=-1)
                {
                    maxn=max(maxn, j);
                    break;
                }
        }
        if(maxn==s[i])
            ans+=s[i], vis[i]=1;
    }
    for(int i=1;i<=len;i++)
        if(!vis[i])
            ans+=s[i];
    return ans;
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int t, ca=1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", s+1);
        len=strlen(s+1);
        printf("Case #%d: ", ca++);
        init();
        string ans=dfs(1, len);
        cout<<ans<<endl;
    }
    return 0;
}
