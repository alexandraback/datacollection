#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int _t; scanf("%d", &_t);
    for(int _i=1; _i<=_t; _i++) {
        int n; scanf("%d", &n);
        vector<double> naomi, ken;
        for(int i=0; i<n; i++) {
            double x; scanf("%lf", &x);
            naomi.push_back(x);
        }
        for(int i=0; i<n; i++) {
            double x; scanf("%lf", &x);
            ken.push_back(x);
        }
        sort(naomi.begin(), naomi.end());
        sort(ken.begin(), ken.end());
        int kl=0; // lowest block's index
        int dn=0; // deceitful score
        int tn=0; // truthful score
        for(int i=0; i<n; i++) {
            if(naomi[i] > ken[kl]) {
                dn++;
                kl++;
            }
        }
        kl=n-1;
        for(int i=n-1; i>=0; i--) {
            if(naomi[i] > ken[kl]) {
                tn++;
            } else {
                kl--;
            }
        }
        printf("Case #%d: %d %d\n", _i, dn, tn);
    }
}
