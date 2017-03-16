#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream in;
    in.open("dataset.in");
    ofstream out;
    out.open("dataset.out");

    int T;
    in >> T;

    for (int i = 0; i < T; ++i) {
        string s;
        in >> s;
        int st = 0;
        if (s[0] == '-')
            st = 1;
        int nb = 0;
        for (int pos = 1; pos < s.length(); ++pos)
            if (s[pos] == '-' && s[pos - 1] != '-')
                ++nb;
        out << "Case #" << (i + 1) << ": " << st + 2 * nb << "\n";
    }
    
    in.close();
    out.close();
    return 0;
}
