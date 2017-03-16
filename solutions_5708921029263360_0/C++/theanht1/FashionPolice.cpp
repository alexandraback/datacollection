#include <bits/stdc++.h>

using namespace std;

int n1, n2, n3, k, nres;

int main() {
    //freopen("1.i", "r", stdin);
    freopen("C-small-attempt2.in", "r", stdin);
    freopen("C-small-attempt2.ou", "w", stdout);

    int ts;
    cin >> ts;

    for (int t = 1; t <= ts; t++) {      
      cin >> n1 >> n2 >> n3 >> k;
             
      nres = n1 * n2 * min(k, n3);
      cout << "Case #" << t << ": ";       
      cout << nres << endl;
      for (int i1 = 1; i1 <= n1; i1++)
        for (int i2 = 1; i2 <= n2; i2++)
          for (int i3 = 1; i3 <= min(k, n3); i3++)
            cout << i1 << " " << i2 << " " << i3 << endl;
    }
}
