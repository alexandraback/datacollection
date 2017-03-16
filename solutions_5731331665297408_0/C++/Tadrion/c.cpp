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

int T;
vector<vector<int> > v;

int n,m;
int a[10][10];
int zip[10];
int perm[10];

bool verify() {
    if(n==1) return true;
    //int st = perm[0];
    int kt = 1;
    stack<int> s;
    s.push(perm[0]);
    //FOR(i,0,n-1) printf("%d ",perm[i]); printf("\n");
    while(kt < n) {
        if(s.empty()) return false;
        //printf("top: %d\n",s.top());
        if(a[s.top()][perm[kt]] == 0) s.pop();
        else {
            s.push(perm[kt]);
            kt++;
            //if(kt == n) break;
        }
    }
    //printf("true\n");
    return true;
}

int main() {
  scanf("%d",&T);
  FOR(iii,1,T) {
    scanf("%d %d",&n,&m);
    v.clear();
    CLEAR(a);
    CLEAR(zip);
    FOR(i,1,n) perm[i-1] = i;
    //printf("%d %d\n",n,m);
    FOR(i,1,n) scanf("%d",&zip[i]);
    FOR(i,1,m) {int x,y; scanf("%d %d",&x,&y); a[x][y] = a[y][x] = 1;}
    do {
        if(verify()) {
            //FOR(i,0,n-1) printf("%d ",perm[i]);
            //printf("\n");
            vector<int> w;
            FOR(i,0,n-1) w.PB(zip[perm[i]]);
            v.PB(w);
        }
        //printf("%d\n",perm[0]);
    }while(next_permutation(perm,perm+n));
    sort(v.begin(),v.end());

    printf("Case #%d: ",iii);
    FOR(i,0,n-1) printf("%d",v[0][i]);
    printf("\n");
  }

  return 0;
}
