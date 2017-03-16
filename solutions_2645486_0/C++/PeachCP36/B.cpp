#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define fi first
#define se second

#define FOR(i,j,k) for(typeof((j)) i = (j); i < (k); ++i)
#define FORE(i,j,k) for(typeof((j)) i = (j); i <= (k); ++i)
#define FOREACH(i,j) for(typeof((j.begin())) i = j.begin(); i != (j).end(); ++i)

typedef pair<int,int>   pii;
typedef vector<int>     vi;
typedef map<int,int>    mii;
typedef long long int   ll;

int _gcd(int a,int b) { if(b==0)return a; return _gcd(b,a%b);}
inline int gcd(int a,int b) { return (a>=b)?_gcd(a,b):_gcd(b,a); }

int g[10000][2];
int v[10000];

void solve(){
    int E,R,N;
    cin >> E >> R >> N;
    FOR(i,0,N) cin >> v[i];
    int remainE = E;
    FORE(i,0,E) g[i][0] = g[i][1] = 0;
    FOR(i,0,N){
        FORE(j,0,E){
            int gain = j*v[i];
            int idx = i&1;
            FORE(k,j,E){
                int newE = min(k - j + R,E);
                g[newE][idx] = max(g[k][1-idx]+gain,g[newE][idx]);
            }
        }
    }
    int idx = (N-1)&1;
    int maxGain = 0;
    FORE(i,0,E){
        maxGain = max(g[i][idx],maxGain);
    }
    cout << maxGain << endl;
}

int main(){
    freopen("Bsmall.in","r",stdin);
    freopen("Bsmall.out","w",stdout);
    int _test;
    scanf("%d",&_test);
    FORE(t,1,_test){
        printf("Case #%d: ", t);
        solve();
    }
    return 0;
}
