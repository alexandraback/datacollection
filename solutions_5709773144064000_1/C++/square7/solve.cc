#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int tot;
  cin >> tot;
  for(int i = 0; i < tot; ++i)
    {
      double C,F,X;
      cin >> C >> F >> X;
      cout << "Case #" << i+1 << ": ";
      int K=X/C-2/F;
      double t=0.0;
      double power=2.0;
      for(int cnt=0; cnt < K; ++cnt)
	{
	  t+=C/power;
	  power+=F;
	}
      t+=X/power;
      cout << setprecision(7) << fixed << t << endl;
    }
}
