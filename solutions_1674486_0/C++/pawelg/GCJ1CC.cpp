#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int T, N, m, d;
    vector<int> diagram[1001];
    bool visited[1001];
    queue<int> q;
    set<int> s;
    ofstream os;
    bool found;
    
    ifstream fin("A-small-attempt1.in");
    os.open("out.txt");
    
    fin>>T;
    
    for(int i = 0; i < T; i++)
    {
        fin>>N;
        os<<"Case #"<<i+1<<": ";
        found = false;
        s.clear();
        
        for (int j = 1; j <= N; j++)
        {
            fin>>m;
            diagram[j].clear();
            for (int k = 0; k < m; k++)
            {
                fin>>d;
                diagram[j].push_back(d);
                s.insert(d);
            }
        }
        
        for (int j = 1; j <= N; j++)
        {
            if (s.find(j) == s.end())
            {
                for (int k = 1; k <= N; k++)
                    visited[k] = false;
                
                while (!q.empty()) q.pop();
                
                visited[j] = true;
                q.push(j);
                while (!q.empty())
                {
                    int f = q.front();
                    q.pop();
                    for (int k = 0; k < diagram[f].size(); k++)
                    {
                         if (!visited[diagram[f][k]])
                         {
                              q.push(diagram[f][k]);
                              visited[diagram[f][k]] = true;
                         }
                         else
                         {
                              os<<"Yes"<<endl;
                              found = true;
                              break;
                         }
                    }
                    if (found) break;
                }
            }
            if (found) break;
        }
        if (!found) os<<"No"<<endl;
    }
    
    os.close();
    
    return 0;
}
