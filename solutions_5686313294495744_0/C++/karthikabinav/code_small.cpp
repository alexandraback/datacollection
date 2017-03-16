#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>


using namespace std;
pair<string, string> entries[20];

/*int try(vector<int> r, int n)
{
  int i;
  vector< pair<int,int> > tedges;
  for(i=0;i<edges.size();i++)
    tedges.push_back(edges[i]);

  for(i=0;i<r.size();i++)
  {
    if(r[i] == 1)
    {
      int te = tedges[i].first;
      tedges[i].first = tedges[i].second;
      tedges[i].second = te;

    }
  }



}*/

int tryT(vector<int> r, int n)
{
  vector<int> order;
  int i;
  for(i=0;i<r.size();i++)
  {
    if(r[i] == 0)
    {
      order.push_back(i);
    }
  }
  for(i=0;i<r.size();i++)
  {
    if(r[i] == 1)
    {
      int j;
      bool fdf = false;
      bool fdl = false;
      for(j=0;j<order.size();j++)
      {
        if(entries[order[j]].first.compare(entries[i].first) == 0)
        {
          fdf = true;
        }
        if(entries[order[j]].second.compare(entries[i].second) == 0)
        {
          fdl = true;
        }

      }
      if(!(fdf && fdl))
        return -1;
    }
  }
  return n-order.size();

}
int main()
{
  int t;
  cin>>t;

  int count = 1;
  while(t--)
  {
      int n;
      cin>>n;


      int i,j;
      for(i=0;i<n;i++)
      {
          string f,l;
          cin>>f;
          cin>>l;

          entries[i] = make_pair(f, l);
      }

      int cnt = 0;
      vector<int> r;
      for(i=0;i<n;i++)
        r.push_back(0);

      int ans = 0;
      while(cnt<pow(2,n))
      {
          int temp = tryT(r, n);
          /*cout<<temp<<endl;
          for(i=0;i<r.size();i++)
            cout<<r[i];
          cout<<endl;*/
          ans = max(ans, temp);

          for(i=r.size()-1;i>=0;i--)
          {
            if(r[i] == 1)
              r[i] = 0;
            else
            {
              r[i]++;
              break;
            }
          }

          cnt++;
      }

      /*for(i=0;i<n;i++)
      {
          for(j=i+1;j<n;j++)
          {
              if(entries[i].first.compare(entries[j].first)==0 || entries[i].second.compare(entries[j].second)==0)
                edges.push_back(make_pair(i,j));
          }
      }

      int cnt = 0;
      vector<int> r;
      for(i=0;i<edges.size();i++)
        r.push_back(0);

      int ans = 0;
      while(cnt<pow(2,edges.size()))
      {
          int temp = try(r, n);
          ans = max(ans, temp);

          for(i=r.size()-1;i>=0;i--)
          {
            if(r[i] == 9)
              r[i] = 0;
            else
            {
              r[i]++;
              break;
            }
          }

          cnt++;
      }*/

      cout<<"Case #"<<count<<": "<<ans<<endl;
    count++;
  }



}
