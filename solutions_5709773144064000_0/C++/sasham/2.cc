#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

#include <vector>

using namespace std;
typedef long double T;

T c, f, x;
   
inline T ccc(void)
{ 
   T v = 0.0;
   T r = 2.0;
   
   T m = x/r;
   
//   cout << "0: " << m << "  " << endl;
   for ( int n = 1; n++; n < 10)
   {
      v += (c/r); r += f; 
      
      if ( m > (v + x/r) ) 
	m = (v + x/r);
      else break;	
      
//      cout << "" << n<< ": " << m << "  " << endl;
   };
   
   return m;
}


int main(void)
{
   int T;
   string str; 
   cin >> T; getline(cin, str);

   cin.precision(7);
   cin.width(7);
   
   

   for (int t = 1; t <= T; t++ )
   {
      cout << "Case #" << t << ": ";
      
      cin >> c >> f >> x; getline(cin, str);
      
      ios_base::fmtflags ff = cout.flags();
        
      cout.setf( ios::fixed, ios::floatfield );
      cout.precision(7);
      cout.width(7);
      cout.setf( ios::fixed, ios::floatfield );
   
      cout << ccc() << endl;
      cout.flags(ff);
   }
   
   return 0;
}



