#include <bits/stdc++.h>

using namespace std;
using LINT = long long int;
using PII = pair<int,int>;

#define PB push_back
#define FI first
#define SE second
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)

int factor(LINT num) {

    LINT sqnum = sqrt(num) + 1;
    for(int i = 2; i < sqnum; ++i)
        if(num % i == 0)
            return i;

    return -1;
}


vector<pair<bitset<16>, vector<int>>> result;

void check(bitset<16> & jamcoin) {

    vector<int> facts;
    for(LINT base = 2; base <= 10; base += 2) {
        LINT lepow = 1;
        LINT res = 0;

        for(int i = 0; i < 16; ++i) {
            if(jamcoin[i])
                res += lepow;
            lepow *= base;
        }

        int fact = factor(res);
        if(fact != -1) {
            facts.push_back(fact);
            facts.push_back(2);
        }
        else
            return;
    }

    facts.pop_back();

    result.push_back({jamcoin, std::move(facts)});
}

int main() {

    bitset<16> jamcoin;

    jamcoin[0] = jamcoin[15] = 1;

    for(int i = 1; i < 15; ++i) {
        for(int j = i + 1; j < 15; ++j) {
            jamcoin[i] = jamcoin[j] = 1;

            check(jamcoin);

            jamcoin[i] = jamcoin[j] = 0;
        }
    }

    cout << "Case #1:" << endl;

    REP(i, 50) {
        cout << result[i].first;

        REP(j, 9) cout << ' ' << result[i].second[j];
        cout << endl;
    }


    return 0;
}
