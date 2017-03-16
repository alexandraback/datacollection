#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

double access_time(double H, size_t M, size_t x, size_t y, size_t xa, size_t ya, std::vector<int> const & c, std::vector<int> const & f)
{
   size_t c0 = x + y * M;
   size_t ca = xa + ya * M;

   if (c[c0] - f[ca] < 50)
      return -1;

   if (c[ca] - f[ca] < 50)
      return -1;

   if (c[ca] - f[c0] < 50)
      return -1;

   if (H <= f[c0])
      return 0;

   if (c[ca] - H >= 50)
      return 0;

   return (50. - (c[ca] - H)) / 10.;
}

std::vector<bool> calc_reachable(int H, size_t M, std::vector<int> const & c, std::vector<int> const & f)
{
   std::vector<bool> res(c.size(), false);

   std::queue<size_t> cells;
   cells.push(0);

   size_t N = c.size() / M;

   while (!cells.empty())
   {
      size_t c0 = cells.back();
      cells.pop();

      if (res[c0])
         continue;

      res[c0] = true;

      size_t x = c0 % M;
      size_t y = c0 / M;

      if (x < M - 1 && !res[x + 1 + y * M] && access_time(H, M, x, y, x + 1, y, c, f) == 0)
         cells.push(x + 1 + y * M);

      if (x > 0 && !res[x - 1 + y * M] && access_time(H, M, x, y, x - 1, y, c, f) == 0)
         cells.push(x - 1 + y * M);

      if (y > 0 && !res[x + (y - 1) * M] && access_time(H, M, x, y, x, y - 1, c, f) == 0)
         cells.push(x + (y - 1) * M);

      if (y < N - 1 && !res[x + (y + 1) * M] && access_time(H, M, x, y, x, y + 1, c, f) == 0)
         cells.push(x + (y + 1) * M);
   }

   return res;
}

struct comp
{
   bool operator () (std::pair<double, size_t> const & a, std::pair<double, size_t> const & b)
   {
      return b < a;
   }
};

double path(size_t x, size_t y, double H, size_t M, std::vector<int> const & c, std::vector<int> const & f)
{
   std::vector<double> times(c.size(), std::numeric_limits<double>::max());

   std::priority_queue<std::pair<double, size_t>, std::vector<std::pair<double, size_t> >, std::greater<std::pair<double, size_t> > > closest;
   closest.push(std::make_pair(0, x + y * M));

   size_t N = c.size() / M;

   while (!closest.empty())
   {
      std::pair<double, size_t> cell = closest.top();
      closest.pop();

      if (times[cell.second] != std::numeric_limits<double>::max())
         continue;

      if (cell.second == c.size() - 1)
         return cell.first;

      times[cell.second] = cell.first;

      size_t x = cell.second % M;
      size_t y = cell.second / M;

      double cur_h = std::max(H - 10 * cell.first, 0.);

      if (x < M - 1 && times[x + 1 + y * M] == std::numeric_limits<double>::max())
      {
         double at = access_time(cur_h, M, x, y, x + 1, y, c, f);
         if (at >= 0)
         {
            double move_h = std::max(H - 10 * (cell.first + at), 0.);
            double trans_time = 10;
            if (f[cell.second] + 20 <= move_h)
               trans_time = 1;

            closest.push(std::make_pair(cell.first + at + trans_time, x + 1 + y * M));
         }
      }

      if (x > 0 && times[x - 1 + y * M] == std::numeric_limits<double>::max())
      {
         double at = access_time(cur_h, M, x, y, x - 1, y, c, f);
         if (at >= 0)
         {
            double move_h = std::max(H - 10 * (cell.first + at), 0.);
            double trans_time = 10;
            if (f[cell.second] + 20 <= move_h)
               trans_time = 1;

            closest.push(std::make_pair(cell.first + at + trans_time, x - 1 + y * M));
         }
      }

      if (y > 0 && times[x + (y - 1) * M] == std::numeric_limits<double>::max())
      {
         double at = access_time(cur_h, M, x, y, x, y - 1, c, f);
         if (at >= 0)
         {
            double move_h = std::max(H - 10 * (cell.first + at), 0.);
            double trans_time = 10;
            if (f[cell.second] + 20 <= move_h)
               trans_time = 1;

            closest.push(std::make_pair(cell.first + at + trans_time, x + (y - 1) * M));
         }
      }

      if (y < N - 1 && times[x + (y + 1) * M] == std::numeric_limits<double>::max())
      {
         double at = access_time(cur_h, M, x, y, x, y + 1, c, f);
         if (at >= 0)
         {
            double move_h = std::max(H - 10 * (cell.first + at), 0.);
            double trans_time = 10;
            if (f[cell.second] + 20 <= move_h)
               trans_time = 1;

            closest.push(std::make_pair(cell.first + at + trans_time, x + (y + 1) * M));
         }
      }
   }

   return times.back();
}

double process(int H, size_t M, std::vector<int> const & c, std::vector<int> const & f)
{
   std::vector<bool> reachable = calc_reachable(H, M, c, f);

   if (reachable.back())
      return 0;

   double t = std::numeric_limits<double>::max();
   for (size_t l = 0; l != reachable.size(); ++l)
   {
      if (!reachable[l])
         continue;

      t = std::min(t, path(l % M, l / M, H, M, c, f));
   }

   return t;
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
      int H;
      in >> H >> N >> M;
      std::vector<int> f(N * M, 0);
      std::vector<int> c(N * M, 0);

      for (size_t i = 0; i != N; ++i)
         for (size_t j = 0; j != M; ++j)
            in >> c[i * M + j];

      for (size_t i = 0; i != N; ++i)
         for (size_t j = 0; j != M; ++j)
            in >> f[i * M + j];


      double time = process(H, M, c, f);

      out.precision(10);

      out << "Case #" << X + 1 << ": " << std::fixed << time << std::endl;
   }
   return 0;
}

