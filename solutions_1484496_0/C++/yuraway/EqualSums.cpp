#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>

std::vector<int> run ( const std::vector<int> &x )
{
   const size_t n = x.size ();
   for ( size_t i=0; i<n; i++ )
      std::cerr << x[i] << " ";
   std::cerr << std::endl;

   typedef std::set<int> Subset;
   typedef std::map<int,Subset> Sums;

   Sums m;

   int cn = 1 << n;
   for ( int c=1; c<cn; ++c )
   {
      int s = 0, i = 0;
      for ( int a=c; a>0; a>>=1, ++i )
         if ( a%2 == 1 )
            s += x[i];

      Sums::iterator p = m.find (s);

      if ( p == m.end () )
      {
         Subset b;
         b.insert (c);
         m.insert ( std::make_pair ( s, b ) );
         continue;
      }

      //std::cerr << p->first << " ";

      for ( Subset::iterator q = p->second.begin (); q != p->second.end (); ++q )
      {
         if ( *q + c != (*q | c) )
            continue;

         std::cerr << *q << " " << c << std::endl;
         std::vector<int> y (n);

         int i=0;
         for ( int a=c; a>0; a>>=1, ++i )
            if ( a%2 == 1 )
               y[i] = 1;

         i=0;
         for ( int a=*q; a>0; a>>=1, ++i )
            if ( a%2 == 1 )
               y[i] = 2;

         for ( size_t i=0; i<n; i++ )
            std::cerr << y[i] << " ";
         std::cerr << std::endl;

         return y;
      }

      p->second.insert (c);
   }

   std::vector<int> y (n);
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

      std::vector<int> y = run ( x );

      std::cout << "Case #" << i+1 << ":" << std::endl;

      if ( std::find ( y.begin (), y.end (), 1 ) == y.end () )
         std::cout << "Impossible" << std::endl;
      else
      {
         int s1 = 0, s2 = 0;
         for ( int j=0; j<n; j++ )
            if ( y[j] == 1 )
            {
               s1 += x[j];
               std::cout << x[j] << " ";
            }
         std::cout << std::endl;
         for ( int j=0; j<n; j++ )
            if ( y[j] == 2 )
            {
               s2 += x[j];
               std::cout << x[j] << " ";
            }
         std::cout << std::endl;
         std::cerr << s1 << " " << s2 << std::endl;
      }

      //std::cout << std::endl;
   }
}

