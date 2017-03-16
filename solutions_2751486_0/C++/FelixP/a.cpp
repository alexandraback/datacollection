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

bool isConsonant(char c) {
   if ( !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ) return true;
   return false;
}

int main() {
   freopen("a-small.in", "r", stdin);
   freopen("a-small.out", "w", stdout);
   int T; scanf("%d", &T);

   int tcase = 0;
   while (T--) {
      char word[1000001]; int n;
      scanf("%s %d", word, &n);

      int L = strlen(word);
      int cnt = 0;
      for ( int i = 0; i < L; ++i ) {
         for ( int j = i; j < L; ++j ) {
            int cons = 0;
            for ( int k = i; k <= j; ++k ) {
               if ( isConsonant(word[k]) ) ++cons;
               else cons = 0;

               if ( cons == n ) {
                  ++cnt;
                  break;
               }
            }
         }
      }

      printf("Case #%d: %d\n", ++tcase, cnt);
   }
   return 0;
}
