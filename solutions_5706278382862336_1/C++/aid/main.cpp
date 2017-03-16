#include <fstream>

using namespace std;

const long long K = 1ll << 40;
const int P = 40;

long long gcd(long long a, long long b) {
    return b? gcd(b, a % b) : a;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int t;
    in >> t;
    for(int tt = 0; tt < t; tt++) {
        long long p, q;
        char c;
        in >> p >> c >> q;
        long long g = gcd(p, q);
        p /= g;
        q /= g;
        if(K % q) {
            out << "Case #" << tt + 1 << ": impossible\n";
            continue;
        }
        p *= K / q;
        int ans = 0;
        while(1ll << ans <= p)
            ans++;
        ans--;
        ans = P - ans;
        out << "Case #" << tt + 1 << ": " << ans << '\n';
    }
    return 0;
}
