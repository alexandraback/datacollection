#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int T, N;
long E, R;

long v[10000];
long e0[10000];
long ec[10000];
int mx[10000];

int main()
{
    ios::sync_with_stdio(false);
    cout.precision(8);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> E >> R >> N;

        for (int i = 0; i < N; i++) {
            cin >> v[i];
            mx[i] = i;
            e0[i] = E;
            ec[i] = E;
        }
        sort(&mx[0], &mx[N], [=](int l, int r){ return v[l] != v[r] ? v[l] > v[r] : l > r;});


        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (mx[i] > mx[j]) {
                    e0[mx[i]] = min(e0[mx[i]], e0[mx[j]] - ec[mx[j]] + R*(mx[i] - mx[j]));
                    ec[mx[i]] = min(ec[mx[i]], e0[mx[i]]);
                } else {
                    ec[mx[i]] = min(ec[mx[i]], R*(mx[j] - mx[i]));
                }
            }
        }
//for (int i = 0; i < N; i++) cerr << e0[i] << ":" << ec[i] << " "; cout << endl;

        long V = 0;
        for (int i = 0; i < N; i++) V += v[i] * ec[i];

        cout << "Case #" << t << ": " << V << endl;
    }
}
