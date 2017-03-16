#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

int s2i(string s) {
    stringstream ss;
    ss << s;
    int res;
    ss >> res;
    return res;
}

string i2s(int n) {
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

void run() {
    int A, B;
    cin >> A >> B;
    int res = 0;
    FOR(i,A,B) {
        if (!isok(i2s(i))) continue;
        int t = sqrt(i);
        if (t * t != i) continue;
        if (isok(i2s(t))) ++res;
    }
    cout << res << endl;
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
