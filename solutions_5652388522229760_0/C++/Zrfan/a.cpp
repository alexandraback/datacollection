#include<iostream>
using namespace std;

int main()
{
  int t, n, w, w1;
  int a[1000], b[1000];
  bool checked[10];
  cin >> t;
  int num;
  for (int ii = 1; ii <= t; ++ii)
  {
    cin >> n;
    if (n == 0)
    {
      cout << "Case #" << ii <<": INSOMNIA" << endl;
      continue;
    }
    w = 0;
    memset(checked, false, sizeof(checked));
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    num = 10;
    while (n > 0)
    {
      a[w] = n % 10;
      b[w] = n % 10;
      n = n / 10;
      if (!checked[a[w]])
      {
        checked[a[w]] = true;
        num--;
      }
      w++;
    }
    int ans = 1;
    w1 = w;
    while (num)
    {
      ans ++;
      int ch = 0;
      int i;
      for (i = 0; i < w; ++i)
      {
        b[i] = b[i] + a[i] + ch;
        ch = b[i] / 10;
        b[i] %= 10;
        if (!checked[b[i]])
        {
          checked[b[i]] = true;
          num--;
        }
      }
      while (ch > 0)
      {
        b[i] = b[i] + ch;
        ch = b[i] / 10;
        b[i] %= 10;
        if (i +1> w1)
          w1 = i +1;
        if (!checked[b[i]])
        {
          checked[b[i]] = true;
          num--;
        }
        ++i;
      }
    }
    cout << "Case #" << ii << ": ";
    for (int i = w1-1; i >=0; --i)
      cout << b[i];
    cout << endl;
  }
  return 0;
}
