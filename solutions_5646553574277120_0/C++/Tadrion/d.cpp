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
int C,D,V,x;

set<int> orig;
bool check(set<int> s) {
    int a[40];
    CLEAR(a);
    a[0]=1;
    FOREACH(it,s) {
        FORD(i,V,1) {
            if(i-*it >= 0 && a[i-(*it)]==1) a[i]=1;
        }
    }
    int cnt=0;
    FOR(i,1,V) if(a[i]==1) cnt++;
    return (cnt==V);
}

set<set<int> > gen() {
    set<set<int> > v;
    set<int> s;
    v.insert(s);
    FOR(i,1,5) {
        //printf("%d\n",SZ(v));
        set<set<int> > v2;
        FOR(j,1,V) {
            FOREACH(k,v) {
                set<int> s = *k;
                s.insert(j);
                v2.insert(s);
            }
        }
        v = v2;
    }

    set<set<int> > v2;
    FOREACH(it,v) {
        FOREACH(it2,orig) {
            set<int> s = *it;
            s.insert(*it2);
            v2.insert(s);
        }
    }

    FOREACH(it,v) v2.insert(*it);

    return v2;
}

int goodness(set<int> s) {
    int cnt=0;
    FOREACH(it,s) if(!IN(*it,orig)) cnt++;
   /* printf("goodness: %d\n",cnt);
    FOREACH(it,s) {
        printf("%d ",*it);
    }
    printf("\n");
*/
    return cnt;
}

int main() {
  scanf("%d",&T);
  FOR(TTT,1,T) {
      scanf("%d %d %d",&C,&D,&V);
      orig.clear();
      FOR(i,1,D) {
        scanf("%d",&x);
        orig.insert(x);
      }
      int minn = 6;
      set<set<int> > v = gen();
      FOREACH(it2,v) {
        if(check(*it2)) minn = MIN(minn,goodness(*it2));

      }
    printf("Case #%d: %d\n",TTT,minn);
  }
  return 0;
}
