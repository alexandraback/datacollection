
#include <iostream>
#include <vector>
#define MAXN 1000

using namespace std;

int N;
vector <int> a, b;

vector <int> read_vec() {
    vector <int> r(N);
    for (int i = 0; i < N; i++) {
        double x;
        cin >> x;
        r[i] = (int) (1e5 * x + 0.5);
    }
    sort(r.begin(), r.end());
    return r;
}

void solve() {
    int points = 0;
    for (int i = 0, j = 0; i < N; i++) {
        while (j < N && b[j] < a[i])
            j++;

        if (j < N)
            j++;
        else
            points++;
    }

    int points_deceit = 0;
    for (int i = 0, j = 0; i < N; i++) {
        if (b[j] < a[i]) {
            j++;
            points_deceit++;
        }
    }

    cout << points_deceit << " " << points << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        a = read_vec();
        b = read_vec();
        cout << "Case #" << t << ": ";
        solve();
    }
}

