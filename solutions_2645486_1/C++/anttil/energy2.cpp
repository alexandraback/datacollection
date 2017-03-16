#include <iostream>

#define lli long long int

using namespace std;

int T;
lli E, R, N;
lli v[10000];

void laske(int n) {
    cin >> E >> R >> N;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    lli g = 0;
    lli e = E;
    for (int i = 0; i < N; i++) {
        int s = -1;
        for (int j = i+1; j < N; j++) {
            if (v[j] > v[i]) {
                s = j;
                break;
            }
        }
        if (s == -1) {
            g += v[i]*e;
            e = 0;
        } else {
            lli a = E-(s-i)*R;
            if (a < 0) a = 0;
            if (e > a) {
                g += (e-a)*v[i];
                e = a;
            }
        }
        e += R;
        if (e > E) e = E;
    }
    cout << "Case #" << n << ": " << g << endl;
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        laske(i+1);
    }
}
