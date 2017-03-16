#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <climits>
#include <vector>
#include <sstream>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long lint;

#define PI 3.1415926535897932385

int main() {
    freopen("a.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    int t;
    int tt = 0;
    cin>>t;
    while (t--) {
        ++tt;
        int ans = 0;
        int d;
        cin>>d;
        vector<int>v(1001);
        int mxx = 1;
        for (int i = 0; i < d; ++i) {
            cin>>v[i];
            mxx = max(mxx, v[i]);
        }
        ans = mxx;
        for (int mx = 1; mx <= mxx; ++mx) {
            int num = mx;
            for (int j = 0; j < d; ++j) {
                num += ((v[j] - 1) / mx);
            }
            //            cout<<num<<" "<<mx<<"\n";
            ans = min(ans, num);
        }
        cout<<"Case #"<<tt<<": "<<ans<<"\n";
    }
    return 0;
}