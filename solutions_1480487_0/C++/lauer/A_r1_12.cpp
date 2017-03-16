#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

double c[201];
double d[201];
pair<double,double> s[201];

int main()
{
  int t;
  double sum;
  int n;
  cin >> t;
  for(int z=0;z<t;++z)
  {
    cin >> n;
    sum = 0;
    for(int i=0;i<n;i++)
    {
      cin >> c[i];
      sum += c[i];
    }
    double stand = (sum*2.0)/n;
    double r = 0;
    double s = 0;
    for(int i=0;i<n;i++)
    {
      d[i] = (stand-c[i]);
      if(d[i] > 0)
      {
        ++r;
        s += c[i];
      }
    }
    stand = (sum+s)/r;
    s = 0;
    for(int i=0;i<n;i++)
    {
      if(d[i] > 0)
      {
        d[i] = stand - c[i];
        s += d[i];
      }
    }
    cout << "Case #" << z+1 << ": ";
    for(int i=0;i<n;i++)
    {
        if(d[i] <= 0)
          cout << fixed << setprecision(6) << 0.0 << " ";
        else
          cout << fixed << setprecision(6) << (100*d[i])/s << " ";
    }
    cout << endl;
  }
}
