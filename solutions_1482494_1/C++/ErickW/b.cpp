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
    int a[1000], b[1000];
    char l[1000]; int s=0, g=0;
    int n; cin >> n;

    for(int i=0;i<n;i++) cin >> a[i] >> b[i];
    memset(l,0,sizeof(l));

    while(s < 2*n)
    {
      bool going=true;
      while(going)
      {
        going = false;
        for(int i=0;i<n;i++)
        {
          if(s>=b[i] && l[i]<2) {
s += 2-l[i]; l[i]=2; g++; going = true; }
        }
      }

      int b0=0,j=-1; for(int i=0;i<n;i++)
      {
        if (l[i]==0 && s >= a[i] && b[i] > b0) { b0=b[i]; j=i; }
      }

      if (j<0) break; else {
s++; l[j]=1; g++; }
    }

    printf("Case #%d: ",loop);
    if (s < 2*n) puts("Too Bad"); else cout << g << endl;
    // puts("");
  }
}
