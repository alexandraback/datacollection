#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        int m = 1000;
        int D;
        cin >> D;
        vector<int> P(D);
        for(int j = 0; j < D; ++j)
            cin >> P[j];
        
        for(int j = 1; j <= 1000; ++j) {
            int repartition = 0;
            
            for(auto e : P)
                repartition += max(0, (e + j - 1)/j - 1);
            m = min(m, j + repartition);
        }
        cout << "Case #" << i << ": " << m << "\n";
    }
}