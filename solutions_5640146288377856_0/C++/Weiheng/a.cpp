#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

using namespace std;


int solve() 
{
    int r,c,w;
    cin>>r>>c>>w;
    int ans = 0;
    ans += c/w + w;
    if (c%w == 0)
        ans--;
    cout<<ans<<endl;
    return 1;
}

int main() {
    int nc, tc;
    tc = 1;
    cin>>nc;
    while (tc<=nc) {
        cout<<"Case #"<<tc<<": ";
        solve();
        tc++;
    }
    return 0;
}
