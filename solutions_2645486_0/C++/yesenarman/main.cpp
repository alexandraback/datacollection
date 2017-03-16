#include <cmath>
#include <string>
#include <iostream>

using namespace std;

int E, R, N;
int x[11111], v[11111];

void solve(int testcase) {
    printf("Case #%d: ", testcase);
    cin >> E >> R >> N;
    for (int i=0; i<N; ++i)
        cin >> v[i];
    x[0] = E;
    for (int i=1; i<N; ++i) {
        int j=i-1;
        x[i]=R;
        while (x[i]<E && j>=0 && v[j]<v[i]) {
            int s=min(E-x[i], x[j]);
            x[i] += s;
            x[j] -= s;
            --j;
        }
    }
    int64_t res=0;
    for (int i=0; i<N; ++i)
        res += (int64_t)x[i]*v[i];
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i=1; i<=T; ++i)
        solve(i);
    return 0;
}
