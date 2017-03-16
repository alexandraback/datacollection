#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <list>
#include <algorithm>


using namespace std;
int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N;
        cin >> N;
        
        vector< vector<int> > adj(N+1);
        
        vector<int> fanin(N+1,0);
        for (int i = 1; i <= N; i++)
        {
            int temp;
            int M;
            cin >> M;
            for (int j = 0; j < M; j++)
            {
                cin >> temp;
                fanin[temp]++;
                adj[i].push_back(temp);
            }
        }
        bool found = false;
        
        for (int j = 1; j <= N ; j++)
        {
            if(fanin[j]==0)
            {       
                vector<bool> visited(N+1, false);
                //~ cerr << j << endl;
                list<int> q;
                visited[j] = true;
                q.push_back(j);   
                while(!q.empty())
                {
                    int current = q.front();
                    q.pop_front();
                    for (int i = 0; i < adj[current].size(); i++)
                    {
                        if(!visited[adj[current][i]])
                        {
                            visited[adj[current][i]] = true;
                            q.push_back(adj[current][i]);
                        }
                        else
                        {
                            found = true; 
                        }
                    }
                }
            }
        }
        cout << "Case #" << t+1 << ": ";
        if(found)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
