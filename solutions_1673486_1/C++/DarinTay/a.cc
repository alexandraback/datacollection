#include <iostream>
#include <cstdio>

using namespace std;

double pA[100001];
double sp[100001];

int main() {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        int a,b;
        cin>>a>>b;

        double pC = 1;
        sp[0] = 1;
        for (int i=0;i<a;i++) {
            cin>>pA[i];
            pC *= pA[i];
            sp[i+1] = sp[i] * pA[i];
        }

        double ans = 2 + b;
        //cout << "default is " << ans << endl;
        ans = min(ans, pC*(b-a+1) + (1-pC)*((b-a)+1+b+1));
        //cout << "Orig ans is " << ans << endl;

        for (int i=a;i>0;--i) {
            int toBackspace = a - i + 1;
            int toType = b - i + 1;
            int toEnter = 1;
            double cur = sp[i-1] * (toBackspace + toType + toEnter) + (1-sp[i-1]) * (toBackspace + toType + toEnter + b + toEnter);
            //cout << "At " << i << " " << toBackspace << " " << toType << " (sp " << sp[i-1] << +"):  " << cur << endl;
            ans = min(ans, cur);
        }

        printf("Case #%d: %.9lf\n", t, ans);
        //cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
