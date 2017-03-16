#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct UF {
  vector<int> p;
  UF(){}
  UF(int n):p(n,-1){}
  int add(){p.push_back(-1); return p.size()-1;}
  int rt(int x){return p[x]<0?x:(p[x]=rt(p[x]));}
  bool eq(int x,int y){return rt(x)==rt(y);}
  void cat(int x,int y) {
    x=rt(x),y=rt(y);
    if(x==y) return;
    if(p[x]<p[y]) swap(x,y);
    p[y]+=p[x];
    p[x]=y;
  }
};

struct Event {
  int num;
  int den;
  int type;// 1:in 0:out
  int a,b;
  Event(){}
  Event(int num,int den,int type,int a,int b):num(num),den(den),type(type),a(a),b(b) {
    if(den<0) num*=-1,den*=-1;
  }
  bool operator<(const Event& o) const {
    if(num*o.den != o.num*den) return num*o.den < o.num*den;
    return type < o.type;
  }
};

int main() {
  int tc; scanf("%d", &tc);
  for(int tci = 0; tci < tc; tci++) {
    int n; scanf("%d", &n);
    static char c[50];
    static int s[50],p[50];
    for(int i = 0; i < n; i++) {
      scanf(" %c%d%d", c+i, s+i, p+i);
    }
    vector<Event> evts;
    vector<vector<int> > mat(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < i; j++) {
        if(s[i]==s[j]) {
          if(abs(p[i]-p[j])<5) mat[i][j]=1;
        } else {
          if((p[i]-p[j]-5)*(s[i]-s[j]) <= 0) {
            evts.push_back(Event(abs(p[i]-p[j])-5, abs(s[i]-s[j]), 1, i, j));
          } else mat[i][j] = mat[j][i] = 1;
          if((p[i]-p[j]+5)*(s[i]-s[j]) <= 0) {
            evts.push_back(Event(abs(p[i]-p[j])+5, abs(s[i]-s[j]), 0, i, j));
          } else mat[i][j] = mat[j][i] = 0;
        }
      }
    }
    sort(evts.begin(), evts.end());
    UF uf;
    vector<pair<int,int> > states(n);
    pair<int,int> init_state = make_pair(uf.add(), uf.add());
    for(int i = 0; i < n; i++) {
      states[i] = make_pair(uf.add(), uf.add());
      if(c[i]=='L') {
        uf.cat(states[i].first, init_state.first);
        uf.cat(states[i].second, init_state.second);
      } else {
        uf.cat(states[i].first, init_state.second);
        uf.cat(states[i].second, init_state.first);
      }
    }
    for(int i = -1; ; i++) {
      if(i >= (int)evts.size()) {
        printf("Case #%d: Possible\n", tci+1);
        break;
      }
      double tim = 0;
      if(i >= 0) {
        Event evt = evts[i];
        fprintf(stderr, "... evt[%d]: (%d/%d), %d, (%d,%d)\n", i, evt.num, evt.den, evt.type, evt.a, evt.b);
        if(evt.type == 0) {
          mat[evt.a][evt.b] = mat[evt.b][evt.a] = 0;
        } else {
          mat[evt.a][evt.b] = mat[evt.b][evt.a] = 1;
        }
        tim = (double)evt.num/evt.den;
      }
      for(int j = 0; j < n; j++) {
        int cnt = 0;
        for(int k = 0; k < n; k++) if(mat[j][k]) cnt++;
        if(cnt==0) states[j] = make_pair(uf.add(), uf.add());
      }
      for(int j = 0; j < n; j++) {
        for(int k = 0; k < j; k++) {
          if(mat[j][k]) {
            uf.cat(states[j].first, states[k].second);
            uf.cat(states[j].second, states[k].first);
          }
        }
      }
      bool succeeded = true;
      for(int j = 0; j < n; j++) {
        if(uf.eq(states[j].first,states[j].second)) succeeded = false;
      }
      if(!succeeded) {
        printf("Case #%d: %.6f\n", tci+1, tim);
        break;
      }
    }
  }
  return 0;
}
