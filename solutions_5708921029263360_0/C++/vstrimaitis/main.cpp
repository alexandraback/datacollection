#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <climits>
#include <set>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>

typedef long long ll;
typedef long double ld;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;
typedef std::pair<double, double> pdd;

#define PI 3.1415926535897932384626433
#define INF ((1<<30)-1)*2+1
#define mp(a, b) make_pair((a), (b))
#define pb push_back
#define MOD 1000000007
#define MAX_N 10
using namespace std;

struct Outfit{
    int j, p, s;
    bool operator==(const Outfit& other) const{
        return j == other.j && p == other.p && s == other.s;
    }
    bool operator<(const Outfit& other) const{
        if(j == other.j && p == other.p)
            return s < other.s;
        if(j == other.j)
            return p < other.p;
        return j < other.j;
    }
};

ostream& operator<<(ostream& os, const Outfit& o){
    os << o.j+1 << " " << o.p+1 << " " << o.s+1;
    return os;
}

vector<Outfit> ans;
int J, P, S, K;


void solve(){
    int numUsed[MAX_N][MAX_N][MAX_N] = {0},
        jp[MAX_N][MAX_N] = {0},
        js[MAX_N][MAX_N] = {0},
        ps[MAX_N][MAX_N] = {0};
    vector<Outfit> ans;
    for(int j = 0; j < J; j++){
        for(int p = P-1; p >= 0; p--){
            for(int s = S-1; s >= 0; s--){
                if(numUsed[j][p][s] == 0 && jp[j][p] < K && js[j][s] < K && ps[p][s] < K){
                    numUsed[j][p][s]++;
                    jp[j][p]++;
                    js[j][s]++;
                    ps[p][s]++;
                    ans.pb(Outfit{j, p, s});
                }
            }
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}

int main()
{
    freopen("../C-small-attempt0.in","r",stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){

        cin >> J >> P >> S >> K;
        cout << "Case #" << t << ": ";
        solve();
        cout << endl;
    }
    return 0;
}
