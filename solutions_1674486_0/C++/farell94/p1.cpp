#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <fstream>

using namespace std;


ifstream fin("in.txt");
ofstream fout("out.txt");

int main()
{
    int c;
    fin >>c;
    for (int k = 0; k < c; k++)
    {
        int n;
        fin >>n;
        vector <vector <int> > in(n+1);
        vector <bool> vis(n+1, false);
        
        for (int i = 0; i < n; i++)
        {
            int m;
            fin >>m;
            for (int j = 0; j < m; j++)
            {
                int v;
                fin >>v;
                in[i+1].push_back(v);
            }
        }
        
        queue <int> q;
        bool res = false;
        
        for (int i = 1; i < n+1; i++)
        {
            while (!q.empty()) q.pop();
            q.push(i);
            vis = vector <bool> (n+1, false);
            
            while (!q.empty())
            {
                  int act = q.front();
                  q.pop();
                  for (int j = 0; j < in[act].size(); j++)
                  {
                      int nxt = in[act][j];
                      if (vis[nxt]) {res = true; break;}
                      vis[nxt] = true;
                      q.push(nxt);
                  }
                  if (res) break;
            }
            if (res) break;
        }
        
        string ans = "No";
        if (res) ans = "Yes";
        
        fout <<"Case #"<<k+1<<": "<<ans<<endl; 
    }
    //int a; fin >>a;
}
