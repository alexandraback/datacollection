#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int T = 0;
  cin>>T;
  for (int t = 1; t <= T; t++)
  {
    double answer = 0;
    double c, f, x;
    cin>>c>>f>>x;

    int q = 0;
    double r = x/2;
    do
    {
      answer = r;
      q++;
      r = 0;
      for (int i = 0; i < q; i++)
      {
        r += c/(f*i + 2);
      }
      r += x/(f*q +2);
    }
    while(r < answer);

    cout<<"Case #"<<t<<": "<<std::fixed<<std::setprecision(7)<<answer<<"\n";
  }
  return 0;
}
