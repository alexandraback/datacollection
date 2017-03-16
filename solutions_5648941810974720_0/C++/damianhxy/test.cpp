#include <iostream>
#include <stack>
#include <string>
using namespace std;

int T;
struct trie {
    int A[26];
} tmp;
bool found;
string S;
string ANS;
string A[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void dfs(trie str) {
    if (found) return;
    bool done = true;
    for (int a = 0; a < 26; ++a)
        done &= str.A[a] == 0;
    if (done) {
        found = true;
        cout << ANS;
        return;
    }
    for (int a = 0; a < 10; ++a) {
        bool can = true;
        trie tmp2 = str;
        for (int b = 0; b < (int)A[a].size(); ++b) {
            --tmp2.A[A[a][b] - 'A'];
            if (tmp2.A[A[a][b] - 'A'] < 0) can = false;
        }
        if (can) {
            ANS.push_back(a + '0');
            dfs(tmp2);
            ANS.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int a = 1; a <= T; ++a) {
        cin >> S;
        found = false;
        for (int b = 0; b < 26; ++b)
            tmp.A[b] = 0;
        for (int b = 0; b < (int)S.size(); ++b)
            ++tmp.A[S[b] - 'A'];
        cout << "Case #" << a << ": ";
        dfs(tmp);
        cout << "\n";
    }
    return 0;
}
