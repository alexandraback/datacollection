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
#include <sstream>

#define mp make_pair

using namespace std;

typedef long long ll;

inline ll rev(ll a) {
    ll res=0;
    while(a) {
        res *= 10;
        res += a%10;
        a /= 10;
    }
    return res;
}

int dyn[1<<21];
int from[1<<21];

void print(int n) {
    cout<<n;
    while(n>1) {
        while(n > 1 && from[n] == n-1) --n;
        if (n == 1) break;
        cout<<" "<<n;
        n = from[n];
    }
    cout<<endl;
}

ll toNum(string s) {
    stringstream ss;
    ll res;
    ss<<s;
    ss>>res;
    return res;
}

string toS(ll num) {
    stringstream ss;
    string res;
    ss<<num;
    ss>>res;
    return res;
}

int numD (ll num) {
    int res=0;
    while(num>0) {
        res++;
        num /= 10;
    }
    return res;
}

ll largestWithD(int d) {
    string resS = "";
    for(int i=0; i<d/2; ++i) resS += "9";
    for(int i=d/2; i<d-1; ++i) resS += "0";
    resS += "1";
    return toNum(resS);
}

ll nextNum(ll cur) {
    cur -= 1;
    string resS = "";
    int d = numD(cur);
    string curS = toS(cur);
    for(int i=0; i<d/2; ++i) {
        resS += curS[i];
    }
    for(int i=d/2; i<d-1; ++i) resS += "0";
    resS += "1";
    ll res = toNum(resS);
    ll revRes = rev(res);
    if (res == revRes) {
        res = largestWithD(d-1);
    }
    return res;
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T, NT;
    cin>>NT;
    ll i, j, n, m;
    memset(dyn, -1, sizeof(dyn));
    dyn[1] = 1;
//    for (i=1; i<2000000; ++i) {
//        if (dyn[i+1] == -1 || dyn[i+1] > dyn[i]) {
//            dyn[i+1] = dyn[i] + 1;
//            from[i+1] = i;
//        }
//        int t = rev(i);
//        if (t <= i || t > 2000000) continue;
//        if (dyn[t] == -1 || dyn[t] > dyn[i]) {
//            dyn[t] = dyn[i] + 1;
//            from[t] = i;
//        }
//    }

    for(T=1; T<=NT; ++T) {
        cin>>n;
//    for(i=1; i<2000000; ++i) {
//        n = i;
        ll remN = n;
        ll res = 0;
        while(n > 20) {
            ll next = nextNum(n);
            res += n - next + 1;
            n = rev(next);
        }
        res += n;
//        if (dyn[remN] != res) cout<<"Error: "<<remN<<endl;
        printf("Case #%d: %d\n", T, res);
    }
    return 0;
}
