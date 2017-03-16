#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int T;
    string s;
    cin >> T;
    for (int i = 0; i < T;) {
        cin >> s;
        int result = 0;
        while (true) {
            size_t lastMinus = s.find_last_of('-');
            if (lastMinus == string::npos)
                break;
            size_t firstMinus = s.find_first_of('-');
            if (firstMinus > 0) {
                ++result;
                for (int i = firstMinus; --i >= 0;)
                    s[i] = '-';
            }
            reverse(s.begin(), s.begin() + (lastMinus + 1));
            for (int i = lastMinus + 1; --i >= 0;)
                s[i] = (s[i] == '-' ? '+' : '-');
            ++result;
        }
        cout << "Case #" << (++i) << ": " << result << endl;
    }
    return 0;
}
