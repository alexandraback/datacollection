#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

#include <vector>

using namespace std;
typedef long double T;

T n[1000], k[1000];
   
int i, j, N;

/// y is the number of points Naomi will score if she plays Deceitful War optimally
inline int yy(void)
{ 
   int y = 0;
   int ii = 0;
   j = N-1;
   for ( i = 0; i < N; i++)
   {
      
      if( n[i] > k[ii] )
      {
        cerr << "yy: i: "<< i << ", ii: " << ii << "" << endl;
        cerr  << "yy: n[i]: " << n[i] << " >!> k[ii] " << k[ii] << "" << endl;	   
	y++;
	ii++;
      } else
	{
           cerr << "yy: i: "<< i << ", j: " << j << "" << endl;
	   cerr  << "yy: n[i]: " << n[i] << " < k[j] " << k[j] << "" << endl;	   
	   j--;
	}
      
   };
   
   return y; 
}

/// z is the number of points Naomi will score if she plays War optimally.
inline int zz(void)
{ 
   int z = N;
   for ( i = 0; i < N; i++, z-- )
   {
      for (j = 0; (j < N) && (n[i] > k[j]); j++ ) 
	;

      cerr << "zz: i: "<< i << ", j: " << j << "" << endl;
      
      if (j == N) // all n[i] > k[j]
	break; // return z;
	   
      cerr << "zz: n[i]: " << n[i] << " <<< k[j]:" << k[j] << "" << endl;
      k[j] = 0.0;  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   };
   
   return z;
}


int main(void)
{
   int T;
   string str; 
   cin >> T; getline(cin, str);

   for (int t = 1; t <= T; t++ )
   {
      cout << "Case #" << t << ": ";
      
      cin >> N; getline(cin, str);
      
      cerr << "N: " << N << endl;

      ios_base::fmtflags ff = cin.flags();
        
      cin.setf( ios::fixed, ios::floatfield );
      cin.precision(7);
      cin.width(7);
      cin.setf( ios::fixed, ios::floatfield );
      cin.flags(ff);
      
      for( i = 0; i < N; i++ )
	cin >> n[i];
      getline(cin, str);

//      cerr << endl << "nn: ";      for( i = 0; i < N; i++ )	cerr << " " << n[i];      cerr << endl;
      
      sort (n,n+N);
      cerr << "nn': ";
      for( i = 0; i < N; i++ )
	cerr << " " << n[i];
      cerr << endl;


      for( i = 0; i < N; i++ )
	cin >> k[i];
      getline(cin, str);

//      cerr << endl << "kk: ";      for( i = 0; i < N; i++ )	cerr << " " << k[i];      cerr << endl;
      
      sort (k,k+N);
      cerr << "kk': ";
      for( i = 0; i < N; i++ )
	cerr << " " << k[i];
      cerr << endl;
      
      int y = yy();
      int z = zz();
      cout << y << " " << z << endl;
   }
   
   return 0;
}



