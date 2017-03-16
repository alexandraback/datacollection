#include <iostream>
#include <algorithm>

using namespace std;

const int N_MAX = 200;

int A, N;
int motes[N_MAX];

void init() {
  cin >> A >> N;
  for (int i = 0; i < N; i++)
    cin >> motes[i];
  sort(motes, motes + N);
}

void solve_case(int t) {
  init();

  int answer = N;
  int num_created = 0;
  int cur_size = A;

  if (cur_size == 1) {
    cout << "Case #" << t << ": " << N << "\n";
    return;
  }

  for (int i = 0; i < N; i++) {
    int num_left = N - i - 1;

    while (cur_size <= motes[i]) {
      num_created++;
      cur_size += cur_size - 1;
    }

    cur_size += motes[i];
    answer = min(answer, num_left + num_created);
  }

  cout << "Case #" << t << ": " << answer << "\n";
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve_case(i + 1);
  }

  return 0;
}
