#include <iostream>

using namespace std;

void Solve() {
    string s;
    cin >> s;
    int result = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        int j = i;
        while (j < s.size() && s[i] == s[j]) ++j; --j;
        i = j;
        if (i == (int)s.size() - 1 && s[i] == '+')
            break;
        ++result;
    }
    cout << result << "\n";
}

int main() {
    int z; scanf("%d", &z);
    for (int i = 0; i < z; ++i) {
        printf("Case #%d: ", i + 1);
        Solve();
    }
    return 0;
}
