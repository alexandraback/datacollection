#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int T, t, i;
    double c, f, x, tmp, RES;

    cin >> T;
    for (t=1; t<=T; t++) {
        cin >> c >> f >> x;

        RES = x/2.0; tmp = 0.0;
        for (i=1; ; i++) {
            tmp += c/(2.0+f*(i-1));
            if (RES < tmp+x/(2.0+f*i)) break;
            else RES = tmp+x/(2.0+f*i);
        }
        printf("Case #%d: %.7lf\n", t, RES);
    }

    return 0;
}
