#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;

typedef vector<string> Svector;

Svector input;

int n;
static const ll MD = 1000000007ll;

enum TYP
{
    BEGIN, MID, END, ALL
};

static const int MXC = 128;
char cnt[4][MXC];

static void EQMUL(ll& a, ll k)
{
    a *= k;
    a %= MD;
}

ll gfac(ll i)
{
    ll ans = 1;
    while (i) {
        EQMUL(ans, i);
        i--;
    }
    return ans;
}

ll solve0()
{
    vector<int> v1(n);
    for (int i=0; i<n; i++)v1[i] = i;
    
    ll ans = 0;
    do 
    {
        char vis[128]={0};
        char lc = '?';
        int good = 1;
        for (int i=0; i<n; i++) {
            string& str = input[v1[i]];
            
            for (int j=0; j<str.size(); j++) {
                if (str[j] != lc) {
                    if (vis[str[j]])good = 0;
                    lc = str[j];
                    vis[lc] = 1;
                }
            }
        }
        ans+=good;
        if (ans > MD) ans -= MD;
    } while (next_permutation(v1.begin(), v1.end()));
    return ans;
}

char edge[MXC][MXC];
int vis[MXC];

static bool dfs(int v)
{
   // printf("vis %c\n", v);
    if (vis[v] == 1)return true;
    else if (vis[v] == 2) return false;
    
    vis[v] = 1;
    for (int i=0; i<MXC; i++) {
        if (edge[v][i]) {
            if (dfs(i))return true;
        }
    }
    vis[v] = 2;
    return false;
}


static bool Floops()
{
    memset(vis, 0, sizeof(vis));
    for (int i=0; i<MXC; i++) {
        if (dfs(i))return true;
    }
    return false;
}

ll solve()
{
    memset(cnt, 0, sizeof(cnt));
    for (int i=0; i<n; i++)
    {
        bool all = true;
        for(int j=1; j<input[i].size(); j++) {
            if (input[i][j] != input[i][j-1])all = false;
        }
        if (all)
        {
            cnt[ALL][input[i][0]]++;
        }
        else
        {
            cnt[BEGIN][input[i][0]]++;
            for(int j=1; j<input[i].size(); j++) {
                if (input[i][j] != input[i][j-1]) {
                    cnt[MID][input[i][j]]++;
                }
            }
            int l = input[i].size();
            cnt[MID][input[i][l-1]]--;
            cnt[END][input[i][l-1]]++;
            if (input[i][0] == input[i][l-1])return 0;
        }
    }
    ll ans = 1;
    ll blocks=0;
    for (int c=0; c<MXC; c++)
    {
        if (cnt[MID][c] > 1 || 
            (cnt[MID][c] == 1 && (cnt[BEGIN][c]+cnt[END][c]+cnt[ALL][c]>0)))
            return 0;
        if (cnt[MID][c])continue;
        if (cnt[BEGIN][c] > 1 || cnt[END][c] > 1 ) return 0;
        EQMUL(ans, gfac(cnt[ALL][c]));
        if (cnt[BEGIN][c] + cnt[END][c]+cnt[ALL][c] == 0)continue;
        blocks += 2 - cnt[BEGIN][c] - cnt[END][c];
        //printf("%c -> %d %d %d\n", c, cnt[BEGIN][c] , cnt[END][c], cnt[ALL][c]);
    }
    blocks /= 2;
    memset(edge, 0, sizeof(edge));
    for (int i=0; i<n; i++)
    {
        for (int j=1; j<input[i].size(); j++)
        {
            if (input[i][j-1] != input[i][j])
            {
                edge[input[i][j-1]][input[i][j]]=1;
            }
        }
    }
    if (Floops()) return 0;
   // cout << "blocks " << blocks << endl;
    EQMUL(ans, gfac(blocks));
    return ans;
}

int main()
{
    int t;
    cin >> t;
    for (int i=1; i<=t; i++)
    {
        cin >> n;
        input = Svector(n);
        for (int j=0; j<n; j++)
        {
            cin >> input[j];
        }    
        
        //if (solve() != solve0() ) cout << " !!! " << i << endl;
        cout << "Case #" << i << ": " << solve() << endl;
    }
}
