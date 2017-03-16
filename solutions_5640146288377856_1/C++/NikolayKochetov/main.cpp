#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

string path = "/home/nicolai/work/CLionProjects/untitled/";


int main() {

    int N;
    ifstream in(path + "input.txt");
    in.sync_with_stdio(false);
    ofstream out(path + "output.txt");
    in >> N;
    for (int t = 0; t < N; t++) {
        int r, c, w;
        in >> r >> c >> w;
        int ans;
        if (w == 1)
            ans = r * c;
        else
            ans = r * (c / w) + w - (c % w ? 0 : 1);
        out << "Case #" << t + 1 << ": " << ans << "\n";
    }
    return 0;
}

