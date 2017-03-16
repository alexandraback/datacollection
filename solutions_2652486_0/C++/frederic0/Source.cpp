#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <cassert>
#include <complex>
#include <climits>
#include <functional>

using namespace std;

#define ST first
#define ND second
#define MP make_pair
#define PB push_back


typedef unsigned int uint;
typedef long long LL;
typedef long double LD;

typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))

#define fabsl __builtin_fabsl
#define atan2l __builtin_atan2l
#define cosl __builtin_cosl
#define sinl __builtin_sinl
#define sqrtl __builtin_sqrtl




int main(int argc, char **argv)
{

   
   cout << "Case #1:" << endl; 

   int testcases, R, N, M, K, print;

   cin >> testcases;

   cin >> R >> N >> M >> K;
   
   

   vector<int> numbs(K);
   

   for (int t = 0; t < R; ++t)
   {
      print = N;
      for (int i = 0; i < K; i++)
      {
         cin >> numbs[i];
      }
      sort(numbs.rbegin(), numbs.rend());
      
      vector<bool> buck(M, false);

      for (int i = 0; i < K; i++)
      {
         int curr = M;
         while (numbs[i] % curr == 0 && print > 0 && buck[curr] == false) {
            buck[curr] = true;
            cout << curr;
            curr--;
            print--;
         }

         if (print == 0) break;
      }
      
      while (print > 0)
      {
         for (int i = 2; i <= M && print > 0; i++)
         {
            if (rand()%2) {
               cout << i;
               print--;
            }
         }
      }
      
      cout << endl;


   }

}