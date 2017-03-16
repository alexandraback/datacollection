#include <fstream>

using namespace std;

enum Quat {
   ONE,
   I,
   J,
   K,
   mONE,
   mI,
   mJ,
   mK
};


Quat mtable[4][4] = { ONE, I, J, K, I, mONE, K, mJ, J, mK, mONE, I, K, J, mI, mONE };

Quat multQuat( Quat a, Quat b )
{
   bool minus = false;
   if (a >= mONE) {
      minus = !minus;
      a = (Quat) ((int)a - 4);
   }
   if (b >= mONE) {
      minus = !minus;
      b = (Quat) ((int)b - 4);
   }

   Quat r = mtable[(int)a][(int)b];

   if (minus) {
      if (r >= mONE) r = (Quat) ((int)r - 4);
      else r = (Quat) ((int)r + 4);
   }

   return r;
}

Quat charToQuat( char c )
{
   if (c == 'i') return I;
   if (c == 'j') return J;
   if (c == 'k') return K;
   return ONE;
}

bool test( string &s, int chars, int mult )
{
   int char_count = chars * mult;

   if (char_count == 0)
      return false;

   Quat q = charToQuat( s.at(0) );

   int index = 1;
   while ( index < chars ) {
      Quat qn = charToQuat( s.at(index) );
      q = multQuat( q, qn );
      index++;
   }

   Quat qm = q;
   for( int i = 1; i < mult; ++i)
      q = multQuat( q, qm );

   return (q == mONE);
}

bool solve( string &s, int chars, int mult )
{
   int char_count = chars * mult;

   if (char_count == 0)
      return false;

   Quat qn;
   // I
   Quat qi = charToQuat( s.at(0) );

   int index = 1;
   while ( index <= char_count - 2 ) {
      if (qi == I) {
         // J
         Quat qj = charToQuat( s.at( index % chars ) );
         int index2 = index + 1;
         while ( index2 <= char_count - 1 ) {
            if (qj == J) {
               // K
               // Actually, since we tested, this MUST equal K
               return true;
               /*
               Quat qk = charToQuat( s.at( index2 % chars ) );
               int index3 = index2 + 1;
               while ( index3 < char_count ) {

                  qn = charToQuat( s.at( index3 % chars ) );
                  qk = multQuat( qk, qn );
                  index3++;
               }
               if (qk == K)
                  return true;
                  */
            }

            qn = charToQuat( s.at( index2 % chars ) );
            qj = multQuat( qj, qn );
            index2++;
         }
      }

      qn = charToQuat( s.at( index % chars ) );
      qi = multQuat( qi, qn );
      index++;
   }

   return false;
}

int main()
{
   std::ifstream in ("c.in", std::ifstream::in);
   std::ofstream out ("c.out", std::ofstream::out);

   int count, chars, mult;

   in >> count;
   for (int i = 1; i <= count; ++i) {
      in >> chars;
      in >> mult;
      string s;
      in >> s;

      bool r = test( s, chars, mult );
      if (r == true)
         r = solve( s, chars, mult );

      if (r == true)
         out << "Case #" << i << ": YES" << endl;
      else
         out << "Case #" << i << ": NO" << endl;
   }
   return 0;
}
