#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN 1000010

long long step[MAXN];

long long reverse(long long t) {
    int num[20];
    int l = 0;
    while (t) {
        num[l++] = t % 10;
        t = t / 10;
    }
    long long ret = 0;
    for (int i=0; i<l; i++) {
        ret = ret*10 + num[i]; 
    }
    return ret;
}

void preprocess() {
    for (int i=1; i<MAXN; i++) {
        step[i] = 0;
    }
    step[1] = 1;
    for (int i=1; i<=1000000; i++) {
        if (step[i+1]==0 || step[i+1]>step[i]+1) {
            step[i+1] = step[i] + 1;
        }
        long long r = reverse(i);
        if (r>=MAXN) {
            continue;
        }
        if (step[r]==0 || step[r]>step[i]+1) {
            step[r] = step[i]+1;
        }
    }
}

void solve() {

    long long c;
    cin >> c;
    cout << step[c] << endl;
}

int main() {
    int T;
    preprocess();
    cin >> T;
    for (int t=1; t<=T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
