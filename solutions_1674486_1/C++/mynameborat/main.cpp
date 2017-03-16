#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>

using namespace std;

int main(int argc, char *argv[])
{
    int T;
    int cno = 1; 
    cin >> T; 
    while(T--)
    {
         cout << "Case #" << cno++ << ": "; 
         int N; 
         bool visited[1024]; 
         vector<int> adj_list[1024]; 
         
         cin >> N; 
         
         for (int i = 0; i <=N; i++)
         {
             adj_list[i].clear();
             visited[i] = false;
         }  
         
         for (int i = 0; i <N; i++)
         {
             int mi; 
             cin >> mi; 
             for (int j = 0; j < mi; j++)
             {
                 int v; 
                 cin >> v; 
                 adj_list[i+1].push_back(v); 
             }
         }
         
         bool diamond = false;
         for (int i = 1; i <= N; i++)
         {
             queue<int> bfs;               
             for (int j = 0; j <= N; j++)
                 visited[j] = false; 
             
             bfs.push(i);
             while (!bfs.empty())
             {
                   int t = bfs.front();
                   bfs.pop(); 
                   
                   for (int j = 0; j < adj_list[t].size(); j++)
                   {
                       if (visited[adj_list[t][j]])
                       {
                           diamond = true; 
                           goto out; 
                       }
                       visited[adj_list[t][j]] = true;
                       bfs.push(adj_list[t][j]); 
                   }
             }
         }
         
         out:
             if (diamond)
                cout << "Yes" << endl;
             else
                cout << "No" << endl; 
    }
    return EXIT_SUCCESS;
}
