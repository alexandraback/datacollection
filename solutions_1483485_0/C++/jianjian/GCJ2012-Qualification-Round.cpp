#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;

string _words[35];
string _google[35];
char _word_map[30] = "yhesocvxduiglbkrztnwjpfmaq";

int main () {
    freopen("A-small.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    // input
    int case_cnt;
    scanf("%d", &case_cnt);

    for (int i = 0; i < case_cnt; ++i) {
        if (0 == i) getchar(); // read return char
        getline(cin, _words[i]);
    }

    //for (int i = 0; i < case_cnt; ++i)
    //    getline(cin, _google[i]);

    // find match
    //for (int cnt_word = 0; cnt_word < case_cnt; ++cnt_word) {
    //    for (int i = 0; i < _words[cnt_word].size(); ++i) {
    //        int word_char = _words[cnt_word][i] - 'a';
    //        char google_char = _google[cnt_word][i];

    //        _word_map[word_char] = google_char;
    //    }
    //}

    // convert
    for (int cnt_word = 0; cnt_word < case_cnt; ++cnt_word) {
        for (int i = 0; i < _words[cnt_word].size(); ++i) {
            char word = _words[cnt_word][i];

            if (islower(word)) {
                int word_char = word - 'a';
                _google[cnt_word].push_back(_word_map[word_char]);
            }
            else
                _google[cnt_word].push_back(word);
        }
    }

    //for (int i = 0; i < 26; ++i) {
    //    char character = 'a' + i;
    //    cout << character << "--" << _word_map[i] << endl;
    //}

    for (int i = 0; i < case_cnt; ++i)
        cout << "Case #" << i+1 << ": " << _google[i] << endl;

    return 0;
}