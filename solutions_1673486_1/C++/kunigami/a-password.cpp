#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 123123

double p[MAXN];

int main (){

    int T, a, b;
    cin >> T;
    for(int t = 0; t < T; t++){
        cin >> a >> b;
        for(int i = 1; i <= a; i++)
            cin >> p[i];
        p[0] = 1.0;
        for(int i = 1; i <= a; i++)
            p[i] *= p[i-1];
        
        int ky = b - a + 1;
        int kn = 2*b + 2 - a;
        double bestE = b + 2;

        for(int i = a; i >= 0; i--){
            double e = ky*p[i] + kn*(1 - p[i]);
            ky += 2;
            kn += 2;
            bestE = min(e, bestE);
        }
        printf("Case #%d: %.6lf\n", t+1, bestE);
    }

    return 0;
}
