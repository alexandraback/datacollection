#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int i = 0; i < int(n); i++)

string to_s(int n) {
    ostringstream os;
    os << n;
    return os.str();
}

int to_i(string s) {
    istringstream is(s);
    int n;
    is >> n;
    return n;
}

int rev(int n) {
    string s = to_s(n);
    reverse(s.begin(), s.end());
    return to_i(s);
}

int a[1000001];

int main() {
    a[1] = 1;
    for (int i = 2; i < 1000001; i++) {
        int y = 0;
        if (i % 10 != 0 && (y = rev(i)) < i) a[i] = min(a[i-1], a[y]) + 1;
        else a[i] = a[i-1]+1;
    }

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << a[N] << endl;
    }
}
