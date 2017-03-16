#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <fstream>

using namespace std;

#define rep(i, n) for(int i=0;i<n;i++)

long long gcd ( long long a, long long b )
{
  long long c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

bool even(long long a) {
  rep(i, 41) {
    if(pow(2,i)==a) return true;
  }
  return false;
}

int main() {
  int test; cin>> test;
  rep(z, test) {
    long long n, d; char temp;long long ans=0;
    cin>>n>>temp>>d;
    long long j=gcd(n,d);
    while(j!=1) {
      n=n/j; d=d/j;
      j=gcd(n,d);
    }
    if(even(d)==false) {cout<<"Case #"<<z+1<<": impossible\n";}
    else {
      if (d==2) ans=1;
      else {
	while(n<d) {
	  ans++; d = d/2;
	}
      }
      cout<<"Case #"<<z+1<<": "<<ans<<endl;
    }
  }
}
	  
      
