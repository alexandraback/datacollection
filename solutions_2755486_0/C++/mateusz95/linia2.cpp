#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define LL long long
#define ff first
#define ss second
#define PB push_back
#define MP make_pair


using namespace std;
int t,n,pierd,latak,P,K,str,dt,dd,ds;
vector<pair<pair<int,int> , int> > V[100000005];
int wys[200000005];

int main()
{
  ios_base::sync_with_stdio(0);
  


  
  cin>>t;
  for(int z=1;z<=t;z++)
  {
    int wynik=0;
    //printf("Case #%d: ",z);
    cout<<"Case #"<<z<<": ";
    cin>>n;
    for(int i=0;i<=200000;i++)wys[i]=0;
    for(int i=1;i<=n;i++)
    {
      cin>>pierd>>latak>>P>>K>>str>>dt>>dd>>ds;
      P+=300;
      K+=300;
      for(int j=1;j<=latak;j++)
      {
	V[pierd].PB(MP(MP(P,K),str));
	P+=dd;
	K+=dd;
	pierd+=dt;
	str+=ds;
	
      }
      
    }
    
    for(int i=0;i<=1000000;i++)
    {
      for(int j=0;j<V[i].size();j++)
      {
	int poc=V[i][j].ff.ff;
	int kon=V[i][j].ff.ss;
	int sila=V[i][j].ss;
	
	
	for(int k=2*poc;k<=2*kon;k++)
	{
	  if(wys[k]<sila)
	  {
	    
	    wynik++;
	    break;
	  }
	}
	
	
	
      }
      
      for(int j=0;j<V[i].size();j++)
      {
	int poc=V[i][j].ff.ff;
	int kon=V[i][j].ff.ss;
	int sila=V[i][j].ss;
	
	
	for(int k=2*poc;k<=2*kon;k++)
	{
	  wys[k]=max(wys[k],sila);
	}
	
	
	
      }
      V[i].clear();
    }
  
  cout<<wynik<<"\n";
  }
  return 0;
}