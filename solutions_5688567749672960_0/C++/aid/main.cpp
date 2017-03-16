#include <fstream>

using namespace std;

const int MAXK = 16;
long long p10[MAXK];

int getDigCnt(long long x) {
    int res = 0;
    while(x) {
        res++;
        x /= 10;
    }
    return res;
}

long long rev(long long x) {
    long long res = 0;
    while(x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    p10[0] = 1;
    for(int i = 1; i < MAXK; i++)
        p10[i] = p10[i - 1] * 10;
    int t;
    in >> t;
    for(int tt = 0; tt < t; tt++) {
        long long n;
        in >> n;
        int k = getDigCnt(n);
        long long ans = 1;
        for(int i = 1; i < k; i++)
            ans += p10[i / 2] + p10[(i + 1) / 2] - 1 - (i == 1);
        if(!(n % p10[(k + 1) / 2]))
            ans += min(n - p10[k - 1],
                       (n - 1) % p10[(k + 1) / 2] +
                       rev(n - 1) % p10[k / 2] + 1);
        else
            ans += min(n - p10[k - 1],
                       n % p10[(k + 1) / 2] + rev(n) % p10[k / 2]);
        out << "Case #" << tt + 1 << ": " << ans << '\n';
    }
    return 0;
}
