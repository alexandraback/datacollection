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

int n;
int a[1<<22];
int nums[512];

int calc(int mask) {
    int res=0;
    for(int i=0; i<n; ++i) {
        if ((mask>>i) & 1) res += nums[i];
    }
    return res;
}

void print(int mask) {
    int i;
    for(i=0; i<n; ++i) {
        if ((mask>>i) & 1) break;
    }
    cout<<nums[i];
    for(++i; i<n; ++i) {
        if ((mask>>i) & 1) cout<<" "<<nums[i];
    }
    cout<<endl;
}

int main() {
    int i, j;
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int NT, T;
    cin>>NT;
    for(T=1; T<=NT; ++T) {
        cin>>n;
        for(i=0; i<n; ++i) {
            cin>>nums[i];
        }
        cout<<"Case #"<<T<<":"<<endl;
        memset(a, 0, sizeof(a));
        bool found = false;
        for(i=0; i<(1<<n); ++i) {
            int cur = calc(i);
            if (a[cur]) {
                print(i);
                print(a[cur]);
                found = true;
                break;
            }
            a[cur] = i;
        }
        if (!found) cout<<"Impossible"<<endl;
    }
    return 0;
}
