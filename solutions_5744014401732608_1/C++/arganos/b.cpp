#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int t;


int main() {
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case #"<<i<<": ";
        long long m, b;
        bool mat[100][100];
                
        for (int j = 0; j < 100; j++)
            for (int k = 0; k < 100; k++)
                mat[j][k] = 0;
    
        cin >>b >> m;

        if (m > (1LL<<(b-2))) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        
        for (int k = b-1; k > 1; k--) {
            for (int j = k+1; j <= b; j++)
                mat[k][j] = true;
        }
        
        if (m == (1LL<<(b-2))) {
            for (int j = 2; j <= b; j++)
                mat[1][j] = 1;
        } else {
    
        int cnt = b-1;
        while (m > 0) {
            mat[1][cnt] = m%2;
            m /= 2;

            cnt--;
        }
        }
        cout << "POSSIBLE"<<endl;

         for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= b; k++)
                cout << mat[j][k];
            cout << endl;
        }
    

   //     cout << endl;
    }

    return 0;
}
