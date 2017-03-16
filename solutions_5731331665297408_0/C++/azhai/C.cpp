#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <cstring>

using namespace std;

const int N_MAX = 60;

int N, M;
int zips[N_MAX];
int ranks[N_MAX];
int by_ranking[N_MAX];

bool adj[N_MAX][N_MAX];

int perm[N_MAX];

void init() {
  memset(adj, 0, sizeof(adj));

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> zips[i];
  }

  int temp[N_MAX];
  for (int i = 0; i < N_MAX; i++)
    temp[i] = zips[i];
  sort(temp, temp + N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (zips[j] == temp[i]) {
        by_ranking[i] = j;
        ranks[j] = i;
      }
    }
  }

  // cout << "ranks";
  // for (int i = 0; i < N; i++)
  //   cout << by_ranking[i];
  // cout << endl;

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;

    int ra = ranks[a - 1], rb = ranks[b - 1];
    adj[ra][rb] = adj[rb][ra] = true;
  }

  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < N; j++)
  //     cout << adj[i][j];
  //   cout << endl;
  // }

}

bool trip_works() {
  vector<int> visit_stack;
  visit_stack.push_back(perm[0]);

  for (int i = 1; i < N; i++) {
    int next = perm[i];
    while (!adj[visit_stack.back()][next]) {
      visit_stack.pop_back();
      if (visit_stack.empty())
        return false;
    }
    visit_stack.push_back(next);
  }
  return true;
}

void solve_case(int t) {
  init();

  for (int i = 0; i < N; i++)
    perm[i] = i;
  do {
    if (trip_works()) {
      cout << "Case #" << t << ": ";
      for (int i = 0; i < N; i++)
        cout << zips[by_ranking[perm[i]]];
      cout << "\n";
      return;
    }

  } while (next_permutation(perm, perm + N));

  cout << "Can't find a valid trip!\n";
  assert(false);
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve_case(i + 1);
  }

  return 0;
}
