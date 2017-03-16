#include <iostream>

using namespace std;

int main()
{
  int T, n, s, p, t, a[100] = {0};
  int surprise[31] = {-1, -1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10, -1, -1};
  int unsurprise[31] = {0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10};
  int i, j;
  cin >> T;
  for (i=0;i<T;i++) {
    cin >> n >> s >> p;
    for (j=0;j<n;j++) {
      cin >> t;
      if (unsurprise[t] >= p)
        a[i]++;
      else if (surprise[t] >= p && s > 0) {
        a[i]++;
        s--;
      }
    }
  }
  for (i=0;i<T;i++)
    cout << "Case #" << i+1 << ": " << a[i] << endl;
  cin >> n;
  return 0;
}
