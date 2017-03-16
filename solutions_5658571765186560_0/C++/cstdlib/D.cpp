#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define Rich 1
#define Gabr 0

int main()
{
  int T;
  cin>>T;
  for(int cas = 1; cas <= T; cas++)
  {
    int ans = 0;
    int X, R, C;
    cin>>X>>R>>C;
    if(X==1) ans = Gabr;
    else if(X==2)
    {
      if(R*C % X == 0) ans = Gabr;
      else ans = Rich;
    }
    else if(X==3)
    {
      if((R*C)%3 != 0 || min(R, C) == 1) ans = Rich;
      else
        ans = Gabr;
    }
    else if(X==4)
    {
      /*
      */
      if((R*C % X != 0) || (min(R, C) == 1 || (min(R,C) == 2 && max(R,C) <= 4))) ans = Rich;
      else
      {
        ans = Gabr;
      }
    }
    else if(X==5)
    {
      /*
          **
         **
         *
      */
      if(R*C % X != 0 || min(R,C) == 1 || min(R,C) == 2) ans = Rich;
      else
      {
        ans = Gabr;
      }
    }
    else if(X==6)
    {
    }
    else if(X>=7)
    {
      ans = Rich;
    }
    

    cout<<"Case #"<<cas<<": "<<(ans?"RICHARD":"GABRIEL")<<endl;
  }
  return 0;
}


