#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

std::string myreverse( std::string x )
{
   std::reverse( x.begin(), x.end() );
   while( x[0] == '0' )
   {
      x = x.substr(1);
   }
   return x;
}

std::string myincrement( const std::string& x )
{
   stringstream ss;
   ss << x;
   int y;
   ss >> y;

   stringstream ss2;
   ss2 << y + 1;

   return ss2.str();
}

std::string mydecrement( const std::string& x )
{
   stringstream ss;
   ss << x;
   int y;
   ss >> y;

   stringstream ss2;
   ss2 << y - 1;

   return ss2.str();
}

int main()
{
   int n;
   cin >> n;
   for(int a = 0; a < n; a++)
   {
      std::string x;
      cin >> x;

      
      std::string c = "1";

      std::queue< std::pair< std::string, std::pair< int, bool > > > q;
      q.push( std::make_pair( c, std::make_pair( 1, false) ) );

      std::queue< std::pair< std::string, std::pair< int, bool > > > q2;
      q2.push( std::make_pair( x, std::make_pair( 1, false) ) );
      

     
      while( q.front().first != x && q2.front().first != c)
      {
       //  std::cout << q.front().first << " " << q.front().second << std::endl;
         //if( !last_reverse)
         if( !q.front().second.second )
            q.push( std::make_pair( myreverse( q.front().first ), std::make_pair( q.front().second.first + 1, true ) ) );
         q.push( std::make_pair( myincrement( q.front().first ), std::make_pair( q.front().second.first + 1, false ) ) );
          if( !q2.front().second.second )
            q.push( std::make_pair( myreverse( q2.front().first ), std::make_pair( q2.front().second.first + 1, true ) ) );
         q.push( std::make_pair( myincrement( q2.front().first ), std::make_pair( q2.front().second.first + 1, false ) ) );
        

          if( !q2.front().second.second )
            q2.push( std::make_pair( myreverse( q2.front().first ), std::make_pair( q2.front().second.first + 1, true ) ) );
         q2.push( std::make_pair( mydecrement( q2.front().first ), std::make_pair( q2.front().second.first + 1, false ) ) );
            if( !q.front().second.second )
            q2.push( std::make_pair( myreverse( q.front().first ), std::make_pair( q.front().second.first + 1, true ) ) );
         q2.push( std::make_pair( mydecrement( q.front().first ), std::make_pair( q.front().second.first + 1, false ) ) );


          q.pop();
         q2.pop();
      }






      int result = q.front().second.first;

      std::cout << "Case #" << a+1 << ": " << result << std::endl;
   }


}