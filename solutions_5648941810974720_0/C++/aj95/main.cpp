// :)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int c[26], p[10], temp[26], perm_temp[5], d[10];

string arr[] = {"ZERO", "ONE", "TWO",   "THREE", "FOUR",
                "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int perm[] = {1, 3, 5, 7, 9};

int solve(int c[], int perm[]) {
  int i, j, x, mn;
  fill(d, d + 10, 0);
  for (i = 0; i < 5; i++) {
    x = perm[i];
    mn = 1000000001;
    for (j = 0; j < (int)arr[x].size(); j++) {
      if ((x == 3 && arr[x][j] == 'E') || (x == 7 && arr[x][j] == 'E') ||
          (x == 9 && arr[x][j] == 'N'))
        mn = min(mn, c[arr[x][j] - 'A'] / 2);
      else
        mn = min(mn, c[arr[x][j] - 'A']);
    }
    d[x] += mn;
    for (j = 0; j < (int)arr[x].size(); j++)
      c[arr[x][j] - 'A'] -= mn;
  }
  for (i = 0; i < 26; i++)
    if (c[i] > 0)
      return 0;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Users/Ayur/Downloads/A-small-attempt0.in.txt", "r", stdin);
  freopen("/Users/Ayur/Downloads/A-small.txt", "w", stdout);
  int t, tt, i, j, n, mn;
  string s;
  cin >> tt;
  for (t = 1; t <= tt; t++) {
    cout << "Case #" << t << ": ";
    fill(c, c + 26, 0);
    fill(p, p + 10, 0);
    cin >> s;
    n = (int)s.size();
    for (i = 0; i < n; i++)
      c[s[i] - 'A']++;
    for (i = 0; i < 10; i += 2) {
      mn = 1000000001;
      for (j = 0; j < (int)arr[i].size(); j++)
        mn = min(mn, c[arr[i][j] - 'A']);
      for (j = 0; j < (int)arr[i].size(); j++)
        c[arr[i][j] - 'A'] -= mn;
      p[i] += mn;
    }
    for (i = 0; i < 5; i++)
      perm_temp[i] = perm[i];
    do {
      for (i = 0; i < 26; i++)
        temp[i] = c[i];
      if (solve(temp, perm_temp))
        break;
    } while (next_permutation(perm_temp, perm_temp + 5));
    for (i = 0; i < 10; i++)
      p[i] += d[i];
    for (i = 0; i < 10; i++)
      for (j = 0; j < p[i]; j++)
        cout << i;
    cout << '\n';
  }
  return 0;
}