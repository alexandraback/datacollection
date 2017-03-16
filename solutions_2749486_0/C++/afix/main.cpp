// GCJ 1C - Problem B
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

void solve() {
    int x, y;
    string s;
    fin >> x >> y;
    int n = 2 * abs(y) - (y > 0);
    for (int i = 0; i < n; ++i) {
        s += (i % 2 ? "S" : "N");
    }
    if (x < 0) {
        for (int i = 0; i < -x; ++i)
            s += "EW";
    } else {
        for (int i = 0; i < x; ++i)
            s += "WE";
    }

    fout << s << endl;
}

void init() {

}

int main()
{
    int T;
    fin >> T;
    for (int I = 1; I <= T; ++I) {
        fout << "Case #" << I << ": ";
        init();
        solve();
    }

    return 0;
}

