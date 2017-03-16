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

int shift(int a, int nd) {
    return (a%nd) * 10 + a/nd;
}

int main() {
    int i, j;
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int NT, T;
    cin>>NT;
    for(T=1; T<=NT; ++T) {
        int a, b;
        cin>>a>>b;
        int nd=1;
        while(nd*10 <= a) nd *= 10;
        long long res=0;
        for(i=a; i<b; ++i) {
            for(j=shift(i, nd); j!=i; j=shift(j, nd)) {
                if (j > i && j <= b) ++res;
            }
        }
        cout<<"Case #"<<T<<": "<<res<<endl;
    }
    return 0;
}
