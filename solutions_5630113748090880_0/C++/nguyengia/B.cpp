#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int n,m,t;
    int a[2500];
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> m;
        memset(a, 0, sizeof(a));
        cout << "Case #" << i+1 << ": ";
        for (int j=0; j<2*m-1; j++) {
            for (int k=0; k<m; k++) {
                cin >> t;
                a[t-1]++;
            }
        }
        for (int j=0; j<2500; j++) {
            if (a[j] % 2 == 1) {
                cout << j+1 << " ";
            }
        }
        cout << endl;
     }
  return 0;
}
