#include <fstream>
#include <vector>
#include <algorithm>

size_t process(size_t N, size_t S, size_t p, std::vector<size_t> const & t)
{
   for (size_t l = 0; l != t.size(); ++l)
   {
      size_t m = t[l] / 3;
      size_t r = t[l] % 3;

      // surpriseless and more than p
      if (m + (r ? 1 : 0) >= p)
         continue;

      // surprises won't help
      if (m + std::max(r, m ? 1U : 0U) < p)
      {
         --N;
         continue;
      }

      if (S)
      {
         --S;
         continue;
      }

      --N;
   }

   return N;
}

int main(int argc, char * argv[])
{
   std::ifstream in(argv[1]);
   std::ofstream out(argv[2]);

   size_t T = 0;
   in >> T;

   for (size_t X = 0; X != T; ++X)
   {
      size_t N, S, p;
      in >> N >> S >> p;
      std::vector<size_t> t(N, 0);
      for (size_t l = 0; l != N; ++l)
         in >> t[l];

      size_t res = process(N, S, p, t);

      out << "Case #" << X + 1 << ": " << res << std::endl;
   }
   return 0;
}

