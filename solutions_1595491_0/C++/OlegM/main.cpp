#include <iostream>
#include <vector>
#include <algorithm>

#include <assert.h>

int main() {
  unsigned num_tests;
  std::cin >> num_tests;
  for (unsigned t = 1; t <= num_tests; ++t) {
    unsigned num_googlers;
    std::cin >> num_googlers;
    unsigned num_surpr;
    std::cin >> num_surpr;
    unsigned min_best_score;
    std::cin >> min_best_score;
    std::vector<unsigned> total_scores;
    total_scores.reserve(num_googlers);
    for (unsigned i = 0; i < num_googlers; ++i) {
      unsigned score;
      std::cin >> score;
      total_scores.push_back(score);
    }

    std::sort(total_scores.begin(), total_scores.end(), std::greater<unsigned>());

    unsigned score_cnt = 0;
    for (unsigned i = 0; i < num_googlers; ++i) {
      unsigned total_score = total_scores[i];
      unsigned score1 = total_score / 3;
      total_score -= score1;
      unsigned score2 = total_score / 2;
      total_score -= score2;
      unsigned score3 = total_score;
      if (score3 >= min_best_score) {
        ++score_cnt;
      }
      else {
        if (num_surpr != 0) {
          if (score1 == score3 && score1 != 0) {
            --score1;
            ++score3;
          }
          if (score2 == score3 && score2 != 0) {
            --score2;
            ++score3;
          }
          if (score3 >= min_best_score) {
            ++score_cnt;
            --num_surpr;
          }
        }
      }
    }

    std::cout << "Case #" << t << ": " << score_cnt << "\n";
  }

  return 0;
}
