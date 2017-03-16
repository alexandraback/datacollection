#include <iostream>

using namespace std;

void doit(int cas) {
    long long n;
    cin >> n;
    cout << "Case #" << cas << ": ";
    if (n == 0) {
        cout << "INSOMNIA" << endl;
        return;
    }
    bool have[10] = {false};
    int havecount = 0;

    long long m = 0;
    while (havecount < 10) {
        m += n;
        long long o = m;
        while (o > 0) {
            int x = o % 10;
            if (!have[x]) {
                havecount += 1;
                have[x] = true;
            }
            o /= 10;
        }
    }
    cout << m << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) doit(i);
    return 0;
}
