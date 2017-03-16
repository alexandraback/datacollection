
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define MAX 10000000

using namespace std;

vector <long long> ps;

inline bool is_palindrome(long long n) {
    vector <int> d;
    while (n > 0)
        d.push_back(n % 10), n /= 10;
    for (int i = 0; i + i + 1 < d.size(); i++)
        if (d[i] != d[d.size() - 1 - i])
            return false;
    return true;
}

void init() {
    for (long long n = 1; n <= MAX; n++)
        if (is_palindrome(n) && is_palindrome(n * n))
            ps.push_back(n * n);

    /*
    cout << ps.size() << endl;
    for (int i = 0; i < ps.size(); i++)
        cout << ps[i] << endl;
    */
}

int solve(long long A, long long B) {
    int cnt = 0;
    for (int i = 0; i < ps.size(); i++)
        if (ps[i] >= A && ps[i] <= B)
            cnt++;
    return cnt;
}

int main() {
    init();

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long A, B;
        cin >> A >> B;
        cout << "Case #" << t << ": " << solve(A, B) << endl;
    }
}

