#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
fstream fsi("B-large.in", fstream::in);
fstream fso("out.txt", fstream::out);

vector<bool> zip;

void solve() {
    int answer, i, j, sz, t;
    string s;
    fsi >> t;
    for (i = 1; i <= t; i++) {
        fsi >> s;
        zip.clear();
        zip.push_back(s[0] == '+');
        for (j = 1; j < s.size(); j++) {
            if (s[j] != s[j-1]) zip.push_back(s[j] == '+');
        }
        reverse(zip.begin(), zip.end());
        sz = zip.size();
        answer = sz;
        if (zip[0]) answer--;
        fso << "Case #" << i << ": "  << answer << '\n';
    }
}

int main() {
    solve();
    return 0;
}
