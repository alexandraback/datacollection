#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <functional>
#include <cctype>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<double,double> ppd;
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
ll gcd( ll a, ll b)
{
  return b == 0 ? a : gcd( b, a % b);
}
int main()
{
  int T;
  scanf("%d", &T);
  ios::sync_with_stdio(false);
  for( int t = 1 ; t <= T; ++t )
    {
      ll p, q;
      char tmp;
      cin >> p >> tmp >> q;
      ll d = gcd( p, q);
      p /= d, q /= d;
      int cnt(0);
      int fir(0);
      for( ; cnt <= 40;)
	{
	  ++cnt;
	  p <<= 1;
	  if( p >= q )
	    {
	      p -= q;
	      if( fir == 0 )
		fir = cnt;
	      if( p == 0 )
		break;
	    }
	}
      
      printf("Case #%d: ", t);
      if( cnt <= 40 )
	printf("%d", fir);
      else printf("impossible");
      printf("\n");
    }
  return 0;
}
