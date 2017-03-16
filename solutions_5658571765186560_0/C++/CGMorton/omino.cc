#include <fstream>

using namespace std;


bool solve (long omino, long x, long y)
{
   if (omino >= 7) return false; // Put a hole in the omino

   if ( (x * y) % omino != 0) return false; // Doesn't add up

   if ( x < omino && y < omino ) return false; // long-ino wins

   if ( omino >= 3 && ( x == 1 || y == 1 ) ) return false; // 2-width omino
   if ( omino >= 5 && ( x <= 2 || y <= 2 ) ) return false; // 3-width omino

   // Now to specific cases

   if ( omino == 4 ) {
      if ( x == 2 || y == 2 ) return false; // 2 width is foiled by parity
      else return true;
   }

   if ( omino == 5 ) {
      // The stair piece can stop a 3x5 board
      if ( (x == 3 && y == 5) || ( y == 3 && x == 5) )
         return false;
      else return true;
   }

   if ( omino == 6 ) {
      // Here's where the magic happens
      // Biggest complex piece is 3x4 dimensions, so:
      // 12-space boards: both fail
      //if ( x * y == 12 ) return false;
      // 18-space boards: 3x6 is only contender: squiggle ends that
      //if ( x * y == 18 ) return false;
      // 24-space boards: 4x6, 3x8:
      // 4x6 is always winnable, just put the piece touching only one edge
      // this is true for all further 4xX boards, so...
      // At what X is a 3xX board always solvable?
      // Answer: NEVER, because of parity. One side of a 3x4 squiggle will
      // always have 3N + 1 empty spots! Okay
      if (x == 3 || y == 3) return false;
      else return true;
   }

   return true; // omino == 1,2,3
}

int main()
{
   std::ifstream in ("d.in", std::ifstream::in);
   std::ofstream out ("d.out", std::ofstream::out);

   long count;

   in >> count;
   for (long i = 1; i <= count; ++i) {
      long omino, x, y;
      in >> omino >> x >> y;

      bool r = solve( omino, x, y );


      if (r == true)
         out << "Case #" << i << ": GABRIEL" << endl;
      else
         out << "Case #" << i << ": RICHARD" << endl;
   }
   return 0;
}
