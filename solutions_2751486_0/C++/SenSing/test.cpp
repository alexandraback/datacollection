#include <iostream>
#include <string>

using namespace std;

int main() {
    long long T;
    cin >> T;
    for (long long ca = 0; ca < T; ca++) {
        string s;
        long long n;
        cin >> s >> n;
        long long ans = 0;
        long long j = 0;
        long long len = 0;
        for (long long i = 0; i < (long long)s.size(); i++) {
            char ch = s[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                len = 0;
            } else {
                len++;
            }
            if (len >= n) {
                j = i - n + 2;
            }
            ans += j;
        }
        cout << "Case #" << ca + 1 << ": " << ans << "\n";
    }
    return 0;
}
