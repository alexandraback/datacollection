#include <iostream>

using namespace std;

int ch[2020];
int bf[2020];
bool bb[2020];

int f(int k, int step, int first)
{
  if (bb[k]) return -1;

  bb[k] = true;

  if (bf[k] == first)
    return step;
  if (ch[k] > -1) {
    if (step > ch[k]) ch[k] = step;
    return -1;
  }

  return f(bf[k], step + 1, first);
}

int main() {
  int T;
  cin >> T;

  for (int ti = 1; ti <= T; ti++) {
    memset(bf, 0, sizeof(bf));
    memset(ch, -1, sizeof(ch));

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> bf[i];
      bf[i]--;
    }

    int cst = 0;

    for (int i = 0; i < n; i++)
      if (bf[bf[i]] == i) ch[i] = 0;

    for (int i = 0; i < n; i++)
    {
      memset(bb, false, sizeof(bb));
      int c = f(i, 1, i);
      if (c > cst) cst = c;
    }

    int lst = 0;
    for (int i = 0; i < n; i++)
      if (ch[i] > -1)
        lst += ch[i];
    int ans = max(lst, cst);
    cout << "Case #" << ti << ": " << ans << endl;
  }
  return 0;
}
