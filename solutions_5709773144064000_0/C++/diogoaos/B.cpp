#include <cstdio>

int main() {
    int ntests;
    double c, f, x;
    
    scanf("%d", &ntests);
    
    for (int test = 1; test <= ntests; test++) {
        scanf("%lf %lf %lf", &c, &f, &x);
        double best = 100000.0;
        
        double sk = 0, tk, ck = 0;
        
        for (int k = 0; k < 100000; k++) {
            sk += ck;
            
            tk = (x + sk * f + k * c) / (2.0 + k * f);            
            if (tk < best) {
                best = tk;
            }
            
            ck += c / (2.0 + k * f);
        }
        
        printf("Case #%d: %.7lf\n", test, best);
    }
    
    return 0;
}
