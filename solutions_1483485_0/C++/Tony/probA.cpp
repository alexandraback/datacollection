
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#define MAX_LINE 1024

using namespace std;

char c[26];

void add(string input, string output) {
    for (int i = 0; i < input.size(); i++)
        if (input[i] != ' ')
            c[input[i] - 'a'] = output[i];
}

void precompute() {
    for (int i = 0; i < 26; i++)
        c[i] = '-';

    // examples
    add("ejp mysljylc kd kxveddknmc re jsicpdrysi",
        "our language is impossible to understand");
    add("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
        "there are twenty six factorial possibilities");
    add("de kr kd eoya kw aej tysr re ujdr lkgc jv",
        "so it is okay if you want to just give up");

    /*
    for (int i = 0; i < 26; i++)
        cout << (char) ('a' + i) << " to " << c[i] << endl;
    */

    // from problem statement
    c['z' - 'a'] = 'q';
    c['q' - 'a'] = 'z';
}

char buf[MAX_LINE];

string solve() {
    cin.getline(buf, MAX_LINE);
    string line = buf;

    for (int i = 0; i < line.size(); i++)
        if (line[i] != ' ')
            line[i] = c[line[i] - 'a'];

    return line;
}

int main() {
    precompute();

    cin.getline(buf, MAX_LINE);
    int T = atoi(buf);
    for (int i = 0; i < T; i++)
        cout << "Case #" << i + 1 << ": " << solve() << endl;
}
