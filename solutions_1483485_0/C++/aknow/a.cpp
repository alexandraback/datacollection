#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int map[26];

// q -> z
int prepare() {
    const int sampleN = 4;

    char org[sampleN][105] = {
        "a zoo q",
        "ejp mysljylc kd kxveddknmc re jsicpdrysi",
        "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
        "de kr kd eoya kw aej tysr re ujdr lkgc jv"
    };

    char ans[sampleN][105] = {
        "y qee z",
        "our language is impossible to understand",
        "there are twenty six factorial possibilities",
        "so it is okay if you want to just give up"
    };

    for (int i = 0; i < sampleN; ++i) {
        for (int c = 0, N = strlen(org[i]); c < N; ++c) {
            char ch = org[i][c];
            if (isspace(ch)) continue;

            char new_ch = ans[i][c];
            map[ch - 'a'] = new_ch - 'a';
        }
    }
}

int main() {
    prepare();
    // for (int i = 0; i < 26; ++i)
    //     cout << i << " " << map[i] << endl;

    char in[105];
    gets(in);

    int caseN;
    // cin >> caseN;
    caseN = atoi(in);

    for (int i = 1; i <= caseN; ++i) {
        cout << "Case #" << i << ": ";

        gets(in);
        for (int c = 0, N = strlen(in); c < N; ++c) {
            char ch = in[c];
            if (isspace(ch)) cout << ch;
            else if ('a' <= ch && ch <= 'z') cout << char(map[ch - 'a'] + 'a');
            else if ('A' <= ch && ch <= 'Z') cout << char(map[ch - 'A'] + 'A');
        }

        cout << endl;
    }

    return 0;
}

