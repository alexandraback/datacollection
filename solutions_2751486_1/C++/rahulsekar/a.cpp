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

long long sum( long long n, long long k)
{
  if( n <=0 ) return 0;
  return ( (k)*(k+1) / 2 ) - (k-n+1)*(k-n)/2;
}

int main()
{
  int t=1;
  int T;
  cin>>T;
  while( t <= T )
    {
      //      cout<<sum(1,1)<<endl;
      printf("Case #%d: ", t);
      string name;
      long long n, l;
      cin>>name>>n;
      long long ans=0;
      long long i=0,j=0,k=0;
      l = name.size();
      while( k < l )
	{
	  while( j < l && ( name[j] == 'a' || name[j] == 'e' ||
			    name[j] == 'i' || name[j] == 'o' ||
			    name[j] == 'u' ) ) j++;
	  
	  k = j;
	  while( k < l && ( name[k] != 'a' && name[k] != 'e' &&
			    name[k] != 'i' && name[k] != 'o' &&
			    name[k] != 'u' ) ) k++;

	  if( k - j >= n)
	    {
	      ans += ( l-(j+n-1) ) * (j - i + 1);
	      ans += sum( (k-n) - j, l - (j+n));
	      i = k - n +1;
	    }
	  //	  cout<<i<<" " << j << " "<<k<<endl;
	  j = k;
	}
      cout<<ans;
      printf("\n");
      t++;
    }
  return 0;
}
