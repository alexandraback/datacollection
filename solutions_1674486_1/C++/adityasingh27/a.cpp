#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<iomanip>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

bool medge[1001][1001];
bool taken[1001];
int n;

int bfs(int v)
{
    int been[1001]={0};
    queue< int > q;
    q.push(v);
    bool visit[1001]={0};
    while(!q.empty())
    {
                     int s;
                     s = q.front();
                     visit[s] = 1;
                     for(int i=1;i<=n;i++)
                     {
                             if(medge[s][i] == 1)
                             {
                              if(visit[i] == 0)
                              {
                                         int r = i;
                                         q.push(r);
                              }
                                  been[i]++;
                                  if(been[i] > 1)
                                  return 1;
                             }
                     }
                     q.pop();
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
            int values[1001]={0};
            cin >> n;
            for(int j=1;j<=n;j++)
            {
                    int mi;
                    cin >> mi;
                    for(int k=1;k<=mi;k++)
                    {
                            int r;
                            cin >> r;
                            medge[j][r] = 1;
                    } 
            }
            int yes = -1;
            for(int j=1;j<=n;j++)
            {
                    int y = bfs(j);
                    if(y == 1)
                    {
                         yes = 1;
                         break;
                     }
            }
            if(yes == 1)
            {
                   printf("Case #%d: Yes\n",i);
            }
            else
            printf("Case #%d: No\n",i);
            for(int j=1;j<=n;j++)
              for(int k=1;k<=n;k++)
                 medge[j][k] = 0;
    }
    return 0;
}
