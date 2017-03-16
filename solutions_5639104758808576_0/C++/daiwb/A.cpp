#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

void run() {
    int n;
    string str;
    cin >> n >> str;

    int sum = str[0] - '0', cnt = 0;
    FOR(i, 1, n) {
        int a = str[i] - '0';
        if (a == 0) continue;

        if (sum >= i) {
            sum += a;
        }
        else {
            cnt += i - sum;
            sum = i + a;
        }
    }
    cout << cnt << endl;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
