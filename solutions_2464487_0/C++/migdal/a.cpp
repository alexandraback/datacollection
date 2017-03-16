/* Author : migdal */
#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <sstream>
#include <map>
#include <set>
#include <climits>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define INF 1000000000
#define ALL(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef long long LL;
int main()
{
   LL test;
   LL r,t,sum,coun,ring;
   cin>>test;
   int i=0;
   while(test--)
   {
      i++;
      cin>>r>>t;
      sum=0;
      coun=0;
      while(sum<=t)
      {
	 sum=sum+2*r+1+(coun)*4;
	 coun++;
      }
      cout<<"Case #"<<i<<": "<<coun-1<<endl;
   }
   return 0;
}
