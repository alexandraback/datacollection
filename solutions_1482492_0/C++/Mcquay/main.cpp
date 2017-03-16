#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

#include <boost/multi_array.hpp>

struct state_t
{
   double x0;
   double v0;
   double a0;
   double t0;
};

double sqr(double a) { return a * a; }

double process(double a, std::vector<std::pair<double, double> > const & t)
{
   if (t.size() == 1)
      return sqrt(2 * t.back().second / a);

   double an = 2 * t.back().second / sqr(t.back().first);

   if (an > a)
      an = a;

   return sqrt(2 * t.back().second / an);
}

void normalize(double D, std::vector<std::pair<double, double> > & t)
{
   assert(t.front().first == 0);

   if (t.size() == 1)
   {
      t.back().second = D;
   }
   else
   {
      if (t.front().second >= D)
      {
         t.resize(1);
         t.front().second = D;
      }
      else
      {
         t.back().first *= (D - t.front().second) / (t.back().second - t.front().second);
         t.back().second = D;
      }
   }
}

int main(int argc, char * argv[])
{
   std::ifstream in(argv[1]);
   std::ofstream out(argv[2]);

   size_t T = 0;
   in >> T;

   for (size_t X = 0; X != T; ++X)
   {
      double D;
      size_t N, A;
      in >> D >> N >> A;

      std::vector<std::pair<double, double> > t(N);
      for (size_t l = 0; l != N; ++l)
         in >> t[l].first >> t[l].second;

      std::vector<double> a(A);
      for (size_t l = 0; l != A; ++l)
         in >> a[l];

      out << "Case #" << X + 1 << ":" << std::endl;
      normalize(D, t);
      for (size_t l = 0; l != A; ++l)
      {
         double time = process(a[l], t);
         out.precision(10);
         out << std::fixed << time << std::endl;
      }
   }
   return 0;
}

