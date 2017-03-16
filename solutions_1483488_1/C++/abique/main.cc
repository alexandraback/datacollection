#include <iostream>

static int get_base(int n)
{
  int base = 1;
  while (n >= 10) {
    base *= 10;
    n /= 10;
  }
  return base;
}

static int count_recycled(int A, int B, int base, int n)
{
  int n2 = n;
  int nb = 0;

  while (true) {
    n2 = n2 / 10 + (n2 % 10) * base;
    if (n2 > n || n2 < A)
      continue;
    if (n2 == n)
      return nb;
    ++nb;
  }
}

int main()
{
  int ntests;
  int A;
  int B;

  std::cin >> ntests;

  for (int i = 0; i < ntests; ++i) {
    std::cin >> A >> B;

    const int base = get_base(B);
    int       res  = 0;

#pragma omp parallel
    for (int j = B; j >= A; --j)
      res += count_recycled(A, B, base, j);

    std::cout << "Case #" << (i + 1) << ": " << res << std::endl;
  }
  return 0;
}
