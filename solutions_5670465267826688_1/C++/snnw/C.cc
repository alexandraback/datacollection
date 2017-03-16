
#include <cassert>
#include <iostream>
#include <vector>

int Q[5][5] = {{+9, +9, +9, +9, +9},
               {+9, +1, +2, +3, +4},
               {+9, +2, -1, +4, -3},
               {+9, +3, -4, -1, +2},
               {+9, +4, +3, -2, -1}};

int times(int q, int r) {
  int result = 1;
  if (q < 0) {
    q = -q;
    result = -1;
  }

  if (r < 0) {
    r = -r;
    result *= -1;
  }

  return result * Q[q][r];
}

char q_to_bit(int q) {
  if (q > 0) {
    q -= 1;
  } else {
    q += 8;
  }
  return 1 << q;
}

long long find_q(const std::string &l, long long start, long long X, int L,
                 int q) {
  static std::vector<char> cycles;
  cycles.resize(L);
  for (auto &c : cycles) c = 0;

  int value = 1;
  long long i = start;

  for (; i < X * L; i++) {
    int qq = l[i % L] - 'g';
    value = times(value, qq);

    if ((cycles[i % L] & q_to_bit(value)) > 0) break; // CYCLE!
    cycles[i % L] |= q_to_bit(value);

    if (value == q) return i + 1;
  }

  return -1;
}

int q_to_the_n(int q, long long n) {
	if (q == 1) return 1;
	if (q == -1) return n % 2 == 0 ? 1 : -1;

  switch (n % 4) {
    case 0:
      return 1;
    case 1:
      return q;
    case 2:
      return -1;
    default:
    	return -q;
  }
}

// check if l[start..end) is the identity.
bool is_one(const std::string &l, long long start, long long end, long long X,
            int L) {
  int pre = 1;
  int post = 1;

  int mid = 1;
  for (int i = 0; i < L; i++) {
    int qq = l[i] - 'g';
    mid = times(mid, qq);
  }

  for (; start < end && start % L != 0; start++) {
    int qq = l[start % L] - 'g';
    pre = times(pre, qq);
  }

  {
  	// end is inclusive during this block
    end--;
    while (start <= end && end % L != L - 1) {
      int qq = l[end % L] - 'g';
      post = times(qq, post);
      end--;
    }
    end++;
  }

  long long repeats = (end - start) / L;
  mid = q_to_the_n(mid, repeats);

  int final = times(pre, times(mid, post));

  return final == 1;
}

long long rfind_q(const std::string &l, long long end, long long X, int L,
                  int q) {
  static std::vector<char> cycles;
  cycles.resize(L);
  for (auto &c : cycles) c = 0;

  int value = 1;
  long long i = end;

  for (; i >= 0; i--) {
    int qq = l[i % L] - 'g';
    value = times(qq, value);

    if ((cycles[i % L] & q_to_bit(value)) > 0) break; // CYCLE!
    cycles[i % L] |= q_to_bit(value);
    
    if (value == q) return i;
  }

  return -1;
}

int main() {
  int T;
  std::cin >> T;

  for (int test = 1; test <= T; test++) {
    long long X;
    int L;

    std::cin >> L >> X;

    std::string l;
    std::cin >> l;

    long long i, j, k, one;
    if ((i = find_q(l, 0, X, L, 2)) == -1) {
      printf("Case #%d: NO\n", test);
      continue;
    }

    fprintf(stderr, "i: %lld\n", i);

    if ((j = find_q(l, i, X, L, 3)) == -1) {
      printf("Case #%d: NO\n", test);
      continue;
    }

    fprintf(stderr, "j: %lld\n", j);

    if ((k = rfind_q(l, L * X - 1, X, L, 4)) == -1) {
      printf("Case #%d: NO\n", test);
      continue;
    }

    fprintf(stderr, "k: %lld\n", k);

    // int val = 1;
    // for (long long m = k; m < L * X; m++) {
    // 	int qq = l[m % L] - 'g';
    // 	val = times(val, qq);
    // }

    // if (val != 1) {
    // 	printf("Case #%d: NO\n", test);
    // 	continue;
    // }

    if (!is_one(l, j, k, X, L)) {
      printf("Case #%d: NO\n", test);
      continue;
    }

    printf("Case #%d: YES\n", test);
  }
}