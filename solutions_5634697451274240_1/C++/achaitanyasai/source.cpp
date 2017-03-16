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

string S;

int get(){
   int res = 0;
   for(int n = S.sz - 1; n >= 0; --n){
      if(S[n] == '-'){
         ++res;
         for(int m = 0; m <= n; ++m){
            S[m] = (S[m] == '-' ? '+' : '-');
         }
      }
   }
   return res;
}

int main() {
   int T;
   cin >> T;
   for(int test = 1; test <= T; ++test){
      cin >> S;
      printf("Case #%d: %d\n", test, get());
      cerr << test << endl;
   }
   return 0;
}