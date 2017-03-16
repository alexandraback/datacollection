#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool seen[10];
int seencnt;

void update(ll x) {
  while (x) {
    if (!seen[x%10]) {
      seen[x%10] = true;
      seencnt++;
    }
    x /= 10;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  ll t, n, curr;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    fill(seen, seen + sizeof(seen), 0);
    seencnt = 0;

    cin >> n;
    curr = n;

    if (!n) {
      cout << "Case #" << i << ": INSOMNIA\n";
      continue;
    }

    while (1) {
      update(curr);
      if (seencnt == 10) {
        cout << "Case #"  << i << ": " << curr << "\n";
        break;
      }
      curr += n;
    }
  }

  return 0;
}
