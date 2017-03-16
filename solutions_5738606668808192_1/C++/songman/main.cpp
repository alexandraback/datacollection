#include <bits/stdc++.h>

using namespace std;
using LINT = long long int;
using PII = pair<int,int>;

#define PB push_back
#define FI first
#define SE second
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)

int main() {

    cout << "Case #1:" << endl;

    bitset<32> num;
    num[0] = num[31] = 1;
    int cnt = 0;
    for(int i = 1; i < 31; ++i) {
        for(int j = i + 2; j < 30; ++j) {
            for(int k = j + 2; k < 30; ++k) {
            num[i] = 1; num[i+1] = 1;
            num[j] = 1; num[j+1] = 1;
            num[k] = 1; num[k+1] = 1;
            cnt++;
            cout << num;
            for(int x = 2; x < 10; x+=2)
                cout << ' ' << x+1 << ' ' << 2;
            cout << ' ' << 11 << endl;

            num[i] = 0; num[i+1] = 0;
            num[j] = 0; num[j+1] = 0;
            num[k] = 0; num[k+1] = 0;

            if(cnt == 500) return 0;
            }
        }
    }



    return 0;
}
