#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  int T;
  cin >> T;
  char c;
  cin >> c;
  for (int t = 0; t < T; t++) {
    ll n = 0;
    vector<bool> cons(1000000);
    ll L = 0;

    while (c >= 'a') {
      if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
        cons[L] = true;
      else
        cons[L] = false;
      L++;
      cin >> c;
    }
    while (c < 'a') {
      n = n * 10 + c - '0';
      if ((cin >> c) == false)
        break;
    }

    //for (int i = 0; i < L; i++)
    //  cout << cons[i];
    //cout << endl << "n = " << n << ", t = " << t << endl;

    ll s = -1; // index of last substring found
    ll con = 0; // consonants in a row so far
    ll ans = 0;
    ll i = 0;
    for (auto it = cons.begin(); it != cons.end(); it++) {
      if (cons[i])
        con++;
      else
        con = 0;
      if (con >= n)
        s = i;
      if (s >= 0)
        ans += s - n + 2;
      i++;
      //cout << ans << " ";
      if (i >= L)
        break;
    }
    cout << "Case #" << t + 1 << ": " << ans << endl;
  }

  return 0;
}
