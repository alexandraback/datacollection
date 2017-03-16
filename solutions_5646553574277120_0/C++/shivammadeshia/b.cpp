#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int t, c, d, v, x, ind;

    freopen("C-small-attempt0.in", "r", stdin);
    freopen("AnswersC", "w", stdout);

    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> c >> d >> v;
        int a[v+1], b[v+1];
        a[0] = 1;
        for(int j = 1; j <= v; j++) {
            a[j] = 0, b[j] = 0;
        }

        for(int j = 0; j < d; j++) {
            cin >> x;
            ind = 0;
            while(ind + x <= v) {
                b[ind + x] = 1;
                ind++;
                while(ind <= v && a[ind] == 0) ind++;
            }
            for(int k = 1; k <= v; k++)
                a[k] = a[k] | b[k];
        }

        int Count = 0;
        for(int j = 1; j <= v; j++) {
            if(a[j] == 1) continue;
            Count++;
            ind = 0;
            x = j;
            while(ind + x <= v) {
                b[ind + x] = 1;
                ind++;
                while(ind <= v && a[ind] == 0) ind++;
            }
            for(int k = 1; k <= v; k++)
                a[k] = a[k] | b[k];
        }
        cout << "Case #" << i << ": " << Count << "\n";
    }

    return 0;
}
