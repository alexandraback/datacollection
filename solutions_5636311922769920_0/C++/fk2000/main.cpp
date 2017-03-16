#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[20000],n,k,m,ans,t,x;
string s;
void output(int t) {
    cout << "Case #" << t << ": ";
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin >> t;
    for (int tt=1;tt<=t;tt++) {
        cin >> n >> m >> k;
        output(tt);
        for (int i=1;i<=n;i++) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
