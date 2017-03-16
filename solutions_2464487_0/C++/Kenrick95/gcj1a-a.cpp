#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: GCJ2013 Round 1A Problem A. Bullseye
 * URL: https://code.google.com/codejam/contest/2418487/dashboard#s=p0
 */

int64 s,T, t, r, x,y,z ,ans, temp;

int main() {
   cin>>T;
   for (int s=1; s<=T; s++) {
      cin>>r;
      cin>>t;
      ans = 0;
      ans = (int64(sqrt((2*r-1)*(2*r-1) + 8*t)) + (-2*r + 1))/4;
      cout<<"Case #"<<s<<": "<<ans<<endl;
   }
   return 0;
}
