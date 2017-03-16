#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    for(int i = 1; i <= t; i++) {
        int ap[2501];
        memset(ap, 0, sizeof(ap));
        int n;
        cin >> n;
        for(int j = 1; j < n*2; j++) {
            for (int k = 0; k < n; k++) {
                int aux;
                cin >> aux;
                ap[aux]++;
                // cout << aux << " ";
            }
            // cout << endl;
        }

        cout << "Case #" << i << ":";
        for(int j = 1; j <= 2500; j++) {
            if(ap[j]%2)
                cout << " " << j;
        }
        cout << endl;
    }

    return 0;
}
