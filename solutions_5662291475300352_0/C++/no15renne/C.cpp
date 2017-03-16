
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <climits>
using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define RREP(i,n) for(int i=(int)n-1; i>=0; i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)
#define ALL(c) (c).begin(), (c).end()

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > pipii;
typedef vector<int> vi;

const int INF = 1e9;
const int MOD = 1e9+7;
const double EPS = 1e9;

int main(void){
    int t;
    cin >> t;
    REP(tt, t){
        int ans = INF;
        int n;
        cin >> n;
        vi d(n), h(n), s(n);
        REP(i, n) cin >> d[i] >> h[i] >> s[i];
        
        if(n == 1) ans = 0;
        else if(d[0] == d[1] && s[0] == s[1]){
            ans = 0;
        }
        else{
            double x = (double)(d[1] - d[0]) / (s[0] - s[1]);
            double d = x * s[0];
            if(d - 359 > EPS) ans = 0;
            else ans = 1; 
        }
         
        cout << "Case #" << tt + 1 << ": " << ans << endl;   
    }
	
	return 0;
}

