#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <iostream>



bool process(size_t idx, size_t a_sum, size_t b_sum, std::vector<size_t> const & c, std::vector<size_t> & a, std::vector<size_t> & b)
{
   if (idx == c.size())
      return false;

   a_sum += c[idx];
   a.push_back(c[idx]);

   if (a_sum == b_sum)
      return true;

   if (process(idx + 1, a_sum, b_sum, c, a, b))
      return true;

   a_sum -= c[idx];
   a.pop_back();

   b_sum += c[idx];
   b.push_back(c[idx]);

   if (a_sum == b_sum)
      return true;

   if (process(idx + 1, a_sum, b_sum, c, a, b))
      return true;

   b_sum -= c[idx];
   b.pop_back();

   if (process(idx + 1, a_sum, b_sum, c, a, b))
      return true;

   return false;
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

      std::vector<size_t> c(N, 0);
      for (size_t l = 0; l != N; ++l)
         in >> c[l];

      std::vector<size_t> a, b;
      bool res = process(0, 0, 0, c, a, b);
      if (!res)
         out << "Case #" << X + 1 << ": Impossible" << std::endl;
      else
      {
         out << "Case #" << X + 1 << ":" << std::endl;
         for (size_t l = 0; l != a.size(); ++l)
         {
            out << a[l];
            if (l != a.size() - 1)
               out << " ";
         }

         out << std::endl;

         for (size_t l = 0; l != b.size(); ++l)
         {
            out << b[l];
            if (l != b.size() - 1)
               out << " ";
         }

         out << std::endl;
      }
   }
   return 0;
}


