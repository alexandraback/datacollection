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

int main(void){	
	int t;
    cin >> t;
    REP(tt, t){
        int c, d;
        ll v;
        cin >> c >> d >> v;
        vector<ll> x(d);
        REP(i, d) cin >> x[i];
        x.push_back(v + 1);
        ll ans = 0;
        if(x[0] != 1){
            x.push_back(1);
            ans++;
        }
        sort(ALL(x));
        ll sum = 0;
        REP(i, x.size() - 1){
            sum += x[i];
            while(1){
                ll can = sum * c;
                if(x[i+1] <= can + 1){
                    break;
                }
                ans++;
                //cout << "Add " << can + 1 << endl;
                sum += can + 1;
            }
        }
        cout << "Case #" << tt + 1 << ": ";
        cout << ans << endl;
    }


    return 0;
}

