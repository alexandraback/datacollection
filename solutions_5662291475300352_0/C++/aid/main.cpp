#include <fstream>

using namespace std;

const int MAXN = 15;
int pos[MAXN], invv[MAXN];

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int t;
    in >> t;
    for(int tt = 0; tt < t; tt++) {
        int m;
        in >> m;
        int n = 0;
        for(int i = 0; i < m; i++) {
            int x, k, invvv;
            in >> x >> k >> invvv;
            for(int j = 0; j < k; j++, invvv++, n++) {
                pos[n] = x;
                invv[n] = invvv;
            }
        }
        out << "Case #" << tt + 1 << ": ";
        if(n == 1) {
            out << 0 << '\n';
            continue;
        }
        if(invv[0] > invv[1]) {
            swap(pos[0], pos[1]);
            swap(invv[0], invv[1]);
        }
        if((long long)(720 - pos[0]) * invv[0] <=
           (long long)(360 - pos[1]) * invv[1])
            out << 1 << '\n';
        else
            out << 0 << '\n';
    }
    return 0;
}
