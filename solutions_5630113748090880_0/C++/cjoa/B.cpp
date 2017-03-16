#include <iostream>

#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

VI solve(int N, VVI& lists) {
   VI res;
   map<int,int> freq;
   for (VI& L : lists) {
      for (int x : L)
         ++freq[x];
   }
   for (auto it : freq) {
      if (it.second & 1)
         res.push_back(it.first);
   }
   sort(res.begin(), res.end());
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
      VVI lists(2*N-1, VI(N));
      for (int i = 0; i < 2*N-1; ++i) {
         for (int j = 0; j < N; ++j)
            cin >> lists[i][j];
      }
      VI res = solve(N, lists);
      cout << "Case #" << tc << ":";
      for (int x : res)
         cout << ' ' << x;
      cout << endl;
   }

   return 0;
}
