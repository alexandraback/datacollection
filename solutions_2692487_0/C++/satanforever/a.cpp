#include <iostream>
#include <cstdlib>
using namespace std;
int a[128];
int N;
int main () {
    int Tc;
    cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        cout << "Case #" << tt << ": ";
        long long sum;
        cin >> sum >> N;
        for (int i = 0; i < N; i++)
            cin >> a[i];
        sort(a, a + N);
        /*
        for (int i = 0; i < N; i++)
            cout << a[i] << "  ";
        cout << endl;
        */
        int cnt = 0, res = N;
        for (int i = 0; i < N; i++) {
            if (a[i] >= sum && sum == 1)
                break;
            while (a[i] >= sum) {
                sum += sum - 1;
                cnt++;
            }
            sum += a[i];
            if (cnt + N - i - 1 < res)
               res = cnt + N - i - 1;
        }
        cout << res << endl;
    }
    return 0;
}


