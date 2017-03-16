#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, x = 0, y = 0, j, k;
        int a[1000] = {0};
        int b[1000] = {0};
        vector <double> v, w;
        
        scanf("%d", &n);
        
        for (j = 0; j < n; j++) {
            double x;
            
            scanf("%lf", &x);
            
            v.push_back(x);
        }
        
        for (j = 0; j < n; j++) {
            double x;
            
            scanf("%lf", &x);
            
            w.push_back(x);
        }
        
        sort(v.begin(), v.end());
        sort(w.begin(), w.end());
        
        for (j = 0; j < n; j++) {
            int z = -1;
            
            for (k = 0; k < n; k++) {
                if (a[k] == 0) z = k;
                
                if (a[k] == 0 && v[j] > w[k]) {
                    a[k] = 1;
                    x++;
                    
                    break;
                }
            }
            
            if (k == n) a[z] = 1;
        }
        
        for (j = 0; j < n; j++) {
            if (v[j] > w[n - j - 1]) {
                x = max(x, n - j);
                
                break;
            }
        }
        
        for (j = 0; j < n; j++) {
            int z = -1;
            
            for (k = 0; k < n; k++) {
                if (b[k] == 0 && z == -1) z = k;
                
                if (b[k] == 0 && w[k] > v[j]) {
                    b[k] = 1;
                    
                    break;
                }
            }
            
            if (k == n) {
                b[z] = 1;
                y++;
            }
        }
        
        printf("Case #%d: %d %d\n", i + 1, x, y);
    }
    
    return 0;
}
