#include <cstring>
#include <iostream>
#include <vector>

const size_t kMaxS = 3;

struct Outfit {
  Outfit() = default;
  Outfit(int j, int p, int s) : j_(j), p_(p), s_(s) {}

  int j_ = 0;
  int p_ = 0;
  int s_ = 0;
};

unsigned PopCount(unsigned mask) {
  unsigned result = 0;
  for (; mask != 0; mask = mask & (mask - 1))
    ++result;
  return result;
}

void Solve(int j, int p, int s, int k, std::vector<Outfit> &outfits) {
  std::vector<Outfit> all;
  for (int x = 0; x < j; ++x) {
    for (int y = 0; y < p; ++y) {
      for (int z = 0; z < s; ++z)
        all.emplace_back(x, y, z);
    }
  }

  unsigned counts[3][kMaxS][kMaxS];
  for (unsigned mask = 0; mask < (1U << all.size()); ++mask) {
    if (PopCount(mask) <= outfits.size())
      continue;

    memset(counts, 0, sizeof(counts));

    bool ok = true;
    for (size_t i = 0; i < all.size(); ++i) {
      if ((mask & (1U << i)) == 0)
        continue;
      const auto &outfit = all[i];

      if (++counts[0][outfit.j_][outfit.p_] > k) {
        ok = false;
        break;
      }
      if (++counts[1][outfit.j_][outfit.s_] > k) {
        ok = false;
        break;
      }
      if (++counts[2][outfit.p_][outfit.s_] > k) {
        ok = false;
        break;
      }
    }

    if (!ok)
      continue;

    outfits.clear();
    for (size_t i = 0; i < all.size(); ++i) {
      if ((mask & (1U << i)) == 0)
        continue;
      outfits.emplace_back(all[i]);
    }
  }
}

int main() {
  int num_tests;
  std::cin >> num_tests;
  for (int test_num = 0; test_num < num_tests; ++test_num) {
    int j, p, s, k;
    std::cin >> j >> p >> s >> k;

    std::vector<Outfit> outfits;
    Solve(j, p, s, k, outfits);
    std::cout << "Case #" << (test_num + 1) << ": " << outfits.size()
              << std::endl;
    for (const auto &outfit : outfits) {
      std::cout << (outfit.j_ + 1) << " " << (outfit.p_ + 1) << " "
                << (outfit.s_ + 1) << std::endl;
    }
  }
  return 0;
}
