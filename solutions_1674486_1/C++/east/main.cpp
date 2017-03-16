#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int size = 1100;
vector<int> ee[size];;
int n;
bool vis[size];

bool dfs(int id)
{
    if(vis[id])
        return true;
    vis[id] = true;
    for(int i = 0; i < ee[id].size(); i++)
    {
        if(dfs(ee[id][i]))
            return true;
    }
    return false;
}

bool getans()
{
    for(int i = 1; i <= n; i++)
    {
        for(int i = 1; i <= n ;i++)
            vis[i] = false;
        if(dfs(i))
            return true;
    }
    return false;
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    int cas; cin >> cas;

    for(int cc = 1; cc <= cas; cc++)
    {
        cout << "Case #" << cc << ": ";
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            int t; cin >> t;
            ee[i].clear();
            while(t --)
            {
                int a; cin >> a;
                ee[i].push_back(a);
            }
        }

        if( getans())
            cout << "Yes" << endl;
        else cout << "No" << endl;



    }

    return 0;
}



















