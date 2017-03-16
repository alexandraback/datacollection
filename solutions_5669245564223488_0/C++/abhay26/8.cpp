/* ***************************
Author: Abhay Mangal (abhay26)
*************************** */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <numeric>
#include <utility>
#include <bitset>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
 #define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define maX(a,b) (a) > (b) ? (a) : (b)
#define pii pair< int, int >
#define pip pair< int, pii >
#define FOR(i,n) for(int i=0; i<(int)n ;i++)
#define REP(i,a,n) for(int i=a;i<(int)n;i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
typedef long long ll;
//int dx[]= {-1,0,1,0};
//int dy[]= {0,1,0,-1};
int n;
string s[105];
ll dp[1<<11][11];
//int adj[105][105];
//int c[26];
ll calc(int mask, int last)
{
   // cout << mask << " " << last << endl;
    if(mask == (1<<n) - 1)
        return 1;
    ll &ret = dp[mask][last];
    if(ret != -1)
        return ret;
    ret = 0;
    int lc = s[last][s[last].length()-1]-'a';
    int c[26];
    FOR(i,26)
    c[i] = 0;
    FOR(i,n)
    {
       // cout << "LOL " << mask << " " << (1<<i) << endl;
        if((mask & (1<<i)) != 0)
        {
            string dup = s[i];
            FOR(k,dup.length())
            {
                c[dup[k]-'a'] = 1;
            }
        }
    }
   // FOR(i,5)
   // cout << c[i] << " ";
    //cout << endl;
    FOR(i,n)
    {
        if((mask & (1<<i)) != 0)
            continue;
        string dup = s[i];
        //if(mask == 12)
            //cout << "HHA " << dup << endl;
        int cur = 0;
        int flag = 1;
        FOR(k,dup.length())
        {
            if(cur == 0 && ((dup[k]-'a') == lc))
            {
                cur = 1;
            }
            else if(cur == 1 && ((dup[k]-'a') == lc))
            {
                cur = 1;
            }
            else if(cur == 1 && !c[dup[k]-'a'])
            {
                cur = 2;
            }
            else if(!c[dup[k]-'a'])
            {
                cur = 2;
            }
            else
            {
                /*if(mask == 12)
                {
                    cout << k << " " << dup[k] << " "  << c[dup[k]-'a'] << " " <<cur << " " << last << endl;
                }*/
                flag = 0;
                break;
            }
        }
       // if(mask == 12)
       // {
       //     cout << "LOL " << i << " " << flag << endl;
       // }
        if(flag)
        {
            ret = (ret + calc(mask|(1<<i),i))%MOD;
        }
    }
   // cout << mask << " " << last << " " << ret << endl;
    return ret;
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    FOR(Z,t)
    {
        memset(dp,-1,sizeof dp);
        scanf("%d",&n);
        int fail = 0;
        FOR(i,n)
        {
            cin >> s[i];
            string dup = s[i];
            string gen = "";
            gen = gen + dup[0];
            for(int k=1;k<dup.length();k++)
            {
                if(dup[k] != dup[k-1])
                    gen = gen + dup[k];
            }
            int cn[26];
            FOR(k,26)
            cn[k] = 0;
            for(int k=0;k<gen.length();k++)
                cn[gen[k]-'a']++;
            FOR(k,26)
            {
                if(cn[k] > 1)
                    fail = 1;
            }
        }
       /* FOR(i,n)
        {
            FOR(j,n)
            {
                if(i == j)
                    adj[i][j] == 0;
                for(int k=0;k<s[i].length();k++)
                {

                }
            }
        }*/
        ll ans = 0;
        if(fail)
            ans = 0;
        else
        {
            FOR(i,n)
            {
                ans = (ans+calc(0|(1<<i),i))%MOD;
            }
        }
        printf("Case #%d: %lld\n",Z+1,ans);
    }
return 0;
}
