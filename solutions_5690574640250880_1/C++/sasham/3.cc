#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

#include <vector>

#include <math.h>

using namespace std;

ofstream f;

int r, c, m, d, Q, l, ll;

bool error = false;

int i, j, k; 
     
char a[50][50];

inline int counta(const int y0, const int x0, const char A)
{
  int n = 0;
   
  for ( int x = x0-1; x<= x0+1; x++ )
     if (x >= 0 && x < c )
       
  for ( int y = y0-1; y <= y0+1; y++ )
     if (y >= 0 && y < r )
	   
	   if( a[y][x] == A ) n++;
   
   return n;
   
}

inline void print(ostream& o)
{
   for ( i = 0; i < r; i++ )
   {
     for ( j = 0; j < c; j++ )
       o << a[i][j];
     o << endl;
   }
}


inline bool check()
{
   int mm = 0; 
   
   for ( i = 0; i < r; i++ )
   for ( j = 0; j < c; j++ )
   {
     if( a[i][j] == '*') mm ++;
     else a[i][j] = '0' + counta(i, j, '*');
   }

   for ( i = 0; i < r; i++ )
   for ( j = 0; j < c; j++ )
   if( a[i][j] != '*')
   {
     if( a[i][j] != '0') // a[i][j] = '.'; else      
	if( counta(i, j, '0') == 0)
	  if( i != 0 && j != 0 && d != 1 )
     {	  
       a[i][j] = '@';
       cerr << "ERROR: unreachable place: (r: " << i << ", c:" << j << ")"<< endl;
       error = true;
     }
   }
    
   if ( m != mm ) 
   {
     cerr << "ERROR: m != mm: "  << mm << endl;
     error = true;
   }
   
   if( !error )
   {
     for ( i = 0; i < r; i++ )
	for ( j = 0; j < c; j++ )
	     if( a[i][j] != '*') a[i][j] = '.';
      a[0][0] = 'c';
   }
   
   return !error;
   
}

