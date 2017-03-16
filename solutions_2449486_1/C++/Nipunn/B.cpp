#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <algorithm>

using namespace std;

typedef multimap<int, pair<int, int> > MapType;

void go() {
   int N, M;
   cin >> N >> M;

   MapType lookup;
   int h[105][105];
   for (int i=0; i<N; i++) {
      for (int j=0; j<M; j++) {
         cin >> h[i][j];
         lookup.insert(make_pair(h[i][j], make_pair(i, j)));
      }
   }

   bool seen[105][105];
   memset(seen, 0, sizeof(seen));
   for (MapType::iterator it = lookup.begin(), end = lookup.end();
         it != end; ++it) {
      int ii = it->second.first;
      int jj = it->second.second;

      if (seen[ii][jj])
         continue;

      bool canCut = true;
      for (int i=0; i<N; i++)
         if (!seen[i][jj] && h[i][jj] > h[ii][jj])
            canCut = false;
      if (canCut) {
         for (int i=0; i<N; i++)
            seen[i][jj] = true;
         continue;
      }

      canCut = true;
      for (int j=0; j<M; j++)
         if (!seen[ii][j] && h[ii][j] > h[ii][jj])
            canCut = false;
      if (canCut) {
         for (int j=0; j<M; j++)
            seen[ii][j] = true;
         continue;
      }

      // FAIL
      cout << "NO\n";
      return;
   }

   cout << "YES\n";
}

int main() {
   int T;
   cin >> T;
   for (int i=1; i<=T; i++) {
      cout << "Case #" << i << ": ";
      go();
   }
}
