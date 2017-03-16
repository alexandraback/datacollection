#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream ifs("B-large.in");
    ofstream ofs("B-large.out");
    int num;
    ifs >> num;
    for (int i = 1; i <= num; i++) {
        string s;
        ifs >> s;
        ofs << "Case #" << i << ": ";
        if (s.find('-') == string::npos) {
            ofs << "0\n";
            continue;
        }
        int flips = 0;
        char previous = s[0];
        for (int j = 0; j < s.size(); j++) {
            if (s[j] != previous) flips++;
            previous = s[j];
        }
        if (s[s.size() - 1] == '-') flips++;
        ofs << flips << endl;
    }
}