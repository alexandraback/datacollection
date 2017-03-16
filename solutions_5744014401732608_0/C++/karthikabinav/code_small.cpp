#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int graph[7][7];
int n;
int num[7];
bool contains(vector<int> vis, int k)
{
  int i;
  for(i=0;i<vis.size();i++)
  {
    if(vis[i] == k)
      return true;
  }
  return false;

}
int num_paths(int u, int b, vector<int> vis)
{
  if(u == b)
      return 1;

      if(num[u]==-1)
      {
          int j;
          int sum = 0;
          for(j=0;j<n;j++)
          {
              if(graph[u][j] == 1 && !contains(vis, j))
              {
                  vector<int> nvis;
                  int k;
                  for(k=0;k<vis.size();k++)
                    nvis.push_back(vis[k]);
                  nvis.push_back(j);

                  sum+=num_paths(j,b, nvis);
              }

          }
          num[u] = sum;

      }

  return num[u];


}

int main()
{
  int t;
  cin>>t;

  int count = 1;
  while(t--)
  {
    int b,m;
    cin>>b>>m;

    n = b;


    int cnt = 0;
    int i,j;
    int sz = ((b-1)*b)/2;
    int bt[sz];
    for(i=0;i<sz;i++)
      bt[i] = 0;

      bool fd = false;
    while(cnt < pow(2,sz))
    {
        for(i=0;i<n;i++)
          num[i] = -1;
        int pos = 0;
        for(i=0;i<b-1;i++)
        {
          for(j=0;j<b;j++)
          {
              if(i>=j)
                continue;
              graph[i][j] = bt[pos];
              pos++;
          }

        }
        //cout<<num_paths(1,b)<<endl;
        vector<int> vis;
        if(num_paths(0,b-1, vis) == m)
        {
          fd = true;
            break;
        }

        for(i=sz-1;i>=0;i--)
        {
          if(bt[i] == 1)
            bt[i] = 0;
          else{
            bt[i] = 1;
            break;
          }

        }
        cnt++;
        //break;
    }
    cout<<"Case #"<<count<<": ";
    if(fd)
    {
        cout<<"POSSIBLE"<<endl;
        for(i=0;i<n;i++)
        {
          for(j=0;j<n;j++)
            cout<<graph[i][j];
          cout<<endl;
        }



    }
    else
    {
      cout<<"IMPOSSIBLE"<<endl;
    }
    count++;
  }



}
