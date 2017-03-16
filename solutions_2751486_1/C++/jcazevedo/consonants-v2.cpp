#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 1000000

int T, N;
string s;
long long c[MAX];
long long starts[MAX];

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

long long getNValue() {
    int S = s.size();

    int consonants = 0;
    c[0] = 0;
    starts[0] = 0;
    for (int i = 1; i <= S; i++) {
        if (isVowel(s[i - 1]))
            consonants = 0;
        else
            consonants++;

        if (consonants >= N)
            starts[i] = (i - N + 1);
        else
            starts[i] = starts[i - 1];

        c[i] = c[i - 1] + starts[i];
    }

    return c[S];
}

int main() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> s >> N;
        cout << "Case #" << i << ": " << getNValue() << endl;
    }
}
