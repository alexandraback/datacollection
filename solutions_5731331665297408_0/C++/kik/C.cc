#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct state
{
  int cur;
  int ret[8][8];
  bool done[8];
};


bool check_route_rec(int route[8], int N, int i, bool f[8][8], const state& st)
{
  if (i == N) return true;

  for (int j = 0; j < N; j++) {
    if (st.ret[st.cur][j] > 0) {
      state nst = st;
      nst.ret[nst.cur][j]--;
      nst.cur = j;
      if (check_route_rec(route, N, i, f, nst)) {
        return true;
      }
    }
  }
  if (f[st.cur][route[i]]) {
    state nst = st;
    nst.ret[route[i]][nst.cur]++;
    nst.cur = route[i];
    if (check_route_rec(route, N, i+1, f, nst)) {
      return true;
    }
  }
  return false;
}

bool check_route(int route[8], int N, bool f[8][8])
{
  state s;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      s.ret[i][j] = 0;
    }
    s.done[i] = false;
  }
  s.cur = route[0];
  s.done[s.cur] = true;
  return check_route_rec(route, N, 1, f, s);
}

int main()
{
  int T;

  cin >> T;

  for (int cas = 1; cas <= T; cas++) {
    int N, M;

    cin >> N >> M;

    string zip[8];
    bool f[8][8] = {{ 0 }};

    for (int i = 0; i < N; i++) {
      cin >> zip[i];
    }
    for (int i = 0; i < M; i++) {
      int from, to;
      cin >> from >> to;
      f[from - 1][to - 1] = true;
      f[to - 1][from - 1] = true;
    }

    int route[8];
    for (int i = 0; i < N; i++) {
      route[i] = i;
    }

    string min_score;
    do {
      if (check_route(route, N, f)) {
        string score = "";
        for (int i = 0; i < N; i++) {
          score += zip[route[i]];
        }
        if (min_score.empty() || min_score > score) {
          min_score = score;
        }
      }
    } while (next_permutation(route, route + N));

    cout << "Case #" << cas << ": " << min_score << endl;
  }

  return 0;
}
