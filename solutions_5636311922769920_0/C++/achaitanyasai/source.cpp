#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define all(a)  a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define fill(a, x) memset(a, x, sizeof(a));
#define mod 1000000007
#define _for(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

using namespace std;

int main() {
   int T;
   cin >> T;
   int K, C, S;
   for(int test = 1; test <= T; ++test){
      scanf("%d%d%d", &K, &C, &S);
      printf("Case #%d: ", test);
      for(int i = 1; i <= K; ++i){
         if(i == K) printf("%d\n", i);
         else printf("%d ", i);
      }
   }
   return 0;
}