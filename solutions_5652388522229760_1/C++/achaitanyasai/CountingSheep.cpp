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

long long get(int x){
   set<int> S;
   map<long long, bool> vis;
   long long p = x;
   int curr = 1;
   long long q;
   long long y;
   while(true){
      q = (x * 1ll * curr);
      if(vis[q]) break;
      vis[q] = 1;
      y = q;
      if(y == 0){
         S.insert((int)0);
      }
      while(y){
         S.insert(y % 10);
         y /= 10;
      }
      if(S.sz == 10) return q;
      ++curr;
   }
   return -1;
}

int main() {
   int T;
   cin >> T;
   for(int test = 1; test <= T; ++test){
      scanf("%d", &N);
      long long res = get(N);
      cerr << test << endl;
      if(res == -1){
         printf("Case #%d: INSOMNIA\n", test);    
      }
      else{
         printf("Case #%d: %lld\n", test, res);    
      }
   }
   return 0;
}