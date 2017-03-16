#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

long int min(long int a, long int b)
{
  if( a<b )
    return a;
  return b;
}
long int max( long int a, long int b )
{
  if(a>b)
    return a;
  return b;
}

int main()
{
  int t=1;
  int T;
  cin>>T;
  while( t <= T )
    {
      long int e, r, n;
      cin>>e>>r>>n;
      long int v[10001];
      for( int i = 0; i <n; ++i )
	cin>>v[i];
      long int gain = 0;
      long int current=e;
      for( int i = 0; i < n; ++i )
	{
	  int j = i+1;
	  while( j < n && v[j] < v[i] )++j;
	  long int spend = min( max(current + (j - i) * r - e,0),current); 
	  if(j==n)
	    spend = current;
	  gain += v[i] * spend;
	  current -= spend-r;
	  //	  cout<< max(current + (j-i)*r-e,0) <<" " <<current << endl;
	}
      cout<<"Case #"<<t<<": "<<gain<<endl;
      t++;
    }
  return 0;
}
