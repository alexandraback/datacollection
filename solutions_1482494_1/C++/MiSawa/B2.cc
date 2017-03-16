#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <utility>
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
#include <memory>
#include <sstream>
#include <cctype>
#include <unistd.h>
#define REP(i,b,n) for(int i=(int)(b);i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define RREP(i,e,n) for(int i=(int)n-1;i>=(int)(e);--i)
#define rrep(i,n) RREP(i,0,n)
#define foreach(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)


#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;

vector<vector<int> > ls;
vector<vector<bool> > f;
int N;

void solve(){
    int n;
    cin >> n;
    N = n;
    ls.clear();
    f.clear();
    rep(i,n){
        int a,b;
        cin >> a >> b;
        ls.pb(vector<int>(2));
        f.pb(vector<bool>(2, false));
        ls[i][0] = a;
        ls[i][1] = b;
    }
    int res = 0;
    int star = 0;
    while(star != (N<<1)){
        pair<int, int> nx;
        bool flg = false;
        rep(i, N){
            rep(j, 2){
                if(!f[i][j] && ls[i][j] <= star){
                    if(flg && nx.second){
                    } else if(j){
                        nx = mp(i, j);
                        flg = true;
                    } else if(!flg){
                        nx = mp(i, j);
                        flg = true;
                    } else if(flg && !j && !nx.second && ls[i][1] >= ls[nx.first][1]){
                        nx = mp(i,j);
                        flg = true;
                    }
                }
            }
        }
        if(!flg){
            cout << "Too Bad" << endl;
            return;
        }
        int i = nx.first, j = nx.second;
        f[i][j] = true;
        if(j == 1){
            if(f[i][0]){
                star++;
            }
            else{
                f[i][0] = true;
                star += 2;
            }
        }
        else if(!f[i][1]) star++;
        ++res;
    }
    cout << res << endl;
}
int main(void){
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}



