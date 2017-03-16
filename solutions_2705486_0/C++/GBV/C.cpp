#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <list>
#include <set>
#include <ctime>
#include <list>
#include <fstream>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define vi vector<int>
#define vd vector<double>
#define pii pair<int,int>
#define pdd pair<double,double>
#define ll long long
#define INF (1<<30)
using namespace std;

vector<string> W[12];
int maxl;
const int MAXN = 64;
int DP[MAXN][MAXN], N;
string cs;

void read_dict()
{
    ifstream in("dict.txt");
    string s;
    while(in >> s)
    {
        W[(int)s.length()].pb(s);
        maxl = max(maxl, (int) s.length());
    }
    in.close();
}

int opt[16][16];
bool fn(string sub)
{
    int i, j, len = sub.length(), best = INF;
    int res = false;
    for(i = 0; i < len; ++i)
        for(j = 0; j < len; ++j) opt[i][j] = INF;
    vector<int> cr;
    for(i = 0; i < W[len].size(); ++i)
    {
        cr.clear();
        for(j = 0; j < len; ++j)
        {
            if(W[len][i][j] != sub[j]) cr.pb(j);
        }
        for(j = 1; j < cr.size(); ++j)
        {
            if(cr[j] - cr[j - 1] < 5) goto next;
        }
        if(cr.size() == 0) res = true;
        else opt[cr[0]][cr[cr.size() - 1]] = min(opt[cr[0]][cr[cr.size() - 1]], (int) cr.size());
        next:;
    }
    return res;
}

void solve_case(int case_id)
{
    printf("Case #%d: ", case_id);
    cin >> cs;
    N = (int) cs.length();
    int i, j, k, l, len, res, u, rem;
    bool ch;
    string sub;
    for(i = 0; i < N; ++i)
    {
        for(j = 0; j <= N; ++j) DP[i][j] = INF;
        for(j = max(i - maxl, 0); j <= i; ++j)
        {
            len = i - j + 1;
            sub = cs.substr(j, len);
            ch = fn(sub);
            if(ch)
            {
                if(j == 0) DP[i][N] = 0;
                else
                {
                    for(l = max(j - 1 - maxl, 0); l < j; ++l) DP[i][N] = min(DP[i][N], DP[j - 1][l]);
                    DP[i][N] = min(DP[i][N], DP[j - 1][N]);
                }
            }
            for(k = 0; k < len; ++k)
            {
                for(l = k; l < len; ++l)
                {
                    if(opt[k][l] == INF) continue;
                    DP[i][j + l] = min(DP[i][j + l], (j > 0 ? DP[j - 1][N] + opt[k][l] : opt[k][l]));
                    rem = max(5 - k, 0);
                    if(j > 0)
                    {
                        for(u = max(j - 1 - rem, 0); u >= max(j - 1 - maxl, 0); --u) DP[i][j + l] = min(DP[i][j + l], (j == 0 ? 0 : DP[j - 1][u]) + opt[k][l]);
                    }
                }
            }
        }
    }
    int ans = INF;
    for(i = max(N - 1 - maxl, 0); i <= N; ++i)
    {
        //cout << i << ' ' << DP[N - 1][i] << '\n';
        ans = min(ans, DP[N - 1][i]);
    }
    cout << ans << '\n';
}

int main()
{
    read_dict();
    /*cout << find_nearest("cxde") << '\n';
    cout << find_nearest("jax") << '\n';*/
    int i, t;
    scanf("%d", &t);
    for(i = 1; i <= t; ++i) solve_case(i);
    return 0;
}
