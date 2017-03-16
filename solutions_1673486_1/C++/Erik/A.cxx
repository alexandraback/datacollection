#include <iostream>
#include <algorithm>

using namespace std;

double p[1000000];

int main()
{
  int T;
  cin >> T;

  for (int t=1; t<=T; t++)
    {
      int A,B;
      cin >> A >> B;
      for (int i=0; i<A; i++)
        cin >> p[i];


      double minp=1+B+1; //press enter right away

      double prob=1.0;
      for (int i=0; i<=A; i++)
        {
          minp = min(minp,((A-i)+(B-i)+1)*prob+((A-i)+(B-i)+1+B+1)*(1.0-prob));
          if (i<A)
            prob *= p[i];
        }

      cout.precision(10);
      cout << "Case #" << t << ": " << minp << endl;
    }

  return 0;
}
