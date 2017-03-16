#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>

int run ( int a, int b )
{
   std::cerr << "[" << a << "," << b << "]" << std::endl;

   int c=1;

   std::set<long long> v;

   for ( int x=a; x<=b; x++ )
   {
      while ( c < x )
      {
         c *= 10;
         std::cerr << c << std::endl;
      }

      for ( int d=10; d<c; d*=10 )
      {
         int y = (x%d)*(c/d) + x/d;

         if ( x < y && y <= b )
         {
            long long k = x;
            k <<= 32;
            k += y;

            if ( v.find (k) == v.end () )
               v.insert (k);
            else
               std::cerr << "*";

            //std::cerr << "(" << x << "," << y << ") ";
         }
      }
   }
   std::cerr << std::endl;

   return v.size ();
}

int main ( int argc, char *argv[] )
{
   if ( argc < 2 )
   {
      std::cerr << "usage: " << argv[0] << " <in-file>" << std::endl;
      return 1;
   }

   std::ifstream is ( argv[1] );

   size_t num = 0;
   is >> num;

   for ( size_t i=0; i<num; i++ )
   {
      int a, b;
      is >> a >> b;

      std::cout << "Case #" << i+1 << ": " << run ( a, b ) << std::endl;
   }
}

