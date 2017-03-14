//
// Qualification round 2012  problem B
//
// Usually built with g++ 4.4.5 on Linux
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <gmpxx.h>

#include <cstdlib>
#include <math.h>

using namespace std;

struct Point
{
     unsigned int x;
     unsigned int y;
     Point( unsigned int a, unsigned int b ) : x(a),y(b) {}
};

unsigned int solve1( unsigned int w,
		     unsigned int h,
		     unsigned int x,
		     unsigned int y,
		     unsigned int d )
{
     unsigned int i,j,k;

     unsigned int nx=(d/w)+2;
     unsigned int ny=(d/h)+2;

     vector<Point> v;
     for (i=1; i<=nx; i++)
     {
	  for (j=1; j<=ny; j++)
	  {
	       unsigned int dx;
	       unsigned int dy;

	       dx = w*i;
	       dy = h*j;
	       if (i%2) dx += w-2*x-1 ;
	       if (j%2) dy += h-2*y-1 ;

	       if (dx*dx+dy*dy <= d*d)
	       {
		    // reflection
		    for (k=0; k<v.size(); k++)
		    {
			 if (v.at(k).x * dy == v.at(k).y * dx)
			 {
			      break;
			 }
		    }
		    if (k==v.size())
		    {
			 v.push_back(Point(dx,dy));
		    }
	       }

	  }
     }

     if (0)
     {
	  for (k=0; k<v.size(); k++)
	  {
	       cerr << "Reflect " << setw(3) << v.at(k).x << " ";
	       cerr << setw(3) << v.at(k).y << endl;
	  }
     }
     //cerr << "Return " << v.size() << endl;
     return v.size();
}

unsigned int solve( unsigned int w,
		    unsigned int h,
		    unsigned int x, // count from 0
		    unsigned int y, // count from 0
		    unsigned int d )
{
     unsigned int n=0;

     if (0)
     {
	  cerr<< "solve(w=" << w << ", h=" << h << ", ";
	  cerr << "x=" << x << ", ";
	  cerr << "y=" << y << ", ";
	  cerr << "d=" << d << " )" << endl;
     }

     /* count the horizontal and verticals */
     if (2*x+1 <= d) n++;
     if (2*y+1 <= d) n++;
     if (2*(w-x)-1 <= d) n++;
     if (2*(h-y)-1 <= d) n++;

     n += solve1( w, h, x,     y,     d );
     n += solve1( w, h, x,     h-y-1, d );
     n += solve1( w, h, w-x-1, y,     d );
     n += solve1( w, h, w-x-1, h-y-1, d );

     return n;
}

int main( int argc, char ** argv )
{
     unsigned int t;
     unsigned int i,j,k;
     

     cin >> t;


     for (i=1; i<=t; i++) {

	  unsigned int h;
	  unsigned int w;
	  unsigned int d;
	  unsigned int x;
	  unsigned int y;
	  string s;

	  cin >> h;
	  cin >> w;
	  cin >> d;

	  //cerr << "h=" << h << "  w= " << w << endl;
	  //cerr << "d=" << d << endl;

	  for (j=0; j<h; j++)
	  {
	       cin >> s;
	       if (s.size() != w) {
		    cerr << "s = " << s << endl;
		    abort();
	       }
	       //cerr << s << endl;
	       for (k=0; k<s.size(); k++)
	       {
		    if (s.at(k) == 'X')
		    {
			 x = k-1;
			 y = j-1;
		    }
	       }
	  }

	  unsigned int a0=solve( w-2,h-2,      x, y, d ) ;
	  unsigned int a1=solve( w-2,h-2,w-2-x-1, y, d ) ;
	  unsigned int a2=solve( h-2,w-2,      y, x, d ) ;
	  //cerr << a0 << endl;
	  //cerr << a1 << endl;
	  //cerr << a2 << endl;

	  if (a0 != a1 || a1 != a2) abort();

	  cout << "Case #" << i << ": ";
	  cout << a0 << endl;
     }

     return 0;
}
