
#include <iostream>
#include <algorithm>

using namespace std;

int main (void) {
    freopen("D-large.in", "r", stdin);
    freopen("D-large.out", "w", stdout);
    
    int t, n, c, d, k, l;
    float a[1005], b[1005];
    
    cin >> t;
    
    for (int j = 1; j <= t; j++) {
        cin >> n;
        
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
            
        sort(a, a + n);
        sort(b, b + n);
        
        c = 0;
        k = n - 1;
        
        for (int i = k; i >= 0 && k >= 0; i--) {
            while (a[i] < b[k] && k >= 0)
                k--;
            if (k >= 0)
                c++;
            k--;
        } 

        l = 0;
        d = 0;
        k = 0;
        
        for (int i = 0; i < n && k < n; i++) {
            while (b[k] < a[i] && k < n)
                k++;
            if(k != n)
                d++;
            k++;
        }

        cout << "Case #" << j << ": " << c << " " << n - d << endl;
    }
    
    return 0;
}
