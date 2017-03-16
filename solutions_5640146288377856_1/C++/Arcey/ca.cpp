#include <fstream>

using namespace std;

long long resolve (int r, int c, int w) {
    return (w + r * (int)((c - 1) / w));
}

int main() {
    ifstream fi("a.in");
    ofstream fo("a.out");

    int totaltest;
    fi >> totaltest;
    for (int test = 1; test <= totaltest; test++) {
        int R, C, W;
        fi >> R >> C >> W;
        fo << "Case #" << test << ": " << resolve(R, C, W) << endl;
    }
    return 0;
}
