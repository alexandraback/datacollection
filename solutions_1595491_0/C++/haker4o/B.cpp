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

int baseTop(int a) {
    return a/3 + (a%3 > 0);
}

bool canIncrease(int a) {
    return a%3 != 1 && a>0;
}

int main() {
    int i, j;
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int NT, T;
    cin>>NT;
    for(T=1; T<=NT; ++T) {
        int n, s, p;
        cin>>n>>s>>p;
        int res=0;
        for(i=0; i<n; ++i) {
            int t;
            cin>>t;
            int top = baseTop(t);
            if (top>=p) {
                res++;
            } else if (top+1 == p && s>0 && canIncrease(t)) {
                res++;
                s--;
            }
        }
        cout<<"Case #"<<T<<": "<<res<<endl;
    }
    return 0;
}
