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

long long a, n, ar[101];
int main()
{
  int t=1;
  int T;
  cin>>T;
  while( t <= T )
    {
      printf("Case #%d: ", t);
      cin>>a>>n;
      FOR(i,n)
	cin>>ar[i];
     
      long long res=n, sum =a,op=0;
      sort(ar, ar+n);
      int i=0;
      while(i<n)
	{
	  if( ar[i] < sum ) sum += ar[i];
	  else
	    {
	      res = min(res, op +(n-i));
	      if( sum <=1 ){ op =1000; break;}
	      while( sum <= ar[i] ) sum += sum-1, op++;
	      sum +=ar[i];
	    }
	  i++;
	}

      cout<<min(op,res);
	
      printf("\n");
      t++;
    }
  return 0;
}
