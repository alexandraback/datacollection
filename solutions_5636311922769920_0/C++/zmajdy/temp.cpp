#include <bits/stdc++.h>

#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define uniq(c) sort(all((c))), (c).resize(unique(all((c))) - (c).begin())
#define lobo(c, x) (int) (lower_bound(all((c)), (x)) - (c).begin())
#define upbo(c, x) (int) (upper_bound(all((c)), (x)) - (c).begin())
#define R(i,a,b)  for (int i=a; i<=b; i++)
#define Re(i,a,b) for (int i=a; i>=b; i--)
#define tr(i,a) for (__typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define tes cout << "test" << endl, fflush(stdout);
#define cincout ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define print(_v) cout << #_v << " : "; for (auto _i : _v) cout << _i <<", "; cout << endl;

#define pb push_back
#define mt make_tuple
#define mp make_pair
#define x first
#define y second

#define MOD 1000000007
#define INF 1000111222
#define EPS 1e-9
#define endl "\n"

using namespace std;

typedef long long int64;
typedef pair<int,int> ii;

int T;

int64 getMod(int64 a,int64 b) {
    if (b == 0) return 1;
    int64 temp = getMod(a,b/2);
    if (b&1) return a*temp*temp;
    else return temp*temp;
}

int main () {
    cin >> T;

    R(tc,1,T) {
        int64 k,c; int s; cin >> k >> c >> s;
        vector<pair<int64,int64>> v; 

        int64 pkt = c-1;
        R(i,1,k) {
            v.pb({getMod(k,max(c-i,0LL))*(i-1) + 1 , getMod(k,max(pkt,0LL))*i});
            if (pkt > 0) pkt--;
        }
        
        vector<int64> answer;
        for (int i=sz(v)-1; i>=0; i--) {
            if (v[i] == mp(0LL,0LL)) continue;
            answer.pb(v[i].x);
            for (int j=i-1; j>=0; j--) if (v[j].x <= v[i].x and v[i].x <= v[j].y) v[j] = {0,0};
        }

        cout << "Case #" << tc << ":";

        if (sz(answer) > s) cout << " IMPOSSIBLE";
        else for (auto i : answer) cout << " " << i;

        cout << endl;
    }
}

