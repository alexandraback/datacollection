#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#include <algorithm>

#define type long long

using namespace std;


int main()
{

  cin.tie(NULL);
  std::ios::sync_with_stdio(false);

  int T;
  cin>>T;
  int t=0;
  while(T--)
  {
    t++;
    type res = 0;
    type p,q;

    type tab[3];

    string buf;
    cin>>buf;
    std::istringstream buffer( buf );
    std::string token;
    int i = 0;
    while( std::getline( buffer, token, '/' ) )
    {
        // std::cout << token << std::endl;
        std::istringstream buf2( token );

        buf2>>tab[i++];
    }
    // cout<<tab[0]<<" "<<tab[1]<<"\n";

    type gc = __gcd(tab[0], tab[1]);
    p = tab[0]/gc;
    q = tab[1]/gc;
    // cout<<p<<" "<<q<<"\n";
    int c = 1;

    type qq = q;
    while(qq % 2 == 0)
      qq/=2;

    bool bb = 0;
    if(qq == 1)
      bb=1;

    while(bb)
    {
      if((2*p)<q)
      {
        if( q % 2)
        {
          c = -42;
          break;
        }

        q/=2;
        c++;
      }
      else
        break;
    }

    if(c > 0 && bb)
      cout<<"Case #"<<t<<": "<< c<<"\n";
    else
      cout<<"Case #"<<t<<": impossible\n";

  }


  return 0;
 
}