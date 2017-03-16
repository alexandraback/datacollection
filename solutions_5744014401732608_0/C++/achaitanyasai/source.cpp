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

int N;
long long M;

bool check(long long x){
   long long p = 1ll << (long long)(N - 2);
   if(x && (!(x&(x-1))) && p >= x) return true;
   return false;
}

int main() {
   int T;
   cin >> T;
   for(int test = 1; test <= T; ++test){
      scanf("%d%lld", &N, &M);
      if(check(M)){
         printf("Case #%d: POSSIBLE\n", test);
         long long k = N;
         while(true){
            if(M == (1ll << (long long)k)) break;
            else --k;
         }
         ++k;
         for(int n = 0; n < N; ++n){
            for(int m = 0; m < N; ++m){
               if(k){
                  if(n < m){
                     cout << "1";
                  }
                  else{
                     cout << "0";
                  }
               }
               else{
                  cout << "0";
               }
            }
            if(k) k--;
            cout << endl;
         }
      }
      else{
         printf("Case #%d: IMPOSSIBLE\n", test);
      }
   }
   return 0;
}