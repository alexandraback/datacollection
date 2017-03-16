#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
  int T;
  cin >> T;
  for (int test = 1; test <= T; test++) {
    int N;
    cin >> N;
    vector<double> me(N), you(N);
    for (int i=0; i<N; i++) cin >> me[i];
    for (int i=0; i<N; i++) cin >> you[i];

    sort(me.begin(), me.end());
    sort(you.begin(), you.end());

    int deceitful = 0;
    for (int i=0, j_min=0, j_max=N-1; i<N; i++)
      if (me[i] > you[j_min]) j_min++, deceitful++; else j_max--;

    int honest = 0;
    for (int i=0, j_min=0, j_max=0; i<N; i++) {
      while (j_max < N && you[j_max] < me[i]) j_max++;
      if (j_max < N)
        you[j_max++] = -1;
      else {
        while (you[j_min] == -1) j_min++;
        j_min++, honest++;
      }
    }      

    cout << "Case #" << test << ": " << deceitful << " " << honest << endl;
  }
  return 0;
}
