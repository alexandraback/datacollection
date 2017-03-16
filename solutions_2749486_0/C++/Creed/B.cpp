#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define mp make_pair
#define pb push_back
#define sz(a) ((int)(a).size())

int T, x, y;

void up(int x)
{
  for(int i = 0; i < x; i++)
    cout << "SN";
}
void down(int x)
{
  for(int i = 0; i < x; i++)
    cout << "NS";
}
void right(int x)
{
  for(int i = 0; i < x; i++)
    cout << "WE";
}
void left(int x)
{
  for(int i = 0; i < x; i++)
    cout << "EW";
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  cin >> T;
  for(int q = 0; q < T; q++)
  {
    cin >> x >> y;
    cout << "Case #" << q + 1 << ": ";
    if (x < 0)
      left(-x);
    else
      right(x);

    if (y < 0)
      down(-y);
    else
      up(y);
    cout << endl;
  }
  return 0;
}

