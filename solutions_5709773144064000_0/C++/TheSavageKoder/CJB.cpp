//Problem B. Cookie Clicker Alpha
#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

int main() {
    freopen("CJB.in", "r", stdin);
    freopen("CJB.out", "w", stdout);

    int T;
    cin >> T;
    for(int cse = 1; cse <= T; cse++) {
        long double C, F, X;
        cin >> C >> F >> X;
        long double best = X/2.0, acc = 0;
        for(int i = 0; i <= 100000; i++) {
            double neu = acc + C/(2+F*i) + X/(2+F*(i+1));

            if(best < neu)
                break;
            best = neu, acc += C/(2+F*i);
        }
        cout << "Case #" << cse << ": " << setprecision(7) << fixed << best << endl;
    }
    return 0;
}
