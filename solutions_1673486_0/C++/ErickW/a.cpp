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

main()
{
  int cases;
  cin >> cases;
  for(int loop=1; loop<=cases; loop++)
  {
    int a,b;
    double p[100000];

    cin >> a >> b;
    for(int i=0;i<a;i++) cin >> p[i];

    double m = b+2;
    double P=1;

    for(int i=0;i<=a;i++)
    {
      int good = (b-i)+(a-i)+1;
      int pen = b+1;
      double t = good + (1-P)*pen;
      P *= p[i];
      if (t < m) m=t;
    }

    printf("Case #%d: ",loop);
    printf("%0.6lf\n",m);
    // puts("");
  }
}
