#include <vector>
#include <list>
#include <cassert>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef pair <int,int> pii;
typedef vector <int> vi;
typedef vector <string> vs;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MAXN = 1001;

inline int toInt(string& s)
{
    stringstream ss;
    int ret;
    ss << s;
    ss >> ret;
    return ret;
}

inline string toStr(int& i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}

/************************************************************************
******************** Code written during the contest ********************
************************************************************************/

bool edge[MAXN][MAXN];
int color[MAXN];
int edges[MAXN];
int edgecount[MAXN];
int verts[MAXN];
int par[MAXN];
int n,colors;

void colorthem(int v, int c)
{
    color[v] = c;
    edges[c] += edgecount[v];
    verts[c]++;
    for (int i=0; i<n; i++)
    {
        if (edge[v][i] && color[i] != c)
            colorthem(i,c);
    }
}

int parent(int i)
{
    vector <int> st;
    if (par[i] != -1) return par[i];
    int c=i;
    bool good = true;
    while (good)
    {
        good = false;
        for (int j=0; j<n; j++)
            if (edge[j][i])
            {
                i = j;
                good = true;
                break;
            }
        if (par[i] != -1) return par[c] = par[i];
        st.push_back(i);
    }
    for (int j=0; j<st.size(); j++)
        par[st[j]] = i;
    return par[c] = i;
}

void solve()
{
    memset(edge,      0, sizeof(edge));
    memset(color,     0, sizeof(color));
    memset(edges,     0, sizeof(edges));
    memset(edgecount, 0, sizeof(edgecount));
    memset(verts,     0, sizeof(verts));
    memset(par,      -1, sizeof(par));

    cin >> n;
    int temp;
    int total = 0;
    for (int i=0; i<n; i++)
    {
        cin >> edgecount[i];
        for (int j=0; j<edgecount[i]; j++)
        {
            cin >> temp;
            assert(!edge[temp-1][i]);
            edge[i][temp-1] = true;
        }
        total += edgecount[i];
    }

    colors = 0;
    for (int i=0; i<n; i++)
    {
        int p = parent(i);
        if (!color[p])
            colorthem(p,++colors);
    }

    for (int i=1; i<=colors; i++)
    {
        assert(edges[i]+1 >= verts[i]);
        if (edges[i]>=verts[i])
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";

}

int main()
{
    int t; cin >> t;
    for (int kase=1; kase<=t; kase++)
    {
        cout << "Case #" << kase << ": ";
        solve();
    }
    return 0;
}
