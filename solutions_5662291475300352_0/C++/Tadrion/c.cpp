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
vector<pair<int,double> > v;
double t[2][5];
double spot[5];
int dist[5];

int main() {
  scanf("%d",&T);
  FOR(TTT,1,T) {
    int N;
    v.clear();
    scanf("%d",&N);
    FOR(i,1,N) {
        int D,H,M;
        scanf("%d %d %d",&D,&H,&M);
        FOR(i,0,H-1) {
            v.PB(MP(D,360.0/(M+i)));
        }
     }
    int res = 2;
    if(SZ(v)==1) {
       res = 0;
       //printf("dupa");
    }
    else {
    sort(v.begin(),v.end());

    int D1 = v[0].ST;
    int D2 = v[1].ST;
    int M1 = v[0].ND;
    int M2 = v[1].ND;

    /////////////FOR(i,0,SZ(v)-1) {
    if(M1 > M2) {
        if(D1 != D2) {
            dist[0] = D2-D1;
        }
        else dist[0] = 360;

        FOR(i,1,4) {
            dist[i] = dist[i-1]+360;
        }
        FOR(i,0,4) {
            spot[i] = (dist[i])*360.0/(M1-M2);
        }
        if(D2+spot[1]*M2/360.0 >= 360.0) res = 0;
        else res=1;
    }
    else if(M1 < M2) {
        if(D1 != D2) dist[0] = D1-D2+360;
        else dist[0]=360;

        FOR(i,0,4) {
            spot[i] = (dist[i])*360.0/(M2-M1);
        }
        if(D1+spot[0]*M1/360.0 >= 360.0) res = 0;
        else if(D1+spot[1]*M1/360.0 >= 360.0) res = 1;
        else if(D2+spot[0]*M2/360.0 >= 360.0) res = 1;
        else res=2;
    }
    else res = 0;
    }
    printf("Case #%d: %d\n",TTT,res);
  }
  return 0;
}
