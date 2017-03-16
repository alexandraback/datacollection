#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool visited[1001];
typedef vector<int> v;
v gr[1001];
bool flag;
bool dfs(int node)
{
     int i;
    if (visited[node] == true)
    { 
       flag = true;
       return true;
    }
    visited[node] = true;
    for (i = 0; i < gr[node].size(); ++i)
    {
        dfs(gr[node][i]);
    }
}


main()
{
      int i, T, N, aux, n;
      cin >> T;
mai:      for (int k = 1; k <= T; ++k)
      {flag = false;
      bool f2 = false;
                cin >> N;
                memset(visited, false, N*sizeof(bool));
                for (i = 1; i <= N; ++i)
                {
                    gr[i].clear();
                    cin >> n;
                    while(n--)
                    {
                     cin >> aux;
                     gr[i].push_back(aux);
                    }
                }
                 cout << "Case #" << k << ": ";
                for (i = 1; i <= N; ++i)
                {
                    memset(visited, false, (N+1)*sizeof(bool));
                    dfs(i);
                    if (flag)
                       break;
                }
                if (flag)
                       cout << "Yes\n";
                else
                    cout << "No\n";
      }
}
