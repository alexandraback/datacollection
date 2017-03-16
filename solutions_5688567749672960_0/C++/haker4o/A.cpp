#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define mp make_pair

using namespace std;

typedef long long ll;

inline int rev(int a) {
    int res=0;
    while(a) {
        res *= 10;
        res += a%10;
        a /= 10;
    }
    return res;
}

int dyn[1<<20];

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T, NT;
    cin>>NT;
    int i, j, n, m;
    memset(dyn, -1, sizeof(dyn));
    dyn[1] = 1;
    for (i=1; i<1000000; ++i) {
        if (dyn[i+1] == -1 || dyn[i+1] > dyn[i]) dyn[i+1] = dyn[i] + 1;
        int t = rev(i);
        if (t <= i || t > 1000000) continue;
        if (dyn[t] == -1 || dyn[t] > dyn[i]) dyn[t] = dyn[i] + 1;
    }

//    for(i=1; i<150; ++i) {
//        cout<<i<<"\t"<<dyn[i]<<endl;
//    }
    for(T=1; T<=NT; ++T) {
        cin>>n;
        printf("Case #%d: %d\n", T, dyn[n]);
    }
    return 0;
}
