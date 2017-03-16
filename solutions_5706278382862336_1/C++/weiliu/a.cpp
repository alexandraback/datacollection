#include <algorithm>
#include <numeric>
#include <functional>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
#include <ctime>
using namespace std;

#define debug(x) cerr<<#x<<" = "<<(x)<<endl;

long long gcd(long long a, long long b){
  while(a%b){
    long long t = b;
    b = a%b;
    a = t;
  }
  return b;
}

int main(int argc, char *argv[])
{
  int __T;
  cin>>__T;
  for(int __t = 1 ; __t <= __T; __t++){

    long long p, q;
    char c;
    cin>>p>>c>>q;

    long long d = gcd(p,q);
    p/=d;
    q/=d;
    long long a = ((long long) 1)<<40;

    if(a%q!=0){
      cout<<"Case #"<<__t<<": impossible"<<endl;
      continue;
    }

    int k = 40;
    long long one = a / q * p;


    while(one>1){
      one /= 2;
      k--;
    }

    cout<<"Case #"<<__t<<": "<<k<<endl;
  }

    return 0;
}
