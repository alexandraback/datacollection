#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int t;
    in >> t;
    int r;
    int c;
    int w;
    for(int i = 0; i < t; i++) {
        in >> r >> c >> w;
        int res = (w + (c - w) / w + (c % w != 0));
        out << "Case #" << (i + 1) << ": " << res << endl;
    }
    return 0;
}
