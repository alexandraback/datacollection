#include <algorithm>
#include <iostream>
using namespace std;

main()
{
  int cases;
  cin >> cases;
  for(int loop=1; loop<=cases; loop++)
  {
    int n, s, p, t;
    printf("Case #%d: ",loop);
    cin >> n >> s >> p;
    int m=0;
    for(int i=0;i<n;i++)
    {
      cin >> t;
      int b = (t+2)/3, q = (t+4)/3;
      if (b >= p) m++;
      else if (q >= p && s>0 && t>=2 && t<=28) { s--; m++; }
    }
    printf("%d\n",m);
  }
}
