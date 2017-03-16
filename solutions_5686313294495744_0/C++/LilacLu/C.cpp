#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define SMALL
//#define LARGE

int T, n;
string A[20], B[20];
vector <string> fA, fB, tA, tB;

int main()
{
#ifdef SMALL
  freopen("C-small.in", "r", stdin);
  freopen("C-small.out", "w", stdout);
#endif

#ifdef LARGE
  freopen("C-large.in", "r", stdin);
  freopen("C-large.out", "w", stdout);
#endif

  cin >> T;
  for (int Case = 1; Case <= T; ++Case) {
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> A[i] >> B[i];
    int ans = 0;
    for (int s = 0; s < (1 << n); ++s) {
      fA.clear(), fB.clear(), tA.clear(), tB.clear();
      int temp = 0;
      for (int i = 0; i < n; ++i) {
        if ((1 << i) & s)
          fA.push_back(A[i]), fB.push_back(B[i]), ++temp;
        else
          tA.push_back(A[i]), tB.push_back(B[i]);
      }
      bool isAns = true;
      for (int i = 0; i < fA.size(); ++i) {
        string tempA = fA[i], tempB = fB[i];
        bool ansA = false, ansB = false;
        for (int j = 0; j < tA.size(); ++j) {
          if (fA[i] == tA[j])
            ansA = true;
          if (fB[i] == tB[j])
            ansB = true;
        }
        if (ansA && ansB)
          continue;
        isAns = false;
        break;
      }
      if (isAns && temp > ans)
        ans = temp;
    }
    cout << "Case #" << Case << ": " << ans << endl;
  }
  return 0;
}
