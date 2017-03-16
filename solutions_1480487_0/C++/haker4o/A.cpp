#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <sstream>

#define mp make_pair

using namespace std;

bool check(vector<int>& v, int s, double d) {
    double votesNeeded=0.0;
    for(int i=0; i<v.size(); ++i) {
        if (v[i] < d) {
            votesNeeded += d-v[i];
        }
    }
    if (votesNeeded < (double)s) return false;
    return true;
}

vector<double> calc(vector<int>& v) {
    int sum=0;
    int n = v.size();
    int i, j;
    for(i=0; i<n; ++i) {
        sum += v[i];
    }
    double s, e, m;
    s = 0;
    e = sum;
    while(e-s > 1e-9) {
        m = (s+e)/2;
        if (check(v, sum, m)) e = m;
        else s = m;
    }
    m = (s+e) / 2;
    vector<double> res;
    for(i=0; i<n; ++i) {
        if (v[i] < m) {
            res.push_back((m-v[i]) / sum * 100.0);
        } else {
            res.push_back(0.0);
        }
    }
    return res;
}

int main() {
    int i, j;
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int NT, T;
    cin>>NT;
    int n, s;
    vector<int> v;
    for(T=1; T<=NT; ++T) {
        cin>>n;
        s = 0;
        v.resize(n);
        for(i=0; i<n; ++i) {
            cin>>v[i];
            s += v[i];
        }
        vector<double> res = calc(v);
        cout<<"Case #"<<T<<":";
        for(i=0; i<n; ++i) {
            printf(" %.6lf", res[i]);
        }
        printf("\n");
    }
    return 0;
}

