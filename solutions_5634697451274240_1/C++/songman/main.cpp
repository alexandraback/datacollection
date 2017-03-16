#include <bits/stdc++.h>

using namespace std;
using LINT = long long int;
using PII = pair<int,int>;

#define PB push_back
#define FI first
#define SE second
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)

void change(char & c) {
    if(c == '+') c = '-';
    else c = '+';
}

void flip(string & str, int size) {
    for(int i = 0; i < size / 2; ++i) {
        change(str[i]);
        change(str[size - i - 1]);
        swap(str[i], str[size - i - 1]);
    }
    if(size % 2)
        change(str[size / 2]);
}

void process(int caseNum) {

    string str;
    cin >> str;

    int size = str.size();
    int cnt = 0;
    while(size > 0) {
        if(str[size-1] == '+') {
            size--;
            continue;
        }

        int l = 0;
        while(str[l] == '+') l++;

        if(l != 0) {
            flip(str, l);
            cnt++;
        }

        flip(str, size);
        cnt ++;
    }

    cout << "Case #" << caseNum << ": " << cnt << endl;
}

int main() {
    int t;
    cin >> t;
    REP(i, t) process(i+1);
    return 0;
}
