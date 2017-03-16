#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

#include <boost/multi_array.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/range/algorithm.hpp>
#include <map>

struct point
{
   point(int x, int y)
      : x(x)
      , y(y)
   {}

   point()
      : x(0)
      , y(0)
   {}

   bool operator < (point const & p) const
   {
      return x < p.x || (x == p.x && y < p.y);
   }

   bool operator == (point const & p) const
   {
      return x == p.x && y == p.y;
   }

   bool operator != (point const & p) const
   {
      return !(p == *this);
   }

   point operator * (int n) const
   {
      return point(x * n, y * n);
   }

   point operator + (point const & p) const
   {
      return point(x + p.x, y + p.y);
   }

   int x, y;
};

char move(point const & p, point const & prev)
{
   if (p.x == prev.x)
   {
      if (prev.y < p.y)
         return 'N';

      return 'S';
   }
   else
   {
      if (prev.x < p.x)
         return 'E';

      return 'W';
   }

   return 'W';
}

std::string process(int x, int y)
{
   std::map<point, point> visited;

   std::queue<boost::tuple<point, size_t> > dfs;
   dfs.push(boost::make_tuple(point(), 1));

   point mvs[] =
   {
      point(-1, 0),
      point(1, 0),
      point(0, -1),
      point(0, 1)
   };

   visited[point()] = point();

   while (!dfs.empty())
   {
      size_t n;
      point p;
      boost::tie(p, n) = dfs.front();
      dfs.pop();

      if (p == point(x, y))
         break;

      for (size_t l = 0; l != 4; ++l)
      {
         point nxt = mvs[l] * n + p;
         if (visited.find(nxt) == visited.end())
         {
            visited[nxt] = p;
            dfs.push(boost::make_tuple(nxt, n + 1));
         }
      }
   }

   std::vector<char> moves;
   point s = point(x, y);
   while (s != point())
   {
      moves.push_back(move(s, visited[s]));
      s = visited[s];
   }

   boost::reverse(moves);
   moves.push_back(0);
   return &moves[0];
}

int main(int argc, char * argv[])
{
   std::ifstream in(argv[1]);
   std::ofstream out(argv[2]);

   size_t T = 0;
   in >> T;

   for (size_t X = 0; X != T; ++X)
   {
      int x, y;
      in >> x >> y;

      out << "Case #" << X + 1 << ": " << process(x, y) << std::endl;
   }
   return 0;
}

