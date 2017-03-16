#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

vector<string> v1, v2;
int n;

bool check(int mask) {
    set<string> s1, s2;
    for(int i=0; i<n; ++i) {
        if (((mask>>i) & 1) == 0) {
            s1.insert(v1[i]);
            s2.insert(v2[i]);
        }
    }
    for(int i=0; i<n; ++i) {
        if (((mask>>i) & 1) == 1) {
            if (s1.count(v1[i]) == 0 || s2.count(v2[i]) == 0) return false;
        }
    }
    return true;
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int T, NT;
    int i, j;
    cin>>NT;
    for(T=1; T<=NT; ++T) {
        cin>>n;
        v1.clear();
        v2.clear();
        string s1, s2;
        for(i=0; i<n; ++i) {
            cin>>s1>>s2;
            v1.push_back(s1);
            v2.push_back(s2);
        }
        int res = 0;
        for(i=0; i<(1<<n); ++i) {
            if (check(i)) {
                res = max(res, __builtin_popcount(i));
            }
        }
        cout<<"Case #"<<T<<": "<<res<<endl;
    }
    return 0;
}
