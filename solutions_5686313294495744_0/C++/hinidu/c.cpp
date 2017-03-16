#include <iostream>

using namespace std;

int n, ans;
string a[16], b[16];
bool fake[16];

bool contains(string *a, string s)
{
  for (int i = 0; i < n; ++i)
    if (!fake[i] && a[i] == s)
      return true;
  return false;
}

void rec(int cur)
{
  if (cur == n)
  {
    int fakes = 0;
    for (int i = 0; i < n; ++i)
      if (fake[i] && contains(a, a[i]) && contains(b, b[i]))
        ++fakes;
    if (fakes > ans)
      ans = fakes;
    return;
  }
  fake[cur] = true;
  rec(cur + 1);
  fake[cur] = false;
  rec(cur + 1);
}

int main()
{
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; ++test)
  {
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> a[i] >> b[i];
    ans = 0;
    rec(0);
    cout << "Case #" << test << ": " << ans << endl;
  }
  return 0;
}
