#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <iostream>
#include <boost/cstdint.hpp>

typedef std::pair<boost::uint64_t, size_t> elem_t;

boost::uint64_t man(boost::uint64_t pr, size_t b, size_t t, std::vector<elem_t> boxes, std::vector<elem_t> toys)
{
   while (b < boxes.size() && t < toys.size() && toys[t].second == boxes[b].second)
   {
      boost::uint64_t crpr = std::min(boxes[b].first, toys[t].first);
      toys[t].first -= crpr;
      boxes[b].first -= crpr;
      pr += crpr;

      if (toys[t].first == 0)
         ++t;

      if (boxes[b].first == 0)
         ++b;
   }

   boost::uint64_t pr1 = pr;
   boost::uint64_t pr2 = pr;

   if (b + 1 < boxes.size())
      pr1 = man(pr, b + 1, t, boxes, toys);

   if (t + 1 < toys.size())
      pr2 = man(pr, b, t + 1, boxes, toys);

   return std::max(pr1, pr2);
}

boost::uint64_t process(std::vector<elem_t> const & boxes, std::vector<elem_t> const & toys)
{
   return man(0, 0, 0, boxes, toys);
}

int main(int argc, char * argv[])
{
   std::ifstream in(argv[1]);
   std::ofstream out(argv[2]);

   size_t T = 0;
   in >> T;

   for (size_t X = 0; X != T; ++X)
   {
      size_t N, M;
      in >> N >> M;

      std::vector<std::pair<boost::uint64_t, size_t> > boxes(N);
      std::vector<std::pair<boost::uint64_t, size_t> > toys(M);

      for (size_t l = 0; l != N; ++l)
         in >> boxes[l].first >> boxes[l].second;

      for (size_t l = 0; l != M; ++l)
         in >> toys[l].first >> toys[l].second;

      out << "Case #" << X + 1 << ": " << process(boxes, toys) << std::endl;
   }
   return 0;
}


