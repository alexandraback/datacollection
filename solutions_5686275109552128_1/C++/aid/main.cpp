#include <fstream>

using namespace std;

const int MAXN = 1005;
int a[MAXN];

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int t;
    in >> t;
    for(int tt = 0; tt < t; tt++) {
        int n;
        in >> n;
        int maxa = 0;
        for(int i = 0; i < n; i++) {
            in >> a[i];
            maxa = max(maxa, a[i]);
        }
        int ans = maxa;
        for(int i = 1; i <= maxa; i++) {
            int s = 0;
            for(int j = 0; j < n; j++)
                s += (a[j] - 1) / i;
            ans = min(ans, s + i);
        }
        out << "Case #" << tt + 1 << ": " << ans << '\n';
    }
    return 0;
}
