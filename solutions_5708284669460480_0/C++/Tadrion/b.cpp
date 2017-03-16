//Tadrion
#include <cstdio>
#include <vector>
#include <iostream>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define CLEAR(x) (memset(x,0,sizeof(x)))
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define VAR(v, n) __typeof(n) v = (n)
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define FOREACH(i, c) for(VAR(i,(c).begin()); i != (c).end(); ++i)
#define DBG(v) cout<<#v<<" = "<<v<<endl;
#define IN(x,y) ((y).find(x)!=(y).end())
#define ST first
#define ND second
#define PB push_back
#define PF push_front
#define MP make_pair
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
int T,K,L,S;
string keys;
string target;
vector<string> gen() {
    vector<string> v;
    v.PB("");
    FOR(y,1,S) {
        vector<string> v2;
        REP(i,SZ(keys))
            REP(j,SZ(v)) {
                v2.PB(v[j]+keys[i]);
            }
        v = v2;
    }
    return v;
}

int main() {
  scanf("%d",&T);
  FOR(TTT,1,T) {
    scanf("%d %d %d",&K,&L,&S);
    cin >> keys;
    cin >> target;
    vector<string> w = gen();
    int cnt = 0;
    int maxx = 0;
    REP(i,SZ(w)) {
            //cout << w[i] << "\n";
            int cntword=0;
            FOR(j,0,S-L) {
                bool ok = 1;
                REP(k,L) {
                    if(w[i][j+k]!=target[k]) {
                        ok=0; break;
                    }
                }
                if(ok) {cntword++; cnt++;}
            }
            maxx = MAX(cntword,maxx);
    }
    double res = maxx - ((double)cnt)/SZ(w);

    printf("Case #%d: %.9f\n",TTT,res);
  }
  return 0;
}
