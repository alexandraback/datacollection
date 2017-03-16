#include <iostream>

#include <algorithm>

using namespace std;

int N, M;
int A[104][104];
int max_row[104];
int max_col[104];

bool check() {
   for (int i = 0; i < N; ++i) {
      max_row[i] = 0;
      for (int j = 0; j < M; ++j)
         max_row[i] = max(max_row[i], A[i][j]);
   }
   for (int j = 0; j < M; ++j) {
      max_col[j] = 0;
      for (int i = 0; i < N; ++i)
         max_col[j] = max(max_col[j], A[i][j]);
   }
   for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j)
         if (A[i][j] != max_row[i] && A[i][j] != max_col[j])
            return false;
   return true;
}

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   int TC;
   cin >> TC;
   for (int tc = 1; tc <= TC; ++tc) {
      cin >> N >> M;
      for (int i = 0; i < N; ++i)
         for (int j = 0; j < M; ++j)
            cin >> A[i][j];
      cout << "Case #" << tc << ": " << (check() ? "YES" : "NO") << endl;
   }

   return 0;
}
