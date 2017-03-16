#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <set>

#define For(i,a,b) for(int i = a; i < b; i++)
#define rep(i,x) For(i,0,x)
#define foreach(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define TWO(x) (1LL<<(x))

#define ll long long


ll doit(ll in) {
    std::vector<int> v;
    while(in != 0) {
        v.push_back(in % 10); 
        in /= 10;
    }
    ll res = 0;
    for(size_t i = 0; i < v.size(); i++) {
        res *= 10;
        res += v[i];
    }
    return res;
}

static const int MAXN=1000000;
int DP[MAXN+1];

using namespace std;
int main() {

memset(DP, 0x4f, sizeof(DP));
DP[1] = 1;

for(int i = 1; i < MAXN; i++) {
    int at = DP[i];
    if(doit(i) > i && doit(i) <= MAXN) {
        int to = doit(i);
        DP[to] = std::min(DP[to], at + 1);
    }
    int to = i + 1;
    DP[to] = std::min(DP[to], at+1);
}

int nprob; cin >> nprob;
rep(tprob, nprob) {
    int n; cin>>n;

    cout << "Case #" << (tprob + 1) << ": " << DP[n] << std::endl;
} 
}
