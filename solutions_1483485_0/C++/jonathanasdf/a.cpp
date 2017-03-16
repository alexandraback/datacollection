#include <iostream>

using namespace std;

string key = "zqejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
string code = "qzour language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";

int main() {
    char map[26];
    for (int i=0; i < key.size(); i++) if (key[i] != ' ') map[key[i]] = code[i];
    
    string sss;
    int T; cin >> T; getline(cin, sss);
    for (int i=0; i < T; i++) {
        string s; getline(cin, s);
        string s2;
        for (int j=0; j < s.size(); j++) s2 += (s[j] == ' ' ? ' ' : map[s[j]]);
        cout << "Case #" << (i+1) << ": " << s2 << endl;
    }
    return 0;
}