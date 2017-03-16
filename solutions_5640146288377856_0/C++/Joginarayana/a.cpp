#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define forn(i,n)  for(int i = 0; i < (n); i++)

void solve()
{
  int R;
  int C;
  int W;
  int out;
  cin>>R>>C>>W;
  out = (R*(C/W)) + W - 1 + ((C % W) != 0);
  cout<<out<<endl;
}

int main()
{
  int T;
  cin>>T;
  forn(i,T)
  {
    cout<<"Case #"<<(i+1)<<": ";
    solve();
  }
  return 0;
}
