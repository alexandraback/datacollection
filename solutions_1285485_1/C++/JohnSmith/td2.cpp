//
// Qualification round 2012  problem D - hard
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

bool debug=false;

struct Room
{
     unsigned int h;
     unsigned int w;
     vector<vector<bool> > mirror;

     Room( unsigned int h1, unsigned int w1 ) : h(h1), w(w1)
	  {
	       unsigned int i;
	       mirror.resize(w);
	       for (i=0; i<w; i++)
	       {
		    mirror.at(i).resize(h);
	       }
	  }
     bool m( unsigned int x, unsigned int y )
	  {
	       return mirror.at(x).at(y);
	  }
};

int trace_ray( Room &r, 
	       int x0, int y0,
	       int dx, int dy )
{
     int xdir;
     int ydir;
     //int dx0 = dx;
     //int dy0 = dy;

     if (dx<0) {
	  xdir = -1;
	  dx  = -dx;
     } else {
	  xdir = 1;
     }

     if (dy<0) {
	  ydir = -1;
	  dy  = -dy;
     } else {
	  ydir = 1;
     }

     int xn=1;
     int yn=1;
     int x=x0;
     int y=y0;
     
     if (debug) cerr << "Trace ray( dx="<<dx<<", dy=" << dy << ")" << endl;
     while (xn<dx*2 || yn < dy*2)
     {
	  if (debug) cout << "x,y = " << x << "," << y << endl;

	  // compare xn/dx and yn/dy
	  if (xn*dy == dx*yn)
	  {
	       if (r.m(x+xdir,y) &&
		   r.m(x+xdir,y+ydir) &&
		   r.m(x,y+ydir))
	       {
		    xdir = -xdir;
		    ydir = -ydir;
	       }
	       else if (r.m(x+xdir, y) &&
			r.m(x+xdir, y+ydir))
	       {
		    xdir = -xdir;
		    y += ydir;
	       }
	       else if (r.m(x,      y+ydir) &&
			r.m(x+xdir, y+ydir))
	       {
		    ydir = -ydir;
		    x += xdir;
	       }
	       else if (r.m(x+xdir, y+ydir))
	       {
		    return 0;
	       }
	       else
	       {
		    x += xdir;
		    y += ydir;
	       }

	       xn+=2;
	       yn+=2;
	  }
	  else if (xn*dy <dx*yn)
	  {
	       if (r.m(x+xdir, y))
	       {
		    xdir = -xdir;
	       }
	       else
	       {
		    x += xdir;
	       }
	       xn+=2;
	  }
	  else
	  {
	       if (r.m(x, y+ydir))
	       {
		    ydir = -ydir;
	       }
	       else
	       {
		    y += ydir;
	       }
	       yn+=2;
	  }

	  // point if xn-1/yn-1 == xd/yd
	  if (dy*(xn-1) == dx*(yn-1))
	  {
	       if (xn-1 == 2*dx && yn-1 == 2*dy)
	       {
		    if (x==x0 && y==y0) 
		    {
			 //cerr << "Final Vertex - score" << endl;
			 //cerr << "Ray to " << dx0 << "," << dy0 << endl;
			 return 1;
		    }
		    else
		    {
			 //cerr << "Final Vertex - no score" << endl;
			 return 0;
		    }
	       }
	       if (x==x0 && y==y0) 
	       {
		    //cerr<< "Encounter self - break" << endl;
		    return 0;
	       }
	  }
	  
     }
     cerr << "Shouldnt get here" << endl;
     abort();
     return 0;
}


unsigned int solve( Room r,
		    int x, // count from 0
		    int y, // count from 0
		    int d )
{
     unsigned int n=0;
     int dd;
     int dx;
     int dy;

     if (0)
     {
	  cerr<< "solve(";
	  cerr << "x=" << x << ", ";
	  cerr << "y=" << y << ", ";
	  cerr << "d=" << d << " )" << endl;
     }

     for (dd=1; ; dd++)
     {
	  if (r.m(x+dd,y))
	  {
	       if (2*dd-1 <= d)
	       {
		    n++;
	       }
	       break;
	  }
     }
     for (dd=1; ; dd++)
     {
	  if (r.m(x-dd,y))
	  {
	       if (2*dd-1 <= d)
	       {
		    n++;
	       }
	       break;
	  }
     }
     for (dd=1; ; dd++)
     {
	  if (r.m(x,y+dd))
	  {
	       if (2*dd-1 <= d)
	       {
		    n++;
	       }
	       break;
	  }
     }
     for (dd=1; ; dd++)
     {
	  if (r.m(x,y-dd))
	  {
	       if (2*dd-1 <= d)
	       {
		    n++;
	       }
	       break;
	  }
     }

     if (debug)
     {
	  cerr << "After aligned rays: " << n <<endl;
     }

     for (dx=-d; dx<=d; dx++)
     {
	  if (dx!= 0)
	  {
	       for (dy=-d; dy<=d; dy++)
	       {
		    if (dy != 0)
		    {
			 if (dx*dx+dy*dy <= d*d)
			 {
			      n += trace_ray( r, x, y, 
					      dx, dy );
			 }
		    }
	       }
	  }
     }
     
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

	  Room r(w,h);

	  for (j=0; j<h; j++)
	  {
	       cin >> s;
	       if (s.size() != w) {
		    cerr << "s = " << s << endl;
		    cerr << "Expected length " << w << endl;
		    cerr << "Actual   length " << s.size() << endl;
		    abort();
	       }

	       for (k=0; k<s.size(); k++)
	       {
		    if (s.at(k) == 'X')
		    {
			 x = j;
			 y = k;
		    }
		    if (s.at(k) == '#')
		    {
			 r.mirror.at(j).at(k) = true;
		    }
	       }
	  }

	  if (debug)
	  {
	       for (k=0; k<w; k++)
	       {
		    for (j=h; j-->0; )
		    {
			 if (r.m(j,k))
			 {
			      cerr << '#';
			 }
			 else if (x==j && y==k)
			 {
			      cerr << 'X';
			 }
			 else
			 {
			      cerr << '.';
			 }
		    }
		    cerr << endl;
	       }
	  }

	  unsigned int a0=solve(r,x,y,d);

	  cout << "Case #" << i << ": ";
	  cout << a0 << endl;
     }

     return 0;
}
