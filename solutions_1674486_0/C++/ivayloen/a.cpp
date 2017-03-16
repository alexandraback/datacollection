#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> u[1024];
int used[1024];

int dfs(int v)
{
    used[v] = 1;
    int i;
    for(i = 0; i < (int)u[v].size(); i++)
        if(used[u[v][i]])
            return 1;
        else
        {
            int r = dfs(u[v][i]);
            if(r)
                return 1;
        }

    return 0;
}

int main()
{
    int t;
    cin >> t;
    int q;
    for(q = 1; q <= t; q++)
    {
        int n;
        cin >> n;
        memset(used, 0, sizeof(used));
       
        int i,j;
        for(i = 0; i < 1024; i++)
            u[i].clear();
        
        for(i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            for(j = 0; j < k; j++)
            {
                
                int w;
                cin >> w;
                u[i].push_back(w - 1);
            }
        }

        cout << "Case #"<< q << ": ";
        int r = 0;
        for(i = 0; i < n; i++)
        {
            r = dfs(i);
            if(r)
            {
                cout << "Yes\n";
                break;
            }

            memset(used, 0, sizeof(used));
        }
        if(!r)
        {
            cout << "No\n";
        }
            
    }
    return 0;
}
