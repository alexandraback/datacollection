#include <vector>
#include <iostream>

using namespace std;

int a,b;

long long countWays(int k) {

}

int main() {
    int t;
    cin >> t;
    for (int cases = 1; cases <= t; cases ++) {
        int k;
        cin >> a >> b >> k;
        int count = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                // cout << i <<" "<< j << " " << (i&j)<< " " << ((i & j) < k) << " " << k << endl;
                if ((i & j) < k) count ++;
            }
        }
        cout << "Case #" << cases << ": " << count << endl;
    }
}