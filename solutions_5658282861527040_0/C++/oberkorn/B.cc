#include <iostream>
#include <set>
using namespace std;

typedef pair<int, int> npair;

int solve(int A, int B, int K) {
    set<npair> npairs;
    for (int a=0; a<A; ++a) {
        for (int b=0; b<B; ++b) {
            if ((a & b) < K) {
                npair n(a, b);
            }
        }
    }
    for (int b=0; b<B; ++b) {
        for (int a=0; a<A; ++a) {
            if ((a & b) < K) {
                npair n(a, b);
                npairs.insert(n);
            }
        }
    }
    return npairs.size();
}

int main(int argc, char** argv) {
    int T;
    int case_num = 0;
    for (cin >> T; T>0; --T) {
        int N;
        int A, B, K;
        cin >> A >> B >> K;
        int i=0;
        cout << "Case #" << ++case_num << ": " << solve(A, B, K) << endl;
    }
    return 0;
}
