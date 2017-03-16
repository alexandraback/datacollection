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

const int S = 2e4, W = 2e4, N = 1100;

int T, h[W + S];

struct attack
{
  int l, r, h;
  attack() {}
  attack(int l, int r, int h) : l(l), r(r), h(h) {}
} a[N];

pii ind[N];

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  cin >> T;
  for(int q = 0; q < T; q++)
  {
    for(int i = 0; i < W + S; i++)
      h[i] = 0;

    int n, cnt = 0, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
      int di, ni, l, r, h, delta_di, delta_pi, delta_h;
      cin >> di >> ni >> l >> r >> h >> delta_di >> delta_pi >> delta_h;
      l += S, r += S - 1;
      for(int j = 0; j < ni; j++)
      {
        a[cnt] = attack(l, r, h);
        //cout << di << " - l = " << l << ", r = " << r << ", h = " << h << endl;
        ind[cnt] = mp(di, cnt);
        l += delta_pi;
        r += delta_pi;
        h += delta_h;
        di += delta_di;
        cnt++;
      }
    }
    sort(ind, ind + cnt);

    for(int i = 0; i < cnt; )
    {
      int r = i;
      while(r < cnt && ind[i].first == ind[r].first)
      {
        int id = ind[r].second;
        bool f = false;
        //cout << ind[r].first << " - l = " << a[id].l << ", r = " << a[id].r << ", h = " << a[id].h << " --- (";
        for(int j = a[id].l; j <= a[id].r; j++)
        {
          //cout << h[j] << " ";
          if (h[j] < a[id].h)
            f = true;
        }
        //cout << ") --- res = " << f << endl;
        ans += f;
        r++;
      }
      for(int j = i; j < r; j++)
      {
        int id = ind[j].second;

        for(int j = a[id].l; j <= a[id].r; j++)
          h[j] = max(h[j], a[id].h);
      }
      i = r;
    }
    cout << "Case #" << q + 1 << ": " << ans << endl;
  }
  return 0;
}

