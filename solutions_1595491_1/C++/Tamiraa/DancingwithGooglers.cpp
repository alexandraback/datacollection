#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
#define sqr(x) ((x)*(x))
#define ABS(x) ((x<0)?(-(x)):(x))
#define eps (1e-9)
#define mp make_pair
#define pb push_back
#define Pair pair<int,int>
#define xx first
#define yy second
#define equal(a,b) (ABS(a-b)<eps)
using namespace std;

template<class T> string tostring(T x) { ostringstream out; out<<x; return out.str();}
long long toint(string s) { istringstream in(s); long long x; in>>x; return x; }

/////////////////////////////////////////////////////////////////////////////////////////////////////
bool ok(int a, int b, int c, int k){
     
    if(ABS(a-b)<=k&&ABS(a-c)<=k&&ABS(b-c)<=k)return 1;
    return 0;
}
int main(int argc, char *argv[]) {
    int T, tt=0;
    freopen("dance.in", "r", stdin);
    freopen("dance.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        tt++;
        int n, s, p, t, ret = 0;
        scanf("%d%d%d", &n, &s, &p);
        while(n--){
            scanf("%d", &t);
            bool o = 0;
            for(int i=p; i<=t; i++){
                for(int j=0; j<=t; j++){
                   for(int k=0; k<=t; k++){
                       if(i+j+k==t){
                          vector<int>v;
                          v.pb(i);v.pb(j);v.pb(k);
                          sort(v.begin(), v.end());
                          if(ABS(v[0]-v[1])<=1&&ABS(v[0]-v[2])<=1){
                             //printf("%d: engiin %d %d %d\n", t, v[0], v[1], v[2]);
                             o = 1;
                             i=j=k=t;
                          }
                       }
                   }
                }
            }
            if(o){
              ret++;
              o=0;
            }
            else if(s>0){
            for(int i=p; i<=t; i++){
                for(int j=0; j<=t; j++){
                   for(int k=0; k<=t; k++){
                       if(i+j+k==t){
                          vector<int>v;
                          v.pb(i);v.pb(j);v.pb(k);
                          sort(v.begin(), v.end());
                          if(ABS(v[0]-v[1])<=2&&ABS(v[0]-v[2])<=2){
                             //printf("%d: ashiglav %d %d %d\n", t, v[0], v[1], v[2]);
                             o = 1;
                             i=j=k=t;
                             s--;
                          }
                       }
                   }
                }
            }
            }
            if(o)ret++;
        }
        printf("Case #%d: %d\n", tt, ret);
    }
return 0;
}
