#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <iostream>
#include <boost/cstdint.hpp>
#include <queue>
#include <map>

struct tribe
{
   size_t d;
   size_t id;
   size_t n;
   int w, e, s;
   int dd, dp, ds;

   operator bool () const
   {
      return n != 0;
   }

   tribe & operator ++ ()
   {
      --n;
      w += dp;
      e += dp;
      s += ds;
      d += dd;
   }

   bool operator < (tribe const & t) const
   {
      if (d < t.d)
         return true;
      if (d > t.d)
         return false;

      if (id < t.id)
         return true;

      return false;
   }

   bool operator > (tribe const & t) const
   {
      return t < *this;
   }

   friend std::istream & operator >> (std::istream & in, tribe & t)
   {
      return in >> t.d >> t.n >> t.w >> t.e >> t.s >> t.dd >> t.dp >> t.ds;
   }
};

struct wall
{
   bool success(tribe const & t)
   {
      for (int w = t.w; w != t.e; ++w)
         if (height[w] < t.s)
            return true;
   }

   void update(tribe const & t)
   {
      for (int w = t.w; w != t.e; ++w)
         height[w] = std::max(t.s, height[w]);
   }

   std::map<int, int> height;
};

size_t process(std::vector<tribe> const & tribes)
{
   wall w;

   std::priority_queue<tribe, std::vector<tribe>, std::greater<tribe> > pq;
   for (size_t l = 0; l != tribes.size(); ++l)
      pq.push(tribes[l]);

   size_t res = 0;
   while (!pq.empty())
   {
      std::vector<tribe> tribes;
      tribes.push_back(pq.top());
      pq.pop();

      while (!pq.empty() && pq.top().d == tribes[0].d)
      {
         tribes.push_back(pq.top());
         pq.pop();
      }

      for (size_t l = 0; l != tribes.size(); ++l)
         if (w.success(tribes[l]))
            ++res;

      for (size_t l = 0; l != tribes.size(); ++l)
      {
         w.update(tribes[l]);
         if (++tribes[l])
            pq.push(tribes[l]);
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
      size_t N;
      in >> N;
      std::vector<tribe> tribes(N);
      for (size_t l = 0; l != N; ++l)
      {
         in >> tribes[l];
         tribes[l].id = l;
      }

      out << "Case #" << X + 1 << ": " << process(tribes) << std::endl;
   }

   return 0;
}


