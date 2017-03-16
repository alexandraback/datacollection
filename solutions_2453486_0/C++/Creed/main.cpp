#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int T, res;
string a[10], t;

int get(string s)
{
  bool f = true;
  for(int i = 0; i < 4; i++)
    f &= (s[i] == 'X' || s[i] == 'T');
  if (f) return 0;

  f = true;
  for(int i = 0; i < 4; i++)
    f &= (s[i] == 'O' || s[i] == 'T');
  if (f) return 1;

  return -1;
}

void upd(int state)
{
  if (state != -1 && res == -1)
    res = state;
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  cin >> T;
  for(int q = 0; q < T; q++)
  {
    for(int i = 0; i < 4; i++)
      cin >> a[i];
    int all = 0;
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
        all += a[i][j] != '.';

    res = -1;

    for(int i = 0; i < 4; i++)
      upd(get(a[i]));

    for(int i = 0; i < 4; i++)
    {
      t = "";
      for(int j = 0; j < 4; j++)
        t += a[j][i];
      //cout << t << endl;
      upd(get(t));
    }

    t = "";
    for(int i = 0; i < 4; i++)
      t += a[i][i];
    //cout << t << endl;
    upd(get(t));

    t = "";
    for(int i = 0; i < 4; i++)
      t += a[i][3 - i];
    //cout << t << endl;
    upd(get(t));

    cout << "Case #" << q + 1 << ": ";

    if (res == -1)
    {
      if (all == 16)
        cout << "Draw" << endl;
      else
        cout << "Game has not completed" << endl;
    }
    else if (res == 0)
    {
      cout << "X won" << endl;
    }
    else
    {
      cout << "O won" << endl;
    }
  }
  return 0;
}
