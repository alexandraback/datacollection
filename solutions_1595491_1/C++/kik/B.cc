#include <iostream>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; cas++) {
    int N, S, p;
    cin >> N >> S >> p;

    int res = 0;
    for (int i = 0; i < N; i++) {
      int ti;
      cin >> ti;
      if (ti >= 3 * p) res++;
      else if (ti >= 3 * p - 2 && p - 1 >= 0) res++;
      else if (ti >= 3 * p - 4 && p - 2 >= 0 && S > 0) res++, S--;
    }
    cout << "Case #" << cas << ": " << res << endl;
  }
  return 0;
}
