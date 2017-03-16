#line 2 "GuitarChords.cpp"
//convert stl string to char array{string stl, char    *arr=stl.c_str()}
//convert char array to string{char arr[]; string str; str.assign(arr)}
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include<cstring>




using namespace std;
#define INF 2000000000
#define INFLL (1LL<<62)
#define _mp make_pair
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,a,b) for(int (i)=a;(i)<(b);(i)++)

vector <int> adj[1009];
bool vis[1009];
int flag;
void dfs(int node)
{
  int i;
  //cout<<node<<"\n";
  for(i=0;i<adj[node].size();i++)
  {
      if(vis[adj[node][i]])
	  flag=1;
      else
      {
	vis[adj[node][i]]=true;
	dfs(adj[node][i]);
      }
  }
  
  
}
int main()
{
  int t,i,j,temp,tt,n,m;
  cin>>t;
  for(tt=1;tt<=t;tt++)
  {
      cin>>n;
      for(i=0;i<n;i++)
      {
	cin>>m;
	adj[i].clear();
	for(j=0;j<m;j++)
	{
	    cin>>temp;
	    temp--;
	    adj[i].push_back(temp);
	}
      }
      
      for(i=0;i<n;i++)
      {
	memset(vis,0,sizeof(vis));
	vis[i]=true;
	flag=0;
	//cout<<"start "<<i<<endl;
	dfs(i);
	if(flag==1)
	 break;
      }
      
      if(i==n)
	cout<<"Case #"<<tt<<": No\n";
      else
	cout<<"Case #"<<tt<<": Yes\n";
      
  }
  return 0;
}
