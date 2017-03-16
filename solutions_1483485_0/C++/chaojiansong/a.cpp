#include <string>
#include <iostream>

using namespace std;

char trans[26];
char s1[3][128] = {
    "ejp mysljylc kd kxveddknmc re jsicpdrysi",
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
    "de kr kd eoya kw aej tysr re ujdr lkgc jv"
};
char s2[3][128] = {
    "our language is impossible to understand",
    "there are twenty six factorial possibilities",
    "so it is okay if you want to just give up"
};

int T;
string line;

int main(int argc, const char *argv[])
{
    trans['q' - 'a'] = 'z';
    trans['z' - 'a'] = 'q';
    for (int i = 0; i < 3; ++i) {
        int len = strlen(s1[i]);
        for (int j = 0; j < len; ++j) {
            if (s1[i][j] != ' ') {
                trans[s1[i][j] - 'a'] = s2[i][j];
            }
        }
    }  
    cin >> T;
    getline(cin, line);
    for (int cas = 1; cas <= T; ++cas) {
        getline(cin, line);
        cout << "Case #" << cas << ": ";
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] == ' ') cout << ' ';
            else cout << trans[line[i] - 'a'];
        }
        cout << endl;
    }
    return 0;
}
