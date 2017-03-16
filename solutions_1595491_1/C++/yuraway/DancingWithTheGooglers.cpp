#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

std::vector<int> xpn (31,-1), xps (31,-1);

void prepare ()
{
   for ( int i=0; i<=10; i++ )
      for ( int j=i; j<=10; j++ )
         for ( int k=j; k<=10; k++ )
         {
            int d1 = i>j ? i-j : j-i;
            int d2 = i>k ? i-k : k-i;
            int d3 = j>k ? j-k : k-j;

            if ( d1 > 2 || d2 > 2 || d3 > 2 ) continue;

            if ( d1 == 2 || d2 == 2 || d2 == 2 )
               xps[i+j+k] = std::max ( xps[i+j+k], k );
            else
               xpn[i+j+k] = std::max ( xpn[i+j+k], k );
         }

   for ( int i=0; i<=30; i++ )
      std::cerr << i << ": " << xpn[i] << "," << xps[i] << std::endl;
}

int run ( int n, int s, int p, const std::vector<int> &points )
{
   std::cerr << n << "," << s << "," << p << " [ ";
   for ( int i=0; i<n; i++ )
      std::cerr << points[i] << " ";
   std::cerr << "]" << std::endl;

   int y = 0, x = 0;

   for ( int i=0; i<n; i++ )
   {
      if ( xpn [ points[i] ] >= p )
         ++x;
      else if ( xps [ points[i] ] >= p )
         ++y;
   }

   std::cerr << x << "," << y << std::endl;

   return x + std::min ( y, s );
}

int main ( int argc, char *argv[] )
{
   if ( argc < 2 )
   {
      std::cerr << "usage: " << argv[0] << " <in-file>" << std::endl;
      return 1;
   }

   prepare ();

   std::ifstream is ( argv[1] );

   size_t num = 0;
   is >> num;

   for ( size_t i=0; i<num; i++ )
   {
      int n, s, p;
      is >> n >> s >> p;

      std::vector<int> points;
      for ( int j=0; j<n; j++ )
      {
         int v;
         is >> v;
         points.push_back (v);
      }

      std::cout << "Case #" << i+1 << ": " << run ( n, s, p, points ) << std::endl;
   }
}

