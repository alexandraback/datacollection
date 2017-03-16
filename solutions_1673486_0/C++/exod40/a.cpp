#include <cstdio>
#include <algorithm>
using namespace std;

int n , m;
double a[1 << 17] , b[1 << 17];

void read() {
    int i;
    
    scanf ( "%d%d", &n , &m );
    b[0] = 1;
    for (i = 1; i <= n; i++) { 
        scanf ( "%lf", &a[i] );
        b[i] = b[i - 1] * a[i];
    }
}

void solve() {
    double ans = m + 2;
    int i;
    
    for (i = 0; i <= n; i++) {
        ans = min ( ans , b[i] * (double)(n - i + m - i + 1) + (1 - b[i]) * (double)(n - i + m - i + 1 + m + 1) );
    }
    
    printf ( "%.8lf\n", ans );
}

int main() {
    int i , cases;
    
    scanf ( "%d", &cases );
    for (i = 1; i <= cases; i++) {
        read();
        printf ( "Case #%d: ", i );
        solve();
    }
    
    return 0;
}
