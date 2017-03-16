#include <iostream>
#include <vector>
#include <algorithm>

#include <assert.h>

int main() {
  unsigned num_tests;
  std::cin >> num_tests;
  for (unsigned t = 1; t <= num_tests; ++t) {
    unsigned A, B;
    std::cin >> A >> B;

    unsigned max_d = 10;
    while (A / max_d != 0) {
      max_d *= 10;
    }

    unsigned __int64 cnt = 0;
    for (unsigned n = A; n < B; ++n) {
      unsigned m_prev[10];
      unsigned m_cnt = 0;
      for (unsigned d = 10; d != max_d; d *= 10) {
        unsigned m = (n % d) * (max_d / d) + (n / d);
        if (m > n && m <= B) {
          bool m_prev_found = false;
          for (unsigned m_idx = 0; m_idx < m_cnt; ++m_idx) {
            if (m_prev[m_idx] == m) {
              m_prev_found = true;
              break;
            }
          }
          if (!m_prev_found) {
            ++cnt;
            m_prev[m_cnt] = m;
            ++m_cnt;
          }
        }
      }
    }

    std::cout << "Case #" << t << ": " << cnt << "\n";
  }

  return 0;
}
