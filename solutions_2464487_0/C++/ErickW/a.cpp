#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unsigned short us;
typedef unsigned char uc;

int main()
{
  int cases;
  cin >> cases;
  for(int loop=1; loop<=cases; loop++)
  {
    ull r,t; cin >> r >> t;
    ull n=0;
    while(t >= (2*r+1))
    {
      n++;
      t-=2*r+1;
      r+=2;
    }
    printf("Case #%d: ",loop);
    cout << n << endl;
    // puts("");
  }
}
