#include <vector>
#include <iostream>
#include <set>
#include <limits>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef long double DD;

DD solve(DD C,DD F,DD X)
{
  DD ans = numeric_limits<DD>::max();
  DD p = 2, t = 0, a = X/p;
  for(int i=1;a<ans;i++) {
    ans = min(ans,a);
    t = t + C/p;
    p = 2+i*F;
    a = t + X/p;
  }
  return ans;
}

int main()
{
  int K;
  cin >> K;
  for(int i=1;i<=K;i++) {
    DD c,f,x;
    cin >> c >> f >> x;
    DD rr = solve(c,f,x);
    cout << "Case #" << i <<": ";
    printf("%0.7Lf\n",rr);
  }
  return 0;
}
