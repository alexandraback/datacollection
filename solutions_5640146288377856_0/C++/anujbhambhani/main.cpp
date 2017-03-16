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
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    lint t;
    cin>>t;
    int cs = 0;
    while(t--) {
        cs++;
        int R,C,W;cin>>R>>C>>W;
        int ans = 0;
        if (W==1) {
            ans = R*C;
            cout<<"Case #"<<cs<<": "<<ans<<"\n";
            continue;
        }
        int x;
        for (x=W;x<=C;x+=W) {
            ans++;
        }
        x-=W;
        if (C==x) ans--;
        ans+=W;
        ans = ans + (R-1) * C/W;
        cout<<"Case #"<<cs<<": "<<ans<<"\n";
    }
    return 0;
}