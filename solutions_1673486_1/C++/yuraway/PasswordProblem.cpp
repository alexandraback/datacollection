#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>

double run ( int a, int b, const std::vector<double> &p )
{
   std::cerr << a << " " << b << std::endl;
   for ( size_t i=0; i<p.size(); i++ )
      std::cerr << p[i] << " ";
   std::cerr << std::endl;

   double y = 2*b+2;
   double pp = 1;

   for ( int i=0; i<=a; i++ )
   {
      double x = a+b+1-2*i;
      double yy = x;
      yy += (1-pp) * (b+1);
      std::cerr << yy << " ";
      y = std::min ( y, yy );
      if ( i<a )
         pp *= p[i];
   }
   std::cerr << std::endl;

   return std::min ( y, (b+2)*1.0 );
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

      std::vector<double> p(a);

      for ( int j=0; j<a; j++ )
         is >> p[j];

      std::cout << "Case #" << i+1 << ": " << std::fixed << std::setprecision (6) << run ( a, b, p ) << std::endl;
   }
}

