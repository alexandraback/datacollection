#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

struct Level {
  int id, one_star, two_star;
};

const int N_MAX = 2000;

int N;
int num_games;
int cur_stars;
int num_stars[N_MAX];
Level levels[N_MAX];

Level by_two_star[N_MAX];
Level by_one_star[N_MAX];
int one_cursor, two_cursor;

bool comp_one_star(Level a, Level b) {

  return a.one_star < b.one_star;
}
bool comp_two_star(Level a, Level b) {
  return a.two_star < b.two_star;
}

bool attempt_two_star() {
  if (two_cursor >= N)
    return false;

  Level l = by_two_star[two_cursor];
  assert(num_stars[l.id] < 2);

  if (l.two_star <= cur_stars) {
    cur_stars += 2 - num_stars[l.id];
    num_stars[l.id] = 2;
    two_cursor++;
    num_games++;
    return true;
  }
  return false;
}

bool attempt_one_star() {
  int best_ix = -1;
  for (int i = 0; i < N; i++) {
    Level l = levels[i];
    if (num_stars[l.id] > 0 || l.one_star > cur_stars)
      continue;
    if (best_ix == -1 || l.two_star > levels[best_ix].two_star)
      best_ix = i;
  }

  if (best_ix == -1)
    return false;
  num_stars[levels[best_ix].id] = 1;
  cur_stars++;
  num_games++;
  return true;
}

void solve_case(int case_num) {
  num_games = one_cursor = two_cursor = cur_stars = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    levels[i].id = i;
    cin >> levels[i].one_star >> levels[i].two_star;
    by_one_star[i] = levels[i];
    by_two_star[i] = levels[i];
    num_stars[i] = 0;
  }

  //  if (N > 5) return;

  //  sort(by_one_star, by_one_star + N, comp_one_star);
  sort(by_two_star, by_two_star + N, comp_two_star);

  for (int i = 0; i <= N; i++) {
    while (attempt_two_star());
    if (two_cursor >= N)
      break;
    if (!attempt_one_star())
      break;
  }

  cout << "Case #" << case_num << ": ";
  if (two_cursor < N)
    cout << "Too Bad\n";
  else
    cout << num_games << '\n';
}

int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++)
    solve_case(i);
}
