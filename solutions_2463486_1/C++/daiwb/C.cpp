#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;

string i2s(LL n) {
    stringstream ss;
    ss << n;
    string res;
    ss >> res;
    return res;
}

bool isok(string str) {
    int len = str.length();
    REP(i,len/2) {
        if (str[i] != str[len - 1 - i]) return false;
    }
    return true;
}

vector<LL> mm;

void init() {
    FOR(i,1,10000000) {
        if (!isok(i2s(i))) continue;
        LL t = i;
        t *= t;
        if (isok(i2s(t))) mm.push_back(t);
    }
}

void run() {
    LL A, B;
    cin >> A >> B;
    int res = 0;
    REP(i,mm.size()) {
        if (mm[i] < A) continue;
        if (mm[i] > B) break;
        ++res;
    }
    cout << res << endl;
}

int main() {
    init();
    //cout << mm.size() << endl;
    //REP(i,mm.size()) cout << mm[i] << endl;
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
