#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void tc() {
    int r = 0;
    int n = 0;
    int S; cin >> S;
    for (int i = 0; i <= S; ++i) {
        char k_; cin >> skipws >> k_; int k = k_ - '0';
        if (k > 0 && n < i) r += i-n, n = i;
        n += k;
    }

    static int cas = 1;
    cout << "Case #" << cas++ << ": " << r << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) tc();
}
