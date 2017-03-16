#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<string>
using namespace std;

#define FOR(i,n) for(int i = 0; i<(n); ++i)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define X first
#define Y second
#define MP make_pair
#define PB push_back

typedef vector<int> VI;

int main()
{
  int t=1;
  int T;
  cin>>T;
  while( t <= T )
    {
      printf("Case #%d: ", t);
      int x, y;
      cin>>x>>y;
      string res="";
      int i;
      if( x < 0 )
	for( i =0; i < -x; ++i )
	  res += "EW";
      else
	for( i =0; i < x; ++i )
	  res += "WE";

      if( y < 0 )
	for( i =0; i < -y; ++i )
	  res += "NS";
      else
	for( i =0; i < y; ++i )
	  res += "SN";
      cout<<res;
      printf("\n");
      t++;
    }
  return 0;
}
