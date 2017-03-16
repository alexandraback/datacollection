#include <bits/stdc++.h>

using namespace std;

#define MAX_STUDENTS 1000

int score_arrangement(int *circle, int *bffs, int sz) {
  auto left_happy = 0;
  for (auto i = 1; i <= sz; i++) {
    auto bff = bffs[circle[i % sz]];
    if (circle[(i + 1) % sz] == bff || circle[(i - 1) % sz] == bff)
      left_happy++;
    else
      break;
  }
  return left_happy;
}

int main() {
  auto test_count = 0;
  auto student_count = 0;
  int bffs[MAX_STUDENTS];
  int nums[MAX_STUDENTS];

  cin >> test_count;
  for (auto i = 0; i < test_count; i++) {
    cin >> student_count;
    for (int j = 0; j < student_count; j++) {
      int student_id = 0;
      cin >> student_id;
      bffs[j] = (student_id - 1);
      nums[j] = j;
    }
    auto max_score = 0;
    while (next_permutation(nums, nums + student_count)) {
      auto score = score_arrangement(nums, bffs, student_count);
      if (score > max_score)
        max_score = score;
      if (score == student_count)
        break;
    }
    cout << "Case #" << (i+1) << ": " << max_score << endl;
  }
  return 0;
}
