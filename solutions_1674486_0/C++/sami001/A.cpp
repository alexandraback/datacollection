#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <numeric>
#include <utility>
using namespace std;
#define pi acos(-1.0)
#define INF 1000000000

vector<int>v[1005];
bool vis[1005];

bool flag;

void dfs(int u)
{
    vis[u] = 1;
    for(int i = 0; i < v[u].size();i++)
    {
        int uu = v[u][i];

        if( !vis[uu] ) dfs( uu );
        else flag = 1;
    }
}

int main()
{
    freopen("i.txt","r",stdin);
    freopen("o.txt","w",stdout);

    int t,cs=0;

    cin >> t;

    while(t--)
    {

        memset(vis, 0, sizeof(vis));

        int n;

        cin >> n;



        for(int i = 1; i <= n; i++)
        {
            int m;
            cin >> m;

            for(int j = 0 ; j <m; j++)
            {
                int k;
                cin >> k;

                v[k].push_back(i);
            }
        }

        for(int i = 1; i <= n; i++ )
        {
            memset(vis, 0, sizeof(vis));
            flag = 0;
            dfs(i);
            if(flag) break;
        }
        cout <<"Case #"<< ++cs<<": ";

        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;



        for(int i = 0; i <= n; i++) v[i].clear();
    }

    return 0;
}
