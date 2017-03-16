#include <bits/stdc++.h>
using namespace std;


int n,m;
string c[101];
int g[101][101];
int check(int city,int st,vector<int>a,vector<int> x,vector<int> y,vector<int> used,vector<int> vis)
{
	
	//cout<<"perm"<<endl;
	//for(int i=0;i<n;i++) cout<<a[i]<< " ";
	//cout<<endl;
	//cout<<city<<" "<<st<<endl;
	if(st==n)
	{
		for(int i=0;i<n;i++)
		{
			if(!vis[i]) return 0;
			
		}
		for(int i=0;i<used.size();i++)
		{
			if(!used[i]) return 1;
		}
		return 1;
	}
	if(city==a[st])
	{
		return check(city,st+1,a,x,y,used,vis);
	}
	int p = city;
	int nx = a[st];
	int ans = 0;
	
	if(vis[nx]) return 0;
	for(int i=0;i<x.size();i++)
	{
		if(y[i]==p && !used[i])
		{
			used[i]=1;
			ans = ans |check(x[i],st,a,x,y,used,vis);
			if(ans==1) return 1;
			used[i]=0;
		}
	}
	if(g[p][nx]){
	 x.push_back(p);
	 y.push_back(nx);
	 used.push_back(0);
	 vis[nx]=1;
	 ans = ans | check(nx,st+1,a,x,y,used,vis);
	 vis[nx]=0;
	  x.pop_back();
	 y.pop_back();
	 used.pop_back();
    }
    return ans;
}
int main()
{
  freopen("in.in","r",stdin);
  freopen("out.out","w",stdout);
  
  int TC;
  cin>>TC;
  for(int test_case=1;test_case<=TC;test_case++){
	 
	  cin>>n>>m;
	  for(int i=0;i<n;i++)
	  {
		  cin>>c[i];
	  }
	  memset(g,0,sizeof(g));
	  for(int i=0;i<m;i++)
	  {
		  int x,y;
		  cin>>x>>y;
		  x--;
		  y--;
		  g[x][y]=1;
		  g[y][x]=1;
	  }
	  vector<int> a(n);
	  for(int i=0;i<n;i++) a[i]=i;
	  string mc(45,'9');
	  do
	  {
		  string cost="";
		  for(int i=0;i<n;i++) cost+=c[a[i]];
		  
		  vector<int> vis(n,0);
		  vis[a[0]]=1;
		  vector<int>x,y,used;
		  //cout<<"start"<<a[0]<<endl;
		  int z= check(a[0],1,a,x,y,used,vis);
		  if(z)
		  mc = min(mc,cost);
	  }
	  while(next_permutation(a.begin(),a.end()));
	  
	  
	  
	  printf("Case #%d: ",test_case);;
	  cout<<mc<<endl;
	 }	
  return 0;
}
