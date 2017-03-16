#include <iostream>
#include <bitset>
#include <sstream>

using namespace std;

int print(long long v,int l) {
    stringstream ss;
    ss << bitset<100>(v);
    cout << ss.str().substr(100 - l,l) << endl;
}

int main(int,char**) {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int B;
        long long M;
        cin >> B >> M;
        cout << "Case #" << t << ": ";
        if ((1L << (B-2)) < M) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << "POSSIBLE" << endl;
            print((M << 1) - 1,B);
            for (int i = 0; i < B-1; ++i) {
                print((1LL << (B-2-i))-1,B);
            }
        }
    }
}

