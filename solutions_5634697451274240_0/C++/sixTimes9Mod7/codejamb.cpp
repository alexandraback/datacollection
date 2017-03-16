#include <iostream>
using namespace std;

int N;
bool d1[105];
bool d2[105];

void flip(int v) {
    for(int i = 1; i <= v; ++i) {
        d2[v+1-i] = !d1[i];
    }
    for(int i = 1; i <= v; ++i) {
        d1[i] = d2[i];
    }
}

int main() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": ";
        string s;
        cin >> s;
        N = s.size();
        for(int i = 0; i < s.size(); ++i) {
            d1[i+1] = s[i] == '+';
        }
        d1[N+1] = true;
        int db = 0;
        for(int i = 1; i <= N; ++i) {
            if(d1[i] != d1[i+1]) flip(i), ++db;
        }
        cout << db <<endl;
    }
    return 0;
}
