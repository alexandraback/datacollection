#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <unordered_set>
#include <utility>

using namespace std;

string last_word(string s) {
    string t = "";
    for (auto ch : s) {
        t = max(t + ch, string(1, ch) + t);
    }
    return t;
}

int main(int argc, char **argv) {
    fstream input("/Users/garygaojun/Google Drive/Documents/codejam/the-last-word/the-last-word.in", ios_base::in);
    fstream output("/Users/garygaojun/Google Drive/Documents/codejam/the-last-word/the-last-word.out", ios_base::out);
    if (!input.is_open()) {
        cout << "fail to open input file" << endl;
        return -1;
    }
    int lines;
    input >> lines;
    for (int i = 1; i <= lines; ++i) {
        string s;
        input >> s;
        output << "Case #" << i << ": ";
        output << last_word(s) << endl;
    }
    return 0;
}