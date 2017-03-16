#include <iostream>

using namespace std;

int main(){
    int t;
    
    long long pt[50];
    pt[0] = 1;
    for (int i = 1; i <= 48; i++){
        pt[i] = 2 * pt[i-1];
    }
    
    cin >> t;
    for (int i = 0; i < t; i++){
        int b;
        cin >> b;
        long long m;
        cin >> m;

        if (m > pt[b-2]) {
            cout << "Case #" << i+1 << ": " << "IMPOSSIBLE" << endl;
            continue;
        }
        
        cout << "Case #" << i+1 << ": " << "POSSIBLE" << endl;
  /*
        if (m == pt[b-2]) {
            for (int j = 0; j < b; j++) {
                for (int k = 0; k < b; k++) {
                    if (k > j) cout << "1";
                    else cout << "0";
                }
                cout << endl;
            }
            continue;
        }
*/
        int ar[50] = {0};
        m -= 1;
        while (m > 0) {
            for (int j = 0; j < b; j++) {
                if (pt[j+1] > m) {
                    ar[j] = 1;
                    m -= pt[j];
                    break;
                }
            }
        }
        

        cout << "0";
        for (int j = 2; j <= b-1; j++) {
            cout << ar[b-j-1];
        }
        cout << "1";
        cout << endl;
        
        for (int j = 2; j <= b-1; j++) {
            for (int k = 1; k <= b; k++) {
                if ((ar[b-j-1] == 1) && (k > j)) cout << "1";
                else cout << "0";
            }
            cout << endl;
        }
        
        for (int j = 1; j <= b; j++) cout << "0";
        cout << endl;
        
    }
    return 0;
}
