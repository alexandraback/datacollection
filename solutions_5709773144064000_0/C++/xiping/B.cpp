#include <iostream>
#include <iomanip>

using namespace std;

void solve_case();

int main()
{
   int N = 0;
   cin >> N;
   for (int i = 0; i < N; ++ i)
   {
      cout << "Case #" << i + 1 << ": ";
      solve_case();
      cout << '\n';
   }

   return 0;
}

void solve_case()
{
   double C = 0.0;
   double F = 0.0;
   double X = 0.0;

   cin >> C;
   cin >> F;
   cin >> X;

   double R = (X - C) * F / C;

   double r = 2.0;

   double t = 0;

   while (r < R)
   {
      t += C / r;
      r += F;
   }

   t += X/r;
   cout << fixed;
   cout << setprecision(7);
   cout << t;

}
