#include <cmath>
#include <string>
#include <iostream>

using namespace std;

int64_t r,t;

bool enough(int64_t r, int64_t t, int64_t m) {
    t -= 2*m*(m+1)-3*m;
    return t/(2*m) >= r;
}

void solve(int testcase) {
    printf("Case #%d: ", testcase);
    cin >> r >> t;
    int64_t le=1, ri=sqrt(t)+1;
    while (le<ri) {
        int64_t m=(le+ri)/2;
        if (enough(r,t,m)) le=m+1; else ri=m;
    }
    cout << le-1 << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i=1; i<=T; ++i)
        solve(i);
    return 0;
}
