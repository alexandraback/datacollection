#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T; cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        string S; cin >> S;
        string last_word {S[0]};
        auto S_len = S.size();
        for (int i = 1; i < S_len; ++i) {
            auto c = S[i];
            if (c >= last_word[0]) // put this char in front of last_word
                last_word = c + last_word;
            else
                last_word.push_back(c);
        }
        cout << "Case #" << cas << ": " << last_word << "\n";
    }

    return 0;
}
