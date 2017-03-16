#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

bool try_fail(double t, size_t i, std::vector<size_t> const & s, size_t sum)
{
   double res = s[i] + sum * t;
   double rest = 1 - t;

   for (size_t l = 0; l != s.size(); ++l)
   {
      if (l == i)
         continue;

      if (s[l] > res)
         continue;

      double p = (res - s[l]) / sum;
      if (p > rest)
         return false;

      rest -= p;
   }

   return true;
}

double process(size_t i, std::vector<size_t> const & s, size_t sum)
{
   double l = 0;
   double u = 1;

   while (u - l > 1e-10)
   {
      if (try_fail((l + u) / 2, i, s, sum))
         l = (l + u) / 2;
      else
         u = (l + u) / 2;
   }

   return u;
}

int main(int argc, char * argv[])
{
   std::ifstream in(argv[1]);
   std::ofstream out(argv[2]);

   size_t T = 0;
   in >> T;

   for (size_t X = 0; X != T; ++X)
   {
      size_t N;
      in >> N;
      std::vector<size_t> s(N, 0);
      for (size_t l = 0; l != N; ++l)
         in >> s[l];

      out.precision(10);

      out << "Case #" << X + 1 << ":";

      size_t sum = std::accumulate(s.begin(), s.end(), 0);

      for (size_t l = 0; l != N; ++l)
         out << " " << std::fixed << process(l, s, sum) * 100;

      out << std::endl;
   }
   return 0;
}

