#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <iostream>
#include <string>
#include <array>


using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rendr()
#define sz(v) ((int)v.size())
#define read(x) scanf("%d",&(x))
#define read2(x, y) scanf("%d %d",&(x),&(y))
#define read3(x, y, z) scanf("%d %d %d",&(x),&(y),&(z))

typedef stringstream ss;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vvi;
typedef long double ld;


int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int  t;
    cin >> t;
    int cas = 1;
    int r,c,w;
    while(t--){
        int ans = (r-1) * (c/w);

        cin >> r >> c>> w;
        if(w == 1){
            ans = c;

        }
        else{
            int i=w-1;
            for(;i<c;i+=w){
                ans++;
            }
            i -= w;
            //cout << i  <<" <<" <<endl;
            int after = c - i- 1;
            int before = w -1;
            ans += min(after , 1) + before;
        }

        cout << "Case #" << cas++ <<": " << ans << endl;
    }
return 0;
}
