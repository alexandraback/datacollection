#import <iostream>
#import <sstream>
#import <algorithm>
#import <map>
#import <set>
#import <vector>
#import <queue>

#import <cstdio>
#import <cstdlib>
#import <cstring>
#import <cmath>
#import <cctype>

using namespace std;
typedef unsigned long long LL;
typedef vector<int> VI;

const double PI = acos( -1.0 );

double sum(double n)
{
   return (n*(n-1))/2.0;
}
int isok(LL r, LL t, LL m)
{
   if(t/m >= (r*2+1+(m-1)*2)) return 1;
   return 0;
}


int main()
{
   freopen("A-small-attempt0.in","r",stdin);
   freopen("A-small.out","w",stdout);
   int T;
   cin>>T;
   for(int tc = 1; tc <= T; tc++) {
      LL r,t;
      cin>>r>>t;
      LL lo = 1, hi = t,req=1;
      while(lo<=hi) {
         LL mid = (lo + hi)/2;
         if(isok(r,t,mid)) {
            req = max(req,mid);
            lo = mid + 1;
         }else {
            hi = mid - 1;
         }

      }
      cout<<"Case #"<<tc<<": "<<req<<endl;

   }
   return 0;
}