inline bool compute () 
{
   error = false;
   
   d = (r * c - m); // > 0
   
   const int rcmin = (r < c) ? r : c;
   const int rcmax = (r > c) ? r : c;
   
   Q = lrintl( floor (sqrt(d)) );
   l = d - Q*Q; // >= 0
   ll = (Q+1)*(Q+1) - d; // > 0
   
   for ( i = 0; i < r; i++ )
   for ( j = 0; j < c; j++ )
     a[i][j] = '*';
       
   if( d == 1 )
     goto ok;
   
   if( r == 1 )
   {	
     for ( j = 0; j < d; j++ )
       a[0][j] = '.';
     goto ok;
   }

   if( c == 1 )
   {	
     for ( j = 0; j < d; j++ )
       a[j][0] = '.';
     goto ok;
   }

     
   
   if (  ((d/r) > 1) && (   
			 ((d % r) == 0 ) || ((d % r) > 1 )
			 )
      )
   {
//     cerr << "||r||: /:"<< d/r<< ", %:" << d%r<< endl;
 
     for ( j = 0; j < (d/r); j++ )
     for ( i = 0; i < r; i++ )
       a[i][j] = '.';
      
     
     for ( i = 0; i < (d%r); i++ )
       a[i][(d/r)] = '.';
      
//     a[0][0] = 'c';
      
     goto ok;
   }
   
   if (  ((d/c) > 1) && (   
			 ((d % c) == 0 ) || ((d % c) > 1 )
			 )
      )
   {  
//     cerr << "||c||: /:"<< d/c<< ", %:" << d%c<< endl;
     for ( j = 0; j < (d/c); j++ )
     for ( i = 0; i < c; i++ )
       a[j][i] = '.';
      
//     a[0][0] = 'c';
      
     for ( i = 0; i < (d%c); i++ )
       a[(d/c)][i] = '.';
      
     goto ok;
   }

   if( (d > 1) && ((d%2) == 1) && (r == 2 || c == 2) )
     goto nope;

   /// || d == 7
   if(  ( d == 2 || d == 3 || d == 5 ) ) // (r > 1 && c > 1) &&
     goto nope;
   
   if( d >= 4 ) //
   {     
	
   if( m <= (r*c - 2*r) )
   {
     for ( j = 0; j < c; j++ )
     for ( i = 0; i < r; i++ )
       a[i][j] = '.';

     i = r - 1;
     j = c - 1;
      
     int mm = m;
     
     while ( (mm > 0) && (i > 1 && j > 1) && (i < r && j < c ) )
     {
	a[i][j] = '*'; mm--; i--;
	
	if( mm == 0 ) break;	

	if (i == 1) 
	{
	   if ( mm > 1 )
	   {
    	      a[i][j] = '*'; mm--; 
	      i--;
    	      a[i][j] = '*'; mm--; 
	      i--;
	   }
	   
	   j--;
	   i = r - 1;
	   
	   if(j == 1)
	     {
		goto next ;
//	        cerr << "ERROR!!! hmm unexpected: run out of space...!!!" << endl;
	     }
	   
	}
	
     }
      
     goto ok;
      
   }
      
next:
      
   if( m <= (r*c - 2*c) )
   {
     for ( j = 0; j < c; j++ )
     for ( i = 0; i < r; i++ )
       a[i][j] = '.';

     i = r - 1;
     j = c - 1;
      
     int mm = m;
     
     while ( (mm > 0) && (i > 1 && j > 1) && (i < r && j < c ) )
     {
	a[i][j] = '*'; mm--; j--;
	
	if( mm == 0 ) break;	

	if (j == 1) 
	{
	   if ( mm > 1 )
	   {
    	      a[i][j] = '*'; mm--; 
	      j--;
    	      a[i][j] = '*'; mm--; 
	      j--;
	   }
	   
	   i--;
	   j = c - 1;
	   
	   if(i == 1)
	     {
		goto next2 ;
//	        cerr << "ERROR!!! hmm unexpected: run out of space...!!!" << endl;
	     }
	   
	}
	
     }
      
     goto ok;
      
   }
      
   }

next2:
   
   for ( i = 0; i < r; i++ )
   for ( j = 0; j < c; j++ )
     a[i][j] = '*';
   
   if( 
       ((Q+1) <= rcmin) 
      && 
       (ll <= ((Q+1)*(Q+1) - 4 - 2 * 2 * (Q-1))
       )
     )
   {
//     cerr << "__*||.... " << endl;
   
     for ( j = 0; j <= Q; j++ )
     for ( i = 0; i <= Q; i++ )
       a[i][j] = '.';
      
     i = j = Q;
     int mm = ll;
     
     int &x = i, &y = j;
     
     if ( rcmin == r )
     { 
        x = j; y = i; 
     }
       
     while ( (mm > 0) && (i > 1 && j > 1) && (i <=Q && j <=Q ) )
     {
	a[i][j] = '*'; mm--;
	
	if( mm == 0 ) break;	
	
	x--;
	
	if (x == 1) 
	{
	   y --;
	   x = Q;
	   
	   if(y == 1)
	     {
	        cerr << "ERROR!!! hmm unexpected!!!" << endl;
		goto next3;  
	     }
	   
	}
	
     }
      
     goto ok;
   }
   
next3:
   
   for ( i = 0; i < r; i++ )
   for ( j = 0; j < c; j++ )
     a[i][j] = '*';

   if( (Q <= rcmin) && ((Q + 1) != l) )
   {
     for ( j = 0; j < Q; j++ )
     for ( i = 0; i < Q; i++ )
       a[i][j] = '.';
      

     if (l <= r)
     if( r > Q && ( (l%r) != 1 && (l%r) != (r-1) ))
     {
        for ( i = 0; i < (l%r); i++ )
           a[i][Q] = '.';
	goto ok;
     }
      
     if (l <= c)
     if( c > Q && ( (l%c) != 1 && (l%c) != (c-1) ))
     {
        for ( i = 0; i < (l%c); i++ )
           a[Q][i] = '.';
	goto ok;
     }
      
//     cerr << "_|.... " << endl;
   }
   
   if( Q == 2 && ll == 2) goto nope;

   if( d == 10 )
     {

	for ( i = 0; i < r; i++ )
	  for ( j = 0; j < c; j++ )
	    a[i][j] = '*';
	
	if ( c >=4 && r >= 3)
	  {
	     a[0][0] = a[0][1] = a[0][2] = a[0][3] = '.';
	     a[1][0] = a[1][1] = a[1][2] = a[1][3] = '.';
	     a[2][0] = a[2][1] = '.';
	     goto ok;	     
	  }

	if ( r >=4 && c >= 3)
	  {
	     a[0][0] = a[0][1] = a[0][2] = '.';
	     a[1][0] = a[1][1] = a[1][2] = '.';
	     a[2][0] = a[2][1] = '.';
	     a[3][0] = a[3][1] = '.';
	     goto ok;	     
	  }
	
	     
     }
	
  
err:   
      
   cerr << "[]: Q=[SQROOT(d)]: " << Q << ", l = d - Q^2: " << l << ", ll = (Q+1)^2 - d: " << ll << endl;
   // ???
   
   cerr << "Hmmmm... ERROR?" << endl;
   error = true;

   
nope:
   return false;
   
ok:
   a[0][0] = 'c';
   return check();
}   


