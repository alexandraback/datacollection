#include <iostream>
#include <cmath>
using namespace std;

bool check(long long number) {
    long long num[100];
    int t = 0;
    while (number) {
        num[t++] = number % 10;
        number /= 10;
    }
    for (int i = 0; i < t / 2; i++) {
        if (num[i] != num[t - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("c_out.txt", "w", stdout);
    
    int t;
    cin >> t;
    for (int task = 1; task <= t; task++) {
        long long a, b;
        cin >> a >> b;
        long long s = sqrt(a);
        if (s * s < a) {
            s++;
        }
        long long t = sqrt(b);
        long long ans = 0;
        for (long long num = s; num <= t; num++) {
            if (check(num) && check(num * num)) {
                ans++;
            }
        }
        cout << "Case #" << task << ": " << ans << endl;
    }
    
    return 0;
}
