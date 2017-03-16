#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 100

int T, N;
string s;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int getNValue() {
    int r = 0;
    int S = s.size();

    for (int i = 0; i < S; i++) {
        for (int j = i + N - 1; j < S; j++) {
            int c = 0;
            int b = 0;
            for (int k = i; k <= j; k++) {
                if (isVowel(s[k])) {
                    c = 0;
                } else {
                    c++;
                }
                b = max(b, c);
            }
            if (b >= N)
                r++;
        }
    }

    return r;
}

int main() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> s >> N;
        cout << "Case #" << i << ": " << getNValue() << endl;
    }
}
