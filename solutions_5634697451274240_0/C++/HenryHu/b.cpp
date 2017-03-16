#include <iostream>
using namespace std;

char flipOne(char in) {
    if (in == '+') return '-';
    else return '+';
}

void flip(string& line, int end) {
    string out = "";
    for (int i=0; i<end; i++) {
        out += flipOne(line[end - i - 1]);
    }
    for (int i=end; i<line.length(); i++) {
        out += line[i];
    }
    line = out;
}

int main() {
    int n;
    cin >> n;
    string line;
    getline(cin, line);
    for (int ni=0; ni<n; ni++) {
        getline(cin, line);

        long op = 0;
        int m = line.length();
        while (true) {
            int lastpos = -1;
            for (int i=m-1; i>=0; i--) {
                if (line[i] == '-') {
                    lastpos = i;
                    break;
                }
            }
            if (lastpos == -1) break;
            if (line[0] != '-') {
                int termpos = -1;
                for (int i=0; i<m; i++) {
                    if (line[i] != '+') {
                        termpos = i;
                        break;
                    }
                }
                flip(line, termpos);
                op++;
            }
            flip(line, lastpos + 1);
            op++;
        }

        cout << "Case #" << (ni+1) << ": " << op << endl;
    }
}
