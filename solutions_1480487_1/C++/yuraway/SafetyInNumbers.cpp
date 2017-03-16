#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>

std::vector<double> run ( const std::vector<int> &x )
{
   const size_t n = x.size ();
   std::vector<double> y (n);

   for ( size_t i=0; i<n; i++ )
      std::cerr << x[i] << " ";
   std::cerr << std::endl;

   int s = 0;
   for ( size_t i=0; i<n; i++ )
      s += x[i];

   std::map<int,int> a;
   for ( size_t i=0; i<n; i++ )
      ++a[x[i]];

   for ( std::map<int,int>::const_iterator p = a.begin (); p != a.end (); ++p )
      std::cerr << p->first << "," << p->second << " ";
   std::cerr << std::endl;

   double s2 = s;
   std::cerr << s << " " << s2 << std::endl;

   std::map<int,int>::const_iterator p = a.begin (), q = p;
   ++q;

   int c = 0;
   while ( q != a.end () )
   {
      c += p->second;
      double b = std::min ( s2, 1.0 * c * ( q->first - p->first ) );
      std::cerr << c << ":" << q->first - p->first << ":" << b << " ";
      for ( size_t i=0; i<n; i++ )
         if ( x[i] <= p->first )
            y[i] += b/c;
      s2 -= b;
      ++p;
      ++q;
   }

   if ( s2 > 0 )
   {
      double b = s2;
      std::cerr << c << ":" << b << " ";
      for ( size_t i=0; i<n; i++ )
         y[i] += b/n;
   }
   std::cerr << std::endl;

   double s3 = 0;
   for ( size_t i=0; i<n; i++ )
      s3 += y[i];

   s3 /= 100;

   for ( size_t i=0; i<n; i++ )
      y[i] /= s3;

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

      std::vector<int> x(n);

      for ( int j=0; j<n; j++ )
         is >> x[j];

      std::vector<double> y = run ( x );

      std::cout << "Case #" << i+1 << ":";

      for ( int j=0; j<n; j++ )
         std::cout << " " << std::fixed << std::setprecision (6) << y[j];

      std::cout << std::endl;
   }
}

