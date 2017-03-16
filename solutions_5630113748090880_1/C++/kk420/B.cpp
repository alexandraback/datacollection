#include <algorithm>
#include <limits>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int MaxInt=numeric_limits<int>::max();
typedef vector<int> VI;
typedef vector<string> VS;
#define For(i,a,n) for (int i=a; i<n; ++i)
#define Fori(n) For(i,0,n)


int main()
{
  int NNN;
  cin>>NNN;
  for (int ca=1; ca<=NNN; ++ca)
  {
    int n, ile[3000]={};
    cin>>n;
    for (int i=0; i<2*n-1; ++i)
    {
      for (int j=0; j<n; ++j)
      {
        int a;
        cin>>a;
        ++ile[a];
      }
    }
    cout<<"Case #"<<ca<<": ";
    Fori(3000)
      if (ile[i]&1)
        cout<<i<<' ';
    cout<<endl;
  }

  return 0;
}
