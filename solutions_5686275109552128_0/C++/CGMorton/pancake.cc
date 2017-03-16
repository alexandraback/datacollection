#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool mygreater (long i,long j) { return (i>j); }

long rec_solve( vector<long> &diners, long index, long max_prev_stack, long steps_taken )
{
   if (index == diners.size()) return steps_taken + max_prev_stack;

   float cur_stack = diners.at( index );
   long max_divisor = ceil( sqrt( cur_stack ) );

   long best = -1;
   for (float div = 1; div <= max_divisor; ++div) {
      long res_stack = ceil(cur_stack / div);
      long result;
      if (res_stack < max_prev_stack)
         result = rec_solve( diners, index + 1, max_prev_stack, steps_taken + (div - 1) );
      else
         result = rec_solve( diners, index + 1, res_stack, steps_taken + (div - 1) );

      if (best == -1 || result < best)
         best = result;
   }

   return best;
}

long solve( vector<long> &diners )
{
   if (diners.empty())
      return 0;

   sort( diners.begin(), diners.end(), mygreater );

   return rec_solve( diners, 0, 0, 0 ); 
}

int main()
{
   std::ifstream in ("b.in", std::ifstream::in);
   std::ofstream out ("b.out", std::ofstream::out);

   long count;

   in >> count;
   for (long i = 1; i <= count; ++i) {

      long num_diners;
      in >> num_diners;
      vector<long> diners;
      diners.resize( num_diners );
      for (int j = 0; j < num_diners; ++j) {
         long pancakes;
         in >> pancakes;
         diners[j] = pancakes;
      }

      long r = solve( diners );

      out << "Case #" << i << ": " << r << endl;
   }
   return 0;
}
