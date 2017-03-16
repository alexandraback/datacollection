#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef unsigned long long big;
typedef pair<big,int> bi;

int n,m;

big solve(vector<bi> &a, vector<bi> &b,int ia,int ib)
{
  if(ia>=n||ib>=m)
    return 0;
  
  bi pa=a[ia],pb=b[ib];
  if(pa.second==pb.second)
    {
      //cout<<"sec"<<pa.second<<" pbsec"<<pb.second<<endl;
      if(pa.first==pb.first)
	{
	  return pa.first+solve(a,b,ia+1,ib+1);
	}
      else if(pa.first<pb.first)
	{
	  vector<bi> c(b);
	  c[ib].first-=pa.first;
	  return pa.first+solve(a,c,ia+1,ib);
	}
      else
	{
	  vector<bi> c(a);
	  c[ia].first-=pb.first;
	  return pb.first+solve(c,b,ia,ib+1);
	}
    }
  else
    {
      return max(solve(a,b,ia+1,ib), solve(a,b,ia,ib+1));
    }
}

int main()
{
  int T;
  cin>>T;
  for(int t=1;t<=T;t++)
    {
      cin>>n>>m;
      cout<<"Case #"<<t<<": ";
      vector<bi> a(n),b(m);
      for(int i=0;i<n;i++)
	cin>>a[i].first>>a[i].second;
      for(int i=0;i<m;i++)
	cin>>b[i].first>>b[i].second;
      
      big resp=solve(a,b,0,0);
      cout<<resp<<endl;      
    }
  return 0;
}
