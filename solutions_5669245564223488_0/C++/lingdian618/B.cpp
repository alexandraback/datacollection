#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 111;
const int L = 111;
const LL mod = 1000000007;
char s[N][L];
int cnt[N];
int start[N], stop[N], mid[N];
int next[N];
int used[N];
bool judge(int k)
{
    int i=0, j;
    while(s[k][i])
    {
        for(j=i+1; s[k][j]; j++)
        {
            if(s[k][j]!=s[k][i])    break;
        }
        int t = cnt[s[k][i]-'a'];
        if(i!=0 && s[k][j] && j-i!=t)   return 0;
        i = j;
    }
    return 1;
}
void update(LL &ans, int k)
{
    for(int i=1; i<=k; i++)
    {
        ans *= i;
        ans %= mod;
    }
}
int main()
{
//    freopen("B-small-attempt0.in", "r", stdin);
//    freopen("B-small-attempt0.out", "w", stdout);
    int t, kase=0;
    int n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        for(int i=0; i<n; i++)
        {
            scanf("%s", s[i]);
            for(int j=0; s[i][j]; j++)
            {
                cnt[s[i][j]-'a']++;
            }
        }
        printf("Case #%d: ", ++kase);
        int yes = 1;
        for(int i=0; i<n; i++)  yes &= judge(i);
        if(0==yes)
        {
            printf("0\n");
            continue;
        }
        memset(next, -1, sizeof(next));
        memset(start, 0, sizeof(start));
        memset(stop, 0, sizeof(stop));
        memset(mid, 0, sizeof(mid));
        memset(used, 0, sizeof(used));
        for(int i=0; i<n; i++)
        {
            int k = strlen(s[i]);
            if(s[i][0]==s[i][k-1])
            {
                mid[s[i][0]-'a']++;
            }
            else
            {
                int a = s[i][0]-'a';
                int b = s[i][k-1]-'a';
                start[a]++;
                stop[b]++;
                next[a] = b;
            }
        }
        for(int i=0; i<26; i++)
        {
            yes &= start[i]<=1;
            yes &= stop[i]<=1;
        }
        if(0==yes)
        {
            printf("0\n");
            continue;
        }
        int chains = 0;
        LL ans = 1;
        for(int i=0; i<26; i++)
        {
            if(start[i]-stop[i]==1)
            {
                chains++;
                int a = i;
                while(-1^a)
                {
                    update(ans, mid[a]);
                    used[a]++;
                    a = next[a];
                }
            }
        }
        for(int i=0; i<26; i++)
        {
            if(used[i]==0 && mid[i])
            {
                update(ans, mid[i]);
                used[i]++;
                chains++;
            }
        }
        if(0==chains)
        {
            printf("0\n");
            continue;
        }
        update(ans, chains);
        cout<<ans<<endl;
    }
    return 0;
}
