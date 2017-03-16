#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

bool is_palin(long long x) {
    static int ar[200];
    int len = 0;
    while (x) {
        ar[len++] = x % 10;
        x /= 10;
    }
    for (int i = 0; i < len - 1 - i; ++i) {
        if (ar[i] != ar[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    int TEST = 0;
    vector <long long> squares;
    for (long long i = 0; i < 1e5 + 300; ++i) {
        if (is_palin(i) && is_palin(i * i)) {
            //cout << i << " " << i * i << endl;
            squares.push_back(i * i);
        }
    }

    cin >> TEST;
    for (int test = 1; test <= TEST; ++test) {
        cout << "Case #" << test << ": ";
        long long a, b;
        cin >> a >> b;
        int ans = 0;
        for (int i = 0; i < squares.size(); ++i) {
            ans += (a <= squares[i] && squares[i] <= b);
        }
        cout << ans << endl;
    }
    return 0;
}