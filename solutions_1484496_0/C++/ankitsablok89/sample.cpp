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
    freopen("input.txt" , "rb" , stdin);
    freopen("output.txt" , "wb" , stdout);
    
    int T;
    cin >> T;
    
    int t_cases = 0;
    
    while( T-- )
    {
           ++t_cases;
           
           int N;
           cin >> N;
           
           vector< LL > S( N );
           
           for(int i = 0 ; i < SZ( S ) ; ++i)
                   cin >> S[ i ];
                      
           if( N == 1 )
               cout <<"Case #"<< t_cases <<": Impossible" << endl;
           
           else
           { 
           
             bool isPossible = false;
           
             vector < LL > s1;
             vector < LL > s2;
             
             int start = 1;
             
             while( start != N )
             {
                    for(int i = 0 ; i < start ; ++i)
                            s1.PB( S[ i ] );
                    
                    for(int i = start ; i < N ; ++i)
                            s2.PB( S[ i ] );
                    
                    LL sum1 = 0 , sum2 = 0;
                    
                    for(int i = 0 ; i < SZ( s1 ) ; ++i)
                            sum1 = sum1 + s1[ i ];
                    
                    for(int i = 0 ; i < SZ( s2 ) ; ++i)
                            sum2 = sum2 + s2[ i ];
                    
                    if( sum1 == sum2 )
                    {
                        isPossible = true;
                        break;
                    }
                    
                    ++start;
                    s1.clear();
                    s2.clear();
             }
             
             if( !isPossible )
                 cout <<"Case #"<< t_cases <<": Impossible" << endl;
             
             else
             {
                 cout <<"Case #"<< t_cases <<": " << endl;
                 
                 for(int i = 0 ; i < SZ( s1 ) ; ++i)
                         cout << s1[ i ] << " ";
                 
                 cout << endl;
                 
                 for(int i = 0 ; i < SZ( s2 ) ; ++i)
                         cout << s2[ i ] << " ";
                 
                 cout << endl;
             }
             
           }
           
    }
    
    getchar();
    getchar();
    
    return 0;
}

