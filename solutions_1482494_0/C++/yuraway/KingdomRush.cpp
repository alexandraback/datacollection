#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>

int run ( const std::vector<int> &a, const std::vector<int> &b )
{
   const size_t n = a.size ();
   std::cerr << n << std::endl;
   for ( size_t i=0; i<n; i++ )
      std::cerr << a[i] << " ";
   std::cerr << std::endl;
   for ( size_t i=0; i<n; i++ )
      std::cerr << b[i] << " ";
   std::cerr << std::endl;

   std::vector<int> x (n);
   int y = 0;
   int c = 0;

   while ( c < 2*n )
   {
      size_t i=0;
      for ( ; i<n; i++ )
         if ( x[i] == 0 && b[i] <= c )
            break;

      if ( i==n )
      {
         for ( i=0; i<n; i++ )
            if ( x[i] == 1 && b[i] <= c )
               break;
      }

      if ( i<n )
      {
         ++y;
         std::cerr << i << "(2," << x[i] << ") ";
         c += 2-x[i];
         x[i] = 2;
         continue;
      }

      for ( i=0; i<n; i++ )
         if ( x[i] < 1 && a[i] <= c )
            break;

      if ( i==n )
         return -1;

      int ii=0;
      int bb=b[0];
      for ( i=1; i<n; i++ )
         if ( x[i] < 1 && b[i] > bb )
            bb = b[i], ii = i;

      ++y;
      ++c;
      x[ii] = 1;
      std::cerr << ii << "(1) ";
   }

   return y;
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
      int n;
      is >> n;

      std::vector<int> a(n), b(n);

      for ( int j=0; j<n; j++ )
         is >> a[j] >> b[j];

      int y = run ( a, b );

      std::cout << "Case #" << i+1 << ": ";

      if ( y >= 0 )
         std::cout << y;
      else
         std::cout << "Too Bad";

      std::cout << std::endl;
   }
}

