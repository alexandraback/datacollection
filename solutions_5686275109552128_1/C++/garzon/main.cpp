#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int n, maxv;
int pan[1001];

bool check(int x) {
    for(int y=0; y<x; y++) {
        int times = 0;
        for(int i=0; i<n; i++) {
            times += ceil(pan[i] * 1.0 / (x-y) - 0.000001) - 1;
        }
        if(times <= y) return true;
    }
    return false;
}

int binarySearch(int l, int r) {
    if(l == r) return check(l) ? l : -1;
    if(l+1 == r) {
        if(check(l)) return l;
        if(check(r)) return r;
        return -1;
    }
    int m = (l+r) >> 1;
    if(check(m)) {
        int tmp = binarySearch(l, m-1);
        if(tmp == -1) return m; else return tmp;
    } else {
        return binarySearch(m+1, r);
    }
}

int main() {
    int a, t, i;
    cin >> t;
    for(a=0; a<t; a++) {
        cin >> n;
        maxv = 0;
        for(i=0; i<n; i++) {
            cin >> pan[i];
            maxv = max(maxv, pan[i]);
        }
        cout << "Case #" << a+1 << ": " << binarySearch(0, maxv) << endl;
    }
    return 0;
}

