#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <queue>

bool diamond(size_t i, std::vector<std::vector<size_t> > const & g)
{
   std::vector<bool> vis(g.size(), false);

   std::queue<size_t> next;
   next.push(i);

   while (!next.empty())
   {
      size_t c = next.front();
      next.pop();

      if (vis[c])
         return true;

      vis[c] = true;

      for (size_t l = 0; l != g[c].size(); ++l)
         next.push(g[c][l]);
   }

   return false;
}

bool diamond(std::vector<std::vector<size_t> > const & g)
{
   for (size_t l = 0; l != g.size(); ++l)
   {
      if (diamond(l, g))
         return true;
   }

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

      std::vector<std::vector<size_t> > graph(N);
      for (size_t l = 0; l != N; ++l)
      {
         size_t M;
         in >> M;

         graph[l].resize(M);

         for (size_t k = 0; k != M; ++k)
         {
            in >> graph[l][k];
            --graph[l][k];
         }
      }

      if (diamond(graph))
         out << "Case #" << X + 1 << ": Yes" << std::endl;
      else
         out << "Case #" << X + 1 << ": No" << std::endl;
   }

   return 0;
}

