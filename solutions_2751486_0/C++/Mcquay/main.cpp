#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <queue>
#include <boost/range/algorithm/find.hpp>

bool vowel(char c)
{
   char vowels[] = {'a', 'e', 'i', 'o', 'u'};
   return boost::find(vowels, c) != boost::end(vowels);
}

size_t process(std::string const & s, size_t n)
{
   size_t len = 0;
   size_t res = 0;
   size_t cl = 0;
   for (size_t l = s.size() - 1; l != -1; --l)
   {
      if (vowel(s[l]))
      {
         res += len;
         cl = 0;
      }
      else
      {
         if (++cl >= n)
         {
            cl = n;
            len = s.size() - l - n + 1;
         }

         res += len;
      }
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
      std::string s;
      size_t n;
      in >> s >> n;

      out << "Case #" << X + 1 << ": " << process(s, n) << std::endl;
   }
   return 0;
}

