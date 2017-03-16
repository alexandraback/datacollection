#include<bits/stdc++.h>
#define MAXN 155
#define PI acos(-1.0)
#define MOD 1000000007
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,s,t) for(int i=s; i<=t; i++)
#define mem(a,b)  memset(a,b,sizeof(a))
#define show(x) { cerr<<">>>"<<#x<<" = "<<x<<endl; }
#define show2(x,y) { cerr<<">>>"<<#x<<"="<<x<<"  "<<#y<<" = "<<y<<endl; }
using namespace std;

int N;
char str[MAXN][MAXN];
int same[MAXN];
vector<int> G[MAXN];
vector<int> rG[MAXN];
bool used[MAXN];
bool have[MAXN];
bool alone[MAXN];
bool ansok;
long long ans;
long long fact[MAXN];
long long C[MAXN][MAXN];

void Judge_input()
{
    for(int i=0; i<N; i++)
    {
        int len = strlen(str[i]);
        for(int j=0; j<len; j++)
            have[str[i][j]] = true;

        if(len == 1)
        {
            same[str[i][0]] ++;
            continue;
        }

        if(str[i][0] == str[i][len-1])
        {
            if(len > 2)
            {
                ansok = false;
                return;
            }
            same[str[i][0]] ++;
        }
        else
        {
            G[str[i][0]].push_back(str[i][len-1]);
            rG[str[i][len-1]].push_back(str[i][0]);
        }

        bool ok[30] = {0};
        for(int j=1; j<len-1; j++)
        {
            char ch = str[i][j];
            if(ok[ch] && j>1 && str[i][j-1] != ch)
            {
                ansok = false;
                return;
            }
            ok[ch] = true;
        }

        for(int h=1; h<len-1; h++)
        {
            for(int j=0; j<N; j++) if(i != j)
            {
                for(int k=0,l=strlen(str[j]); k<l; k++)
                {
                    if(str[j][k] == str[i][h])
                    { //show2(j, k); show2(i,h);
                        ansok = false;
                        return;
                    }
                }
            }
        }
    }
}

void dfs(char ch)
{
    used[ch] = true;
    if(G[ch].size() == 1 && !used[ch])
    {
        char next = G[ch][0];
        dfs(next);
    }
}

void factrial()
{
    fact[0] = 1;
    for(int i=1; i<100; i++)
        fact[i] = fact[i-1]*i%MOD;
}

void solve()
{
    for(int i=0; i<26; i++)
        if(G[i+'a'].size() > 1 || rG[i+'a'].size() > 1)
        {
            ansok = false;
            return;
        }
    //统计不同块的个数;
    int linknum = 0;
   // for(int i=0; i<26; i++) show(have[i+'a']);
    for(int i=0; i<26; i++) if(have[i+'a'])
    {
        if(used[i+'a']) continue;
        linknum++;
        if(G[i+'a'].size() == 1)
        {
            linknum++;
            dfs(i+'a');
        }
        else
        {
            alone[i+'a'] = true;
        }
    } show(linknum);

    ans = 1;
    ans = fact[linknum];

    for(int i=0; i<26; i++) if(have[i+'a'])
    {
        if(!alone[i+'a'])
        {
            ans = (ans*fact[same[i+'a']])%MOD;
        }
        else
        {
            ans = (ans*fact[linknum])%MOD;
            ans = (ans*fact[same[i+'a']])%MOD;
        }
    }
}

int main()
{
    freopen("E:\\acm\\input.txt","r",stdin);
    //freopen("E:\\acm\\output.txt","w",stdout);
    int T; cin>>T;
    for(int cas=1; cas<=T; cas++)
    {
        printf("Case #%d: ",cas);
        cin>>N;
        ansok = true;
        memset(used, 0, sizeof(used));
        memset(have, 0, sizeof(have));
        memset(same, 0, sizeof(same));
        memset(alone, 0, sizeof(alone));
        memset(G, 0, sizeof(G));
        memset(rG, 0, sizeof(rG));
        for(int i=0; i<N; i++)
            cin>>str[i];
        Judge_input();
        if(ansok)
        {
            printf("0\n");
            continue;
        }
        solve();
        if(ansok)
        {
            printf("0\n");
            continue;
        }
        cout<<ans<<endl;
    }
}












