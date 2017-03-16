#include<iostream>
#include<fstream>
#include<cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<vector>
#include<set>
using namespace std;

 vector<int> v[1002];
 int M[1002][1002];
 int visited[1002];
 int path[1002];
 int dfs(int s, int t, int len)
 { 
        if(len > 1 && s == t) return 1;
        if(s == t) return 0;
        visited[s] = 1;
        int ret = 0;
        for(int i = 0; i < v[s].size(); i++)
        {
           if(!visited[v[s][i]])
           {
             path[len] = v[s][i];
             ret |= dfs(v[s][i], t, len + 1);
           }
           if(ret) return 1;
        }
        return ret;
 }
int main()
{
 ifstream in("in.txt");
 ofstream out("out.txt");
 int t,n;
 
 in >> t;
 for(int k = 1; k <= t; k++)
 {
   in >> n;
   memset(M,0,sizeof(M));
   for(int j = 1; j <= n; j++) v[j].clear();
   for(int j  =1; j <= n; j++)
   {
     int c;
     in >> c;
     for(int i = 0; i < c; i++)
     {
        int cur;
        in >> cur;
        v[cur].push_back(j);    
        M[cur][j] = 1;
     }
   }
   int g = 0;
   for(int s = 1; s <= n; s++)
   {
     for(int ta = 1; ta <= n; ta++)
     {
            memset(visited,0,sizeof(visited));
            memset(path,0,sizeof(path));
            if(s != ta)
            {
                if(M[s][ta] == 1 || dfs(s,ta,0))
                {
                    memset(visited,0,sizeof(visited));
                   
                    for(int i = 0; path[i] != 0; i++)
                    {
                      
                        if(path[i] != s && path[i] != ta)
                          visited[path[i]] = 1;
                    }
                  
                    memset(path,0,sizeof(path));
                    if(dfs(s,ta,0))
                    {
                 
                      for(int i = 0; path[i] != 0; i++)
                      {
                 
                        if(path[i] != s && path[i] != ta)
                          visited[path[i]] = 1;
                      }
                    
                      g = 1;
                      goto hell;    
                    }
                }
            }
     }   
   }
   hell:;
   if(g)
     out<<"Case #"<<k<<": Yes"<<endl;
   else
     out<<"Case #"<<k<<": No"<<endl;
  }

}
