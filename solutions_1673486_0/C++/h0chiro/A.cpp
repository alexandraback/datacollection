#include <iostream>
#include <cstdio>
using namespace std;

double p[100001];

int main() {
    int t,a,b;
    cin>>t;

    for(int tc=1; tc<=t; ++tc) {
        cin>>a>>b;

        for(int i=0; i<a; ++i) cin>>p[i];

        double ans = 0.0;
        // press enter
        ans = b+2;

        // keep typing
        double pp = 1.0;
        for(int i=0; i<a; ++i) pp *= p[i];
        pp = (b-a+1)*pp + (b-a+1 + b+1)*(1-pp);
        ans = min(pp, ans);

        // press backspace i times
        double exp = 0.0;
        pp = 1.0;
        for(int i=0; i<a; ++i) {
            // press a-i times
            exp = pp * (b-i+1 + a-i) + (1-pp) * (a-i + b-i+1 + b+1);
            pp *= p[i];

            ans = min(exp, ans);
        }

        printf("Case #%d: %.12f\n", tc, ans);
    }
}
