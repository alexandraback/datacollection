#include <cassert>
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
    ull e, r, n; cin >> e >> r >> n;
    vector<ull> v(n); for(int i=0;i<n;i++) cin >> v[i];

vector<ull> y(e+1), ny(e+1);
for(int i=0;i<=e;i++) y[i] = i*v[n-1];

for(int l=n-2;l>=0;l--)
{
   for(int i=1;i<=e;i++)
   {
     ny[i] = 0;
     for(int j=0;j<=i;j++)
     { 
       ny[i] = max(ny[i], y[min(e,i-j+r)] + j*v[l]);
     }
   }
   y = ny;
}

    printf("Case #%d: ",loop);
    // puts("");
    cout << y[e] << endl;
  }
}
