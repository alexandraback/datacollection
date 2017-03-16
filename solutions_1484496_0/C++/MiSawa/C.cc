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

typedef vector<ll> vi;

typedef vector<vi> vii;

vii x;
void solve(){
    x.clear();
    x = vii(2000010);
    int N;
    cin >> N;
    vi a;
    rep(i,N){
        ll tmp;
        cin >> tmp;
        a.pb(tmp);
        x[tmp].pb(1<<i);
    }
    for(int i=0; i<x.size(); ++i){
        for(int j=0; j<x[i].size(); ++j){
            /*
            for(int k=0; k<x[i].size(); ++k){
                for(int l=k+1; l<x[i].size(); ++l){
                    if((x[i][k]&x[i][l])==0){
                        cout << x[i][k] << ", " << x[i][l] << endl;
                        return;
                    }
                }
            }*/
            for(int k=0; k<N; ++k){
                if(x[i][j] & (1<<k)){
                }else{
                    int nx = i + a[k];
                    int flg = 0;
                    for(int l = 0; l < x[nx].size(); ++l){
                        if(x[nx][l] == (x[i][j] | (1<<k))){
                            flg = 1;
                            break;
                        }else if((x[nx][l] &( x[i][j] | (1<<k))) == 0){
                            for(int m = 0; m < N; ++m){
                                if(x[nx][l] & (1<<m)) cout << a[m] << " ";
                            }cout << endl;
                            for(int m = 0; m < N; ++m){
                                if(x[i][j] & (1<<m)) cout << a[m] << " ";
                            }cout << a[k] << endl;

                            return;
                        }
                    }
                    if(!flg) x[i+a[k]].pb(x[i][j] | (1<<k));
                }
            }
        }
    }
    return;
}


int main(void){
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": " << endl;
        solve();
    }
    return 0;
}

