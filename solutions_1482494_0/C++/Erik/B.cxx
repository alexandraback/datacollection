#include <iostream>
#include <algorithm>

using namespace std;

int a[2000], b[2000];
bool ad[2000], bd[2000];
int main()
{
  int T;
  cin >> T;

  for (int t=1; t<=T; t++)
    {
      int N;
      cin >> N;
      for (int i=0; i<N; i++)
        {
          cin >> a[i] >> b[i];
          ad[i] = bd[i] = false;
        }

      int stars=0;
      int games=0;
      while (stars < 2*N)
        {
          int besta, bestb;
          besta=bestb=-1;
          for (int i=0; i<N; i++)
            {
              if (!bd[i] && stars>=b[i])
                {
                  bestb=i;
                  break;
                }
              if (!ad[i] && stars>=a[i] && (besta==-1 || b[besta]<b[i]))
                besta=i;
            }
          if (bestb != -1)
            {
              if (ad[bestb])
                stars++;
              else
                stars+=2;
              ad[bestb]=bd[bestb]=true;
              games++;
            }
          else if (besta != -1)
            {
              stars++;
              ad[besta] = true;
              games++;
            }
          else
            break;
        }

      if (stars >= 2*N)
        cout << "Case #" << t << ": " << games << endl;
      else
        cout << "Case #" << t << ": " << "Too Bad" << endl;

    }

  return 0;
}
