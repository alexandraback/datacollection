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

int main(){
    freopen("a.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin>>t;
    int tt = 0;
    while (t--) {
        tt++;
        int n;
        cin>>n;
        n++;
        vector<int>v(n, 0);
        string s;
        cin>>s;
        for (int x=0; x<n; x++) {
            v[x] = s[x] - '0';
        }
        int ans = 0;
        int cur = 0;
        for (int x=0;x<n;x++) {
            if (cur < x) {
                ans += (x-cur);
                cur += (x-cur);
            }
            cur += v[x];
        }
        cout<<"Case #"<<tt<<": "<<ans<<"\n";
    }
    return 0;
}