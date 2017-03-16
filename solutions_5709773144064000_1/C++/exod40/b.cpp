#include <cstdio>
#include <algorithm>
using namespace std;

double c, f, x;

void read() {
    scanf("%lf%lf%lf", &c, &f, &x);
}

void solve() {
    double p = 2.;
    double t = 0;
    double ans = 1e100;
    
    for (int i = 0; i <= 1000000; i++) {
        ans = min(ans, t + x / p);
        
        t += c / p;
        p += f;
    }
    
    printf ("%.7lf\n", ans);
}

int main() {
    int cases;
    
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++) {
        read();
        printf("Case #%d: ", i);
        solve();
    }
    
    return 0;
}
