
#include <iostream>
#include <algorithm>

using namespace std;

int main (void) {
    
    int t, d, p[1010];
    int maxv, minv, sum;
    
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    
    cin >> t;
    
    for (int cs = 1; cs <= t; cs++) {
        
        cin >> d;
        
        maxv = -1;
        
        for (int i = 0; i < d; i++) {
            cin >> p[i];
            maxv = max(maxv, p[i]);
        }
        
        minv = maxv;
        
        for (int i = 1; i <= maxv; i++) {
            sum = i;
            
            for (int j = 0; j < d; j++) {
                if (p[j] > i) {
                    sum += (p[j] % i == 0) ? (p[j]/i - 1) : (p[j]/i);
                }
            }
            minv = min(minv, sum);
        }

        cout << "Case #" << cs << ": " << minv << endl;
    }
    
    return 0;
}
