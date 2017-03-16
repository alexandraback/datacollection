#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>

using namespace std;
int **graph;
int n;

bool fun(int start)
{
    queue<int> Q;
    vector<int> visited(n, 0);
    visited[start] = 1;
    Q.push(start);
    
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i = 0; i < n; i++)
        {
            if(i == u)
                continue;
            if( graph[u][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                Q.push(i);
            }
            else if( graph[u][i] == 1 && visited[i] == 1)
                return 1;
        }
    }
    return 0;
}

int main()
{
    int cases, num = 1;
    cin >> cases;
    
    while(cases--)
    {
        cin >> n;
        
        graph = new int*[n];
        for(int i = 0; i < n; i++)
        {   
            graph[i] =new int[n];
            for(int j = 0; j < n; j++)
                graph[i][j] = 0;
        }
        for(int i = 0; i < n; i++)
        {
            int m, c;
            cin >> m;
            for(int j = 0; j < m; j++)
            {
                cin >> c;
                c--;
                graph[i][c] = 1;
            }
        }
        bool done = 0;
        for(int i = 0; i < n && !done; i++)
        {
            if(fun(i))
                done = 1;
        }
        if(done)
            cout << "Case #" << num++ << ": Yes" << endl;
        else
            cout << "Case #" << num++ << ": No" << endl;
    }

    return 0;
}
