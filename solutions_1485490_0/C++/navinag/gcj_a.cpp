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

long long memo[105][105],Aq[105],At[105],Bq[105],Bt[105];
int n, m;

long long go(int i, int j)
{
    long long ans=0;
    if(i>=n || j>=m)
	return 0;
   
    if(At[i]==Bt[j])
    {
	if(Aq[i]==Bq[j])
	{
	  long long temp = Aq[i], temp1=Bq[j];
	  Aq[i]=0;
	  Bq[j]=0;
	  ans=max(ans, temp+go(i+1,j+1));
	   Aq[i]=temp, Bq[j]=temp1;
	}
	else if(Aq[i]>Bq[j])
	{
	  long long temp = Aq[i], temp1=Bq[j];
	  Aq[i]-=Bq[j];
	  Bq[j]=0;
	  
	  ans=max(ans, temp1+go(i,j+1));
	  Aq[i]=temp, Bq[j]=temp1;
	}
	else
	{
	  long long temp = Aq[i], temp1=Bq[j];
	  Bq[j]-=Aq[i];
	  Aq[i]=0;
	  
	  ans=max(ans, temp+go(i+1,j));
	  Aq[i]=temp, Bq[j]=temp1;
	}
	  
    }
    else
    {
      ans=max(ans, go(i+1,j+1));
      ans=max(ans, go(i+1,j));
      ans=max(ans, go(i, j+1));
    }
    
   return ans;
}
int main()
{
  int t,i,j,temp,tt;
  cin>>t;
  for(tt=1;tt<=t;tt++)
  {
      cin>>n>>m;
      
      for(i=0;i<n;i++)
      {
	cin>>Aq[i]>>At[i];
      }
      for(i=0;i<m;i++)
      {
	cin>>Bq[i]>>Bt[i];
	
      }
      memset(memo,-1,sizeof(memo));
      long long ans=go(0,0);
      
      /*for(i=0;i<n;i++)
      {
	for(j=0;j<m;j++)
	  cout<<memo[i][j]<<" ";
	cout<<"\n";
      }*/
	cout<<"Case #"<<tt<<": "<<ans<<"\n";
      
  }
  return 0;
}
