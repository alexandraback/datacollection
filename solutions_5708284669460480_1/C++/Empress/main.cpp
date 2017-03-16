//#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<climits>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
#include<map>
#include<queue>
#define lson l, mid
#define rson (mid+1), r
#define pb push_back

const double eps=1e-8;
int dcmp(double x)
{
    if(fabs(x)<eps)
        return 0;
    if(x>0)
        return 1;
    return -1;
}
struct AC
{
    int ch[105][26],f[105];
    int len, sz;
    double dp[105][105],p[26];
    char str[105];
    char target[105];
    int idx(char c)
    {
        return c-'A';
    }
    void init()
    {
        memset(p,0,sizeof(p));
        memset(ch[0],0,sizeof(ch[0]));
        sz=1;
        scanf("%s",str);
        len=strlen(str);
        for(int i=0;i<len;i++)
            p[idx(str[i])]+=1.0/len;
    }
    void insert()
    {
        scanf("%s",target);
        len=strlen(target);
        int rt=0;
        for(int i=0;i<len;i ++)
        {
            int c=idx(target[i]);
            if(!ch[rt][c])
            {
                memset(ch[sz],0,sizeof(ch[sz]));
                ch[rt][c]=sz ++;
            }
            rt=ch[rt][c];
        }
    }
    void getfail()
    {
        queue<int> q;
        f[0]=0;
        for(int c=0;c<26;c ++)
        {
            int u=ch[0][c];
            if(u)
            {
                f[u]=0;
                q.push(u);
            }
            else
                f[u]=0;
        }
        while(!q.empty())
        {
            int r=q.front();
            q.pop();
            for(int c=0;c<26;c ++)
            {
                int u=ch[r][c];
                if(!u)
                {
                    ch[r][c]=ch[ f[r] ][c];
                    continue;
                }
                else
                {
                    f[u]=ch[ f[r] ][c];
                    q.push(u);
                }
            }
        }
    }
    double getans1(int s)
    {
        memset(dp,0,sizeof(dp));
        dp[0][0]=1.0;
        double res=0;
        for(int i=0;i<s;i ++)
        {
            for(int j=0;j<sz;j ++)
                for(int k=0;k<26;k ++)
                    dp[i + 1][ ch[j][k] ] += dp[i][j] * p[k];
            res += dp[i + 1][sz - 1];
        }
        return res;
    }
    double getans2(int l,int s)
    {
        for(int i=0;i<l;i ++)
            if(dcmp(p[ idx(target[i]) ])==0)
                return 0;
        return (s-l)/(l - f[sz - 1]) + 1;
    }
}AC;

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("out.out","w",stdout);
    int t, ca=1;
    scanf("%d", &t);
    while(t--)
    {
        int k, l, s;
        scanf("%d%d%d", &k, &l, &s);
        AC.init();
        AC.insert();
        AC.getfail();
        printf("Case #%d: ", ca++);
        double res=AC.getans2(l,s)-AC.getans1(s);
        printf("%.10f\n", res);
    }
    return 0;
}