void test(const int R, const int C)
{
   bool ret; // f = cerr;
   int t = 1;

   for ( r = 1; r <= R; r++ )
     for ( c = r; c <= C; c++ )
       if( r > 15 || c > 15 )
       for ( m = 0; m < r*c; m++ )
      {
         cerr << "Case #" << t << ":" << endl; t++;

//	 if ( t == 118 || t == 124 || t == 205 || t == 218 || t == 219 )
         cerr << r << " " << c << " " << m << "" << endl;
	 
	 
//        char name[20] = "";	sprintf(name, "data/%1d_%1d_%02d", r, c, m);	f.open (name);
        ret = compute();
	 
        if (!ret || error) cerr << "Impossible" << endl; else print(cerr);
	 
	if ( error ) 
	  {	 
	      cerr << "ERROR: something went wrong... " << endl;
              cerr << "             r: " << r << ",          c: " << c << ",         m: " << m << ",       d: " << d << endl;
	      print(cerr);
              cerr << "***********************************************************************" << endl;
	  } else
	  {
//              cout << "             r: " << r << ",          c: " << c << ",         m: " << m << ",       d: " << d << endl;
//              cout << "[]: Q=[SQROOT(d)]: " << Q << ", l = d - Q^2: " << l << ", ll = (Q+1)^2 - d: " << ll << endl;
//              cout << "***********************************************************************" << endl;
	  }
	 
//	 f.close();  
      }
//   cout << "t: " << t;
}


int main(void)
{
//   test(20, 20); return 0;
   
   int T; string str; bool ret;
   
   cin >> T; getline(cin, str);
   for (int t = 1; t <= T; t++ )
   {
      cout << "Case #" << t << ":" << endl;
      
      cin >> r >> c >> m; getline(cin, str);
      
        ret = compute();
	 
        if (!ret || error) cout << "Impossible" << endl; else print(cout);
	 
	if ( error ) 
	  {	 
	      cerr << "ERROR: something went wrong... " << endl;
              cerr << "             r: " << r << ",          c: " << c << ",         m: " << m << ",       d: " << (r*c - m) << endl;
              cerr << "[]: Q=[SQROOT(d)]: " << Q << ", l = d - Q^2: " << l << ", ll = (Q+1)^2 - d: " << ll << endl;
	      print(cerr);
              cerr << "***********************************************************************" << endl;
	  } else
	  {
/*
              cout << "             r: " << r << ",          c: " << c << ",         m: " << m << ",       d: " << (r*c - m) << endl;
              cout << "[]: Q=[SQROOT(d)]: " << Q << ", l = d - Q^2: " << l << ", ll = (Q+1)^2 - d: " << ll << endl;
              cout << "***********************************************************************" << endl;
*/
	  }

   }
   
   return 0;
}



