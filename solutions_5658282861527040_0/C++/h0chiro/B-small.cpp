#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <complex>
#include <cmath>
#include <algorithm>
using namespace std;

void solve() {
    int A,B,K, ans = 0;
    cin>>A>>B>>K;
    for (int i=0; i<A; ++i) {
        for (int j=0; j<B; ++j)
            if ((i&j) < K) ans++;
    }
    cout<<ans<<endl;
}

int main() {
    int T;
    cin>>T;
    for (int tc=1; tc<=T; ++tc) {
        cout<<"Case #"<<tc<<": ";
        solve();
    }
}
