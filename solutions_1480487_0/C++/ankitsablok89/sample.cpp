// _/\_ //

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cctype>
#include<cerrno>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<streambuf>
#include<valarray>
#include<typeinfo>
#include<new>

#include<set>
#include<list>
#include<vector>
#include<bitset>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<list>
#include<algorithm>
#include<functional>
#include<utility>
#include<iterator>


#define SZ( c )                          ( ( int )  ( ( c ).size()  ) )
#define LN( str )                        ( ( int )  (  ( str ).length() ) )
#define ALL(c)                           ( c ).begin( ) , ( c ).end() 
#define TR(c,i)                          for( typeof( ( c ).begin( ) )  i  = ( c ).begin() ;  i != ( c ).end() ; i++) 
#define PRESENT(c,x)                     ( ( c ).find( x ) != ( c ).end() ) 
#define CPRESENT(c,x)                    ( find( all( c ) , x ) != ( c ).end( ) ) 
#define PB                               push_back
#define MP                               make_pair
#define MOD                              1000000007ULL

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector < int > VI;
typedef vector < VI > VVI;
typedef vector < string > VS;
typedef vector < VS > VVS;
typedef pair< int , int > pii;

const long double PI = 3.141592653589793L;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w" , stdout);
    
    int T;
    cin >> T;
    
    int t_cases = 0;
    
    while( T-- )
    {
           ++t_cases;
           
           int N;
           cin >> N;
           
           vector < double > Si( N );
           
           for(int i = 0 ; i < N ; ++i)
                   cin >> Si[ i ];
           
           printf("Case #%d: ", t_cases);
           
           double X = 0;
           
           for(int i = 0 ; i < SZ( Si ) ; ++i)
                   X = X + Si[ i ];
           
           vector < double > Ci( N );
           
           for(int i = 0 ; i < SZ( Si ) ; ++i)
                   Ci[ i ] = Si[ i ];
           
           for(int i = 0 ; i < N ; ++i)
           {
                   double l = 0 , r = 1;
                   
                   for(int j = 0 ; j < 200 ; ++j)
                   {
                           double audience = (l + r) / 2;
                           
                           double val = Ci[ i ] + X * audience;

                           vector <double> D;
                           
                           for (int k = 0; k < N; ++k) 
                               if (k != i)
                                  D.push_back(Ci[k]);
                           
                           sort(D.begin(), D.end());

                           double success = true;
                           
                           double weHavePoints = X - X * audience;
                           
                           for (int j = 0; j < N - 1; ++j) 
                           {
                               double toAdd = val - D[j];
                                 if (toAdd > weHavePoints) 
                                 {
                                   success = false;
                                   break;
                               }

                               weHavePoints -= toAdd;
                           }

                           if (success) 
                              l = audience;
                           else 
                                r = audience;
                   }

                   l *= 100;
                   printf("%.8lf ", l);
           }

           cout << endl;
    }
    
    getchar();
    getchar();
    
    return 0;
}
