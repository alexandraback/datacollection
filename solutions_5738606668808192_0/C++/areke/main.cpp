/*
 ID: areke
 PROG: butter
 LANG: C++
 */

#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <limits>
#include <queue>

using namespace std;

long long n = 16;
long long j = 50;
long long cnt = 0;
vector<long long> v;


long long base(string s, long long b) {
    long long x = 1;
    long long num = 0;
    for (int i = s.length()-1; i >= 0; i--) {
        num += ((long long)(s[i]-'0'))*x;
        x *= b;
    }
    return num;
}



bool prime(long long num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            v.push_back(i);
            return false;
        }
    }
    return true;
}

void recurse(string s) {
    ifstream fin ("input.in");
    ofstream fout ("output.out");
    if (cnt == 50) return;
    if (s.length() == 16 && s[0] == '1' && s[15] == '1') {
        v.clear();
        for (int i = 2; i <= 10; i++) {
            long long num = base(s, i);
            if (prime(num)) {
                return;
            }
        }
        cout << s << " ";
        for (int i = 0; i < 9; i++) {
            cout << v[i];
            if (i == 8) cout << endl;
            else cout << " ";
        }
        cnt++;
        return;
    }
    else if (s.length() >= 16) return;
    recurse(s+"0");
    recurse(s+"1");
    
}

int main() {
    ifstream fin ("input.in");
    ofstream fout ("output.out");
    cout << "Case #1:" << endl;
    
    recurse("");
}