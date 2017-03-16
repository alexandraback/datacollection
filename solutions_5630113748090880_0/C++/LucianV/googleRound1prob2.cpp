
#include <fstream>
#include <map>
#include <cstring>
#define dim 3000
#include <deque>
using namespace std;

ifstream in("googleR2.in");
ofstream out("googleR2.out");
int viz[dim];

void solve(int t)
{
    int n;
    in >> n;
    int viz[dim];
    memset(viz,0,sizeof(viz));

    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            in >> x;
            viz[x]++;
        }
    }
    out << "Case #" << t << ": ";
    for (int i = 0; i < 2800; i++) {
        if (viz[i] % 2 != 0) {
            out << i << " ";
        }
    }
    out << "\n";
}

int main()
{
    int T;
    in >> T;
    for (int i = 1; i <= T; i++) {
        solve(i);
    }
    return 0;
}
