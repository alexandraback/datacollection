#include <iostream>
#include <iomanip>

using namespace std;

double solve(double c, double f, double x)
{
  double ans = x/2;
  double rate=2;
  double tim=0;
  int an=0;
  for (int n=1; n<=1000000; n++) {
    tim += c/rate;
    rate += f;
    double t = tim + x/rate;
    if(t < ans){ans = t; an = n;};
  }
  cerr << " !!! " << an << endl;
  return ans;
}

int main()
{
  int t;
  cin >> t;
  for(int i=1; i<=t; i++) {
    double c,f,x;
    cin >> c >> f >> x;
    cout << "Case #" << i << ": " << fixed << setprecision(8) << solve(c,f,x) << "\n";
  }
}
