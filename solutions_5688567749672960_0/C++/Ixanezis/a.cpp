#include <iostream>
#include <cstring>
#include <stdexcept>

using namespace std;

int d[1000010];
int prv[1000010];

int flip(int x) {
    int ret = 0;
    for (;x; x/=10)
        ret = ret*10 + x%10;
    return ret;
}

int main() {
    int t; cin >> t;

    memset(d, 0x7f, sizeof d);
    d[1] = 1;
    for (int i=1; i<=1000000; ++i) {
        d[i+1] = min(d[i+1], d[i] + 1);
        int fl = flip(i);
        if (fl < i) {
            if (d[fl] > d[i] + 1) {
                throw logic_error("oh no no no");
            }
        }
        d[fl] = min(d[fl], d[i] + 1);
    }

    for (int e=1; e<=t; ++e) {
        int x; cin >> x;
        cout << "Case #" << e << ": " << d[x] << endl;
    }

    return 0;
}



