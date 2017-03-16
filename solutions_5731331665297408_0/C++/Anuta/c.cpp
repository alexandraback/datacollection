#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int T;
int n, m;
vi g[100];
int z[100];
vector<bool> visited;
vector <int> pred;
vector <int> time;
string res;

void dfs(int st, int &tt)
{
/*    char ss[1000];
    itoa(z[st], ss, 10);
    res += ss;*/
    visited[st] = true;
    time[st] = tt;
    vector <pii> x;
    for (int i = 0; i < g[st].size(); ++i)
    {
        x.push_back(pii(z[g[st][i]], g[st][i]));
    }    
    for (int i = 0; i < x.size(); ++i)
    {
        
        if (!visited[x[i].second])
        {
            pred[x[i].second] = st;
            dfs(x[i].second, ++tt);
        }
        if (z[pred[x[i].second]] > z[st])
        {
            pred[x[i].second] = st;
            dfs(x[i].second, ++tt);
        }
    }
}

int main()
{
    scanf("%d", &T);
    for (int t = 0; t < T; ++t)
    {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i)
            g[i].resize(0);
        for (int i = 0; i < n; ++i)
            scanf("%d", &z[i]);
        for (int i = 0; i < m; ++i)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            --a; --b;
            g[a].push_back(b);
            g[b].push_back(a);        
        }
        vector<pii> p(n);
        for (int i = 0; i < n; ++i)
            p[i] = pii(z[i], i);
        sort(p.begin(), p.end());
        bool ok = false;
        
        res = "";
        string r = "";
        for (int i = 0; i < n && !ok; ++i)
        {
            visited.clear();
            visited.resize(n, false);
            pred.resize(n, -1);
            time.resize(n, 0);
            int tm = 0;
            dfs(p[i].second, tm);
            ok = true;
            for (int j = 0; j < visited.size() && ok; ++j)
                if (!visited[j]) ok = false;
            /*if (ok && (r == "" || r > res))
                r = res;*/
            if (ok)
            {
                vector <pii> pp(n);
                for (int j = 0; j < n; ++j)
                {
                    
                    pp[j] = pii(time[j], z[j]);
                }
                sort(pp.begin(), pp.end());
                res = "";
                for (int j = 0; j < n; ++j)
                {
                    char ss[1000];
                    itoa(pp[j].second, ss, 10);
                    res += ss;
                }
                if (r == "" || res < r)
                    r = res;
            }   
        }
        printf("Case #%d: %s\n", t + 1, r.c_str());
    }
    return 0;
}