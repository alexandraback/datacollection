#include <iostream>
#include <math.h>

size_t sqr(size_t A) { return A * A; }
size_t step(size_t A) { return (A + 2) * (A + 1) / 2; }

double C(size_t N, size_t K)
{
   double res = 1;
   for (size_t l = K + 1, lk = 1; l != N + 1; ++l, ++lk)
      res *= l * 1. / lk;

   return res;
}

double calc(size_t N, size_t X, size_t Y)
{
   size_t c = X + Y;

   if (c == 0)
      return 1;

   size_t s = step(c - 2);
   if (s > N)
      return 0;

   N -= s;

   if (N >= 2 * c + 1)
      return 1;

   if (X == 0)
      return 0;

   if (N > c + Y)
      return 1;

   if (N < Y + 1)
      return 0;

   if (N > c)
   {
      size_t h = N - c;
      N -= 2 * h;
      c -= h;
      Y -= h;
   }

   double res = 0;
   for (size_t l = Y + 1; l <= N; ++l)
      res += C(N, l);

   return ldexp(res, -N);
}

int main(int argc, char * argv[])
{
   size_t N = 0;
   std::cin >> N;

   for (size_t l = 0; l != N; ++l)
   {
      size_t A, Y;
      int X;
      std::cin >> A >> X >> Y;

      std::cout << "Case #" << l + 1 << ": " << calc(A, abs(X), Y) << std::endl;
   }
}

