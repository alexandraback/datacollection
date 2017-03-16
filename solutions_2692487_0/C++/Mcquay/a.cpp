#include <iostream>
#include <string>
#include <vector>
#include <boost/range/algorithm/sort.hpp>

size_t process(size_t A, std::vector<size_t> data)
{
   if (A == 1)
      return data.size();

   boost::sort(data);

   size_t adds = 0;
   size_t curr = data.size();
   for (size_t l = 0; l != data.size(); ++l)
   {
      while (A <= data[l])
      {
         ++adds;
         A += A - 1;
      }

      A += data[l];
      curr = std::min(curr, adds + data.size() - l - 1);
   }

   return curr;
}

int main(int argc, char * argv[])
{
   size_t N = 0;
   std::cin >> N;

   for (size_t l = 0; l != N; ++l)
   {
      size_t A, M;
      std::cin >> A >> M;
      std::vector<size_t> data(M);
      for (size_t k = 0; k != M; ++k)
         std::cin >> data[k];

      std::cout << "Case #" << l + 1 << ": " << process(A, data) << std::endl;
   }
}

