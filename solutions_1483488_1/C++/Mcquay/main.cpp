#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <iostream>

void rot(size_t & m, size_t pw)
{
   size_t t = m % 10;
   m /= 10;
   m += pw * t;
}

size_t try_n(size_t n, size_t A, size_t B, size_t digs, size_t pw)
{
   std::set<size_t> ms;
   size_t res = 0;
   size_t m = n;
   for (size_t l = 0; l != digs; ++l)
   {
      rot(m, pw);
      if (m > n && m <= B)
      {
         if (ms.find(m) == ms.end())
            ++res;
         else
            std::cout << n << " " << m << std::endl;

         ms.insert(m);
      }
   }

   return res;
}

size_t digits(size_t A)
{
   size_t res = 0;
   while (A)
   {
      ++res;
      A /= 10;
   }

   return res;
}

size_t process(size_t A, size_t B)
{
   size_t digs = digits(A);
   size_t pw = pow(10, digs - 1);

   size_t res = 0;
   for (size_t l = A; l != B; ++l)
   {
      res += try_n(l, A, B, digs, pw);
   }

   return res;
}

int main(int argc, char * argv[])
{
   std::ifstream in(argv[1]);
   std::ofstream out(argv[2]);

   size_t T = 0;
   in >> T;

   for (size_t X = 0; X != T; ++X)
   {
      size_t A, B;
      in >> A >> B;

      size_t res = process(A, B);

      out << "Case #" << X + 1 << ": " << res << std::endl;
   }
   return 0;
}


