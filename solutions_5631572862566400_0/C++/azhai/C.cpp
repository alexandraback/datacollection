#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

const int N_MAX = 1100;

int N;
int bff[N_MAX];
bool can_cycle[N_MAX];
int friend_count[N_MAX];

int num_pairs; // actually counts each pair twice
int max_pair_dist[N_MAX]; // TODO
int pair_id[N_MAX];
int dist_to_pair[N_MAX];

void init() {
  cin >> N;
  num_pairs = 0;

  for (int i = 0; i < N_MAX; i++)
    max_pair_dist[i] = 0;

  for (int i = 0; i < N; i++) {
    friend_count[i] = 0;
    can_cycle[i] = true;
    pair_id[i] = -1;
    dist_to_pair[i] = -1;
  }

  for (int i = 0; i < N; i++) {
    cin >> bff[i];
    bff[i]--;
    friend_count[bff[i]]++;
  }
}


void compute_pair_info(int x) {
  if (pair_id[x] != -1)
    return;
  if (can_cycle[x]) {
    pair_id[x] = -2;
    return;
  }

  if (pair_id[bff[x]] == -1)
    compute_pair_info(bff[x]);
  pair_id[x] = pair_id[bff[x]];
  if (pair_id[x] != -2)
    dist_to_pair[x] = dist_to_pair[bff[x]] + 1;
}
void make_pairs() {
  for (int i = 0; i < N; i++) {
    if (pair_id[i] != -1)
      continue;
    assert(dist_to_pair[i] == -1);

    if (bff[bff[i]] == i) { // I am in a pair
      pair_id[i] = num_pairs++;
      assert(pair_id[bff[i]] == -1);
      pair_id[bff[i]] = num_pairs++;
      dist_to_pair[i] = dist_to_pair[bff[i]] = 0;
    }
  }

  // cout << "N: " << N << endl;
  // for (int i = 0; i < N; i++)
  //   cout << pair_id[i] << " ";

  for (int i = 0; i < N; i++)
    compute_pair_info(i);
}


void cull() {
  while (true) {
    bool culled_someone = false;
    for (int i = 0; i < N; i++) {
      if (can_cycle[i] && friend_count[i] == 0) {
        can_cycle[i] = false;
        friend_count[bff[i]]--;
        culled_someone = true;
      }
    }
    if (!culled_someone)
      break;
  }
}
int cycle_len(int x) {
  int cur = x;
  for (int i = 0; i < N + 1; i++) {
    cur = bff[cur];
    if (cur == x)
      return i + 1;
  }
  assert(false); // will fail for culled x
}


void solve_case(int t) {
  init();


  // cycle case
  cull();
  int cycle_answer = 0;
  for (int i = 0; i < N; i++) {
    if (can_cycle[i]) {
      cycle_answer = max(cycle_answer, cycle_len(i));
    }
  }

  // pairs case
  make_pairs();
  for (int i = 0; i < N; i++) {
    int p = pair_id[i];
    assert(p != -1);
    if (p == -2)
      continue;
    max_pair_dist[p] = max(max_pair_dist[p], dist_to_pair[i]);
  }
  int pairs_answer = 0;
  for (int p = 0; p < num_pairs; p++)
    pairs_answer += max_pair_dist[p] + 1;

  cout << "Case #" << t << ": " << max(pairs_answer, cycle_answer) << "\n";
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve_case(i + 1);
  }

  return 0;
}
