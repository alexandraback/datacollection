#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int t;
  cin >> t;
  int dat[105];
  for (int t1=1; t1<=t; t1++)
  { 
    int ans;
    int a,n; 
    cin >> a >> n;
    ans = n;
    for(int i=0; i<n; i++)cin >> dat[i];
    sort(dat, dat+n);
    if (a > 1)
    {
      int cs=a;
      int cm = 0;
      for(int i=0; i<n; i++)
      {
        ans = min(ans, cm + n-i);
        while(cs <= dat[i])
        {
          cs += cs-1;
          cm++;
        }
        cs += dat[i];
      }
      ans = min(ans, cm);
    }
    cout << "Case #" << t1 << ": " << ans << "\n";
  }
  return 0;
}
