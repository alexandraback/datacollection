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
        int c,d,v;
        cin>>c>>d>>v;
        vector<int>dp(v+1,0);
        dp[0]=1;
        vector<int>denom;
        for (int x=0;x<d;x++){
            int ii; cin>>ii;
            for (int y=v;y>=0;y--) {
                if (dp[y] && (y+ii <= v)) {
                    dp[y+ii]=1;
                }
            }
        }
        int ans = 0;
        for (int x=1;x<=v;x++) {
            if (!dp[x]) {
                ans++;
                for (int y=v;y>=0;y--) {
                    if (dp[y] && (y+x <= v)) {
                        dp[x+y]=1;
                    }
                }
            }
        }
        cout<<"Case #"<<cs<<": "<<ans<<"\n";
    }
    return 0;
}