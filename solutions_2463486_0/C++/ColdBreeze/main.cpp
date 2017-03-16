#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

inline bool isPalin(long long n) {
    long long t=n, nn=0;
    while (t) {
        nn = nn*10 + t%10;
        t /= 10;
    }
    return (nn==n);
}

int main() {
    ifstream cin("in_codejam");
    ofstream cout("out_codejam");
    vector<long long> v;
    for (long long i=1; i<=sqrt(100000000000000); ++i) {
        if (isPalin(i) && isPalin(i*i)) v.push_back(i*i);
    }
    int T, cases=0, len=v.size();
    long long A, B, n, sum;
    cin >> T;
    while (T--) {
        sum = 0;
        cin >> A >> B;
        for (int i=0; i<len; ++i) {
            if (v[i]>=A && v[i]<=B) ++sum;
            if (v[i]>B) break;
        }
        cout << "Case #" << (++cases) << ": " << sum << endl;
    }
    return 0;
}
