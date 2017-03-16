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

int sh(int x, int d10)
{
  return (x/10)+(x%10)*d10;
}

main()
{
  int cases;
  cin >> cases;
  for(int loop=1; loop<=cases; loop++)
  {
    printf("Case #%d: ",loop);
    int a, b; cin >> a >> b;
    int d=0, d10=1; while(d10<=a) { d++; d10*=10; } d10/=10;
    if (d<=1) { puts("0"); continue; }
    int t=0;
    for(int m=a;m<b;m++)
    {
      for(int k=sh(m,d10);k!=m;k=sh(k,d10)) { if (k>m && k<=b) t++; }
    }
    cout << t << endl;
    // puts("");
  }
}
