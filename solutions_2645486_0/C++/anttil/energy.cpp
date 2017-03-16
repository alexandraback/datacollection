#include <iostream>

using namespace std;

int T;
int E, R, N;
int v[10];
int p = 0;

void haku(int k, int e, int t) {
    if (k == N) {
        if (t > p) p = t;
        return;
    }
    for (int i = 0; i <= e; i++) {
        int ue = e-i+R;
        if (ue > E) ue = E;
        haku(k+1, ue, t+v[k]*i);
    }
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cout << "Case #" << (i+1) << ": ";
        cin >> E >> R >> N;
        for (int j = 0; j < N; j++) {
            cin >> v[j];
        }
        p = 0;
        haku(0, E, 0);
        cout << p << endl;
    }
}
