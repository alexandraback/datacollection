#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
typedef long long LL;
typedef vector <int> vi;

#define INF 2000000000
#define PI 3.14159265

#define REP(i,n) for(int i=0, _n=n; i<_n; ++i)
#define FOR(i,a,n) for(int i=a,_n=n; i<=_n; ++i)
#define FOREACH(it,arr) for (__typeof((arr).begin()) it=(arr).begin(); it!=(arr).end(); it++)

#define ALL(v) (v).begin(), (v).end()

#define DEBUG(x) cout << '>' << #x << ':' << x << '\n';

int a, n;
int arr[105];

bool isPossible(int x) {
   int size = a;

   REP (i, n) {
      if ( size > arr[i] ) size += arr[i];
      else {
         int discard = n-i;
         if ( x >= discard ) return true;

         while ( size <= arr[i] ) {
            if ( size-1 <= 0 ) return false;
            size += size-1; //watch out zero
            --x;
            if ( x < 0 ) return false;
         }

         size += arr[i];
      }
   }

   return true;
}

int bin() {
   int left = 0; int right = 100;

   int ans = 100;
   while ( left <= right ) {
      int mid = (left + right) / 2;

      if (isPossible(mid)) {
         right = mid - 1;
         ans = mid;

      }
      else {
         left = mid+1;
      }
   }

   return ans;
}

int main() {
   freopen("a-small.in", "r", stdin);
   freopen("a-small.out", "w", stdout);
   int t; scanf("%d", &t);

   int tcase = 0;
   while (t--) {
      scanf("%d %d", &a, &n);
      REP (i, n) scanf("%d", &arr[i]);

      sort(arr, arr+n);
      int ans = bin();

      printf("Case #%d: %d\n", ++tcase, ans);
   }
   return 0;
}
