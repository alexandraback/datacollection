#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

bool consonant(char c) {
    string str = "aeiou";
    for(int i = 0;i<str.size();i++) {
        if (str[i] == c) return false;
    }
    return true;
}

int nextcons(string & input, int pos, int &count, int limit) {
    while(pos < input.size() and count < limit) {
        if (consonant(input[pos])) {
            count++;
        }
        else {
            count = 0;
        }
        pos++;
    }
    return pos;
}

typedef long long LL;

void solve(int cas) {
    string input;
    int limit;
    cin >> input >> limit;
    int count = 0;
    LL res = 0;
    for(int pos = 0, cons = 0;pos < input.size();pos++) {
        if (count == limit and cons - pos < limit) count--;
        if (count < limit) {
            cons = nextcons(input, cons, count, limit);
        }
        if (count == limit) {
            res += (((int)input.size()) + 1 - cons);
        }
    }
    cout << "Case #" << cas << ": " << res << endl;
}

int main() {
    int T;
    cin >> T;
    for(int i = 1;i<=T;i++) solve(i);
    return 0;
}

