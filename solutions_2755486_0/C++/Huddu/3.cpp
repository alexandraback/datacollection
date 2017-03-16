#include "stdio.h"
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct tribe {
  int d, n, w, e, s, del_d, del_p, del_s;
  tribe() {
    d=n=w=e=s=del_d=del_p=del_s=0;
  }
};
struct attack {
  int w, e, s;
  attack(int w_, int e_, int s_) {
    w=w_;
    e=e_;
    s=s_;
  }
};
vector<tribe> T;
map<int, int> H;
map <int, vector<attack> > A;
void process_attacks(tribe t) {
  int num = t.n;
  for (int i=0; i<num; i++) {
    int day = t.d+(i*t.del_d);
    int w= t.w+(i*t.del_p);
    int e= w + (t.e - t.w);
    int s = t.s+(i*t.del_s);
    A[day].push_back(attack(w, e, s)); 
  }
}
int main() {
  int t;
  scanf("%d", &t);
  for(int x=1; x<=t; x++) {
    int n;
    T.clear();
    A.clear();
    H.clear();
    scanf("%d", &n);
    T.resize(n);
    for(int i=0; i<n; i++) {
      //T[i] = new tribe();
      scanf("%d %d %d %d %d %d %d %d",
	    &T[i].d,&T[i].n,&T[i].w,
	    &T[i].e,&T[i].s,&T[i].del_d,
	    &T[i].del_p,&T[i].del_s);
    }
    for (int i=0; i<n; i++) {
      process_attacks(T[i]);
      //printf("%d\n", T[i].d);
    }
    int ans = 0;
    for (map<int, vector<attack> >::iterator it = A.begin(); it != A.end(); it++) {
      for (int i=0; i< it->second.size(); i++) {
	int stren = it->second[i].s;
	int w = it->second[i].w;
	int e = it->second[i].e;
	//printf("day : %d w: %d e: %d s: %d\n", it->first, it->second[i].w, it->second[i].e, it->second[i].s);
	for (int j=w; j<e; j++) {
	  if (H[j] < stren) {
	    ans++;
	    break;
	  }
	}
      }
      for (int i=0; i< it->second.size(); i++) {
	int stren = it->second[i].s;
	int w = it->second[i].w;
	int e = it->second[i].e;
	//printf("day : %d w: %d e: %d s: %d\n", it->first, it->second[i].w, it->second[i].e, it->second[i].s);
	for (int j=w; j<e; j++) {
	  H[j] = max(stren, H[j]);
	}
      }
    }
    printf("Case #%d: %d\n", x, ans);
  }
}