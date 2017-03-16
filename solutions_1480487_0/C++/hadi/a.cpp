#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int t, n, arr[200], sum;

bool check(int idx, double p) {
    double score = arr[idx] + p * sum;
    double psum = p;
    for(int i = 0; i < n; i ++) {
        if(i != idx) {
            double req = max(0.0, (score - arr[i]) / sum);
            psum += req;
        }
    }
    return psum > 1.0;
}

double solve(int idx) {
    double left = 0, right = 1;
    for(int i = 0; i < 100; i ++) {
        double mid = (left + right) * 0.5;
        if(check(idx, mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return left * 100;
}

int main() {
    cin >> t;
    for(int I = 1; I <= t; I ++) {
        cin >> n;
        for(int i = 0;  i < n; i ++) {
            cin >> arr[i];
        }
        sum = 0;
        for(int i = 0; i < n; i ++) {
            sum += arr[i];
        }
        cout << "Case #" << I << ":";
        cout.precision(6);
        cout.setf(ios::fixed | ios::showpoint);
        for(int i = 0; i < n; i ++) {
            cout << " " << solve(i);
        }
        cout << endl;
    }
    return 0;
}