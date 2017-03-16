#include <iostream>

#include <vector>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

#define SZ(a) int((a).size())
#define BITCOUNT(mask) ( __builtin_popcountll((mask)) )

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;

bool check(VI& F, VI V) {
   sort(V.begin(), V.end());
   const int M = V.size();
   do {
      bool ok = true;
      for (int i = 0; i < SZ(V); ++i) {
         int u = V[i];
         if (V[(i+M-1)%M] != F[u] && V[(i+1)%M] != F[u]) {
            ok = false;
            break;
         }
      }
      if (ok) return true;
   } while (next_permutation(V.begin()+1, V.end()));
   return false;
}

int solve(int N, VI& F) {
   for (int u = 0; u < N; ++u)
      F[u]--;

   int res = 0;
   for (int mask = (1<<N)-1; mask > 0; --mask) {
      int bc = BITCOUNT(mask);
      if (bc <= res) continue;
      VI V;
      for (int i = 0; i < N; ++i)
         if (mask & (1<<i))
            V.push_back(i);
      if (check(F, V))
         res = bc;
   }

   return res;
}

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   int TC;
   cin >> TC;
   for (int tc = 1; tc <= TC; ++tc) {
      int N;
      cin >> N;
      VI F(N);
      for (int i = 0; i < N; ++i)
         cin >> F[i];
      int res = solve(N, F);
      cout << "Case #" << tc << ": " << res << '\n';
   }

   return 0;
}
