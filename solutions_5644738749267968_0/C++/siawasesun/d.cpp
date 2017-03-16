#include <bits/stdc++.h>

using namespace std;

int N;
vector<double> P, Q;

void Input() {
  cin >> N;
  P.resize(N);
  Q.resize(N);
  for (int i = 0; i < N; i++) cin >> P[i];
  for (int i = 0; i < N; i++) cin >> Q[i];
}

int DeceitfulScore(vector<double> A, vector<double> B, int lie) {
  for (int i = 0; i < lie; i++) {
    A.erase(A.begin());
    B.erase(B.end() - 1);
  }
  int score = 0;
  for (int i = 0; i < A.size(); i++) {
    if (A[i] >= B[i]) {
      score++;
    }
  }
  return score;
}

int DeceitfulWar(vector<double> A, vector<double> B) {
  int score = 0;
  for (int lie = 0; lie < A.size(); lie++) {
    int current = DeceitfulScore(A, B, lie);
    if (score > current) {
      break;
    }
    score = current;
  }
  return score;
}

int War(vector<double> A, vector<double> B) {
  int score = 0;
  for (int i = 0; i < A.size(); i++) {
    auto it = lower_bound(B.begin(), B.end(), A[i]);
    if (it == B.end()) {
      score += B.size();
      break;
    } else {
      B.erase(it);
    }
  }
  return score;
}

void Solve() {
  sort(P.begin(), P.end());
  sort(Q.begin(), Q.end());

  int deceitfulWarScore = DeceitfulWar(P, Q);
  int warScore = War(P, Q);

  printf("%d %d", deceitfulWarScore, warScore);
}

int main(int argc, char **argv) {
  int T;
  scanf("%d", &T);

  for (int test_case = 1; test_case <= T; ++test_case) {
    Input();
    printf("Case #%d: ", test_case);
    Solve();
    printf("\n");
  }
  return 0;
}
