#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 10000000;

long long rev(long long x) {
    long long ans = 0;
    while(x) {
        ans = 10*ans + x % 10;
        x /= 10;
    }
    return ans;
}

bool isPal(long long x) {
    return x == rev(x);
}

int main() {

    vector<long long> fsn;

    for(int i = 1; i <= MAXN; i++) {
        if(isPal(i)) {
            long long sq = i * (long long) i;
            if(isPal(sq)) {
                fsn.push_back(sq);
//                cerr << "fsn: " << sq << endl;
            }
        }
    } 

    int t;
    cin >> t;

    for(int tc = 1; tc <= t; tc++) {
        long long a, b;
        cin >> a >> b;
        cout << "Case #" << tc << ": " << (upper_bound(fsn.begin(), fsn.end(), b) - lower_bound(fsn.begin(), fsn.end(), a)) << '\n';
    }

    return 0;
}
