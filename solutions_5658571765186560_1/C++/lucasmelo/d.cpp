#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define all(a) (a).begin(), (a).end()
#define fi first
#define inf 0x3f3f3f3f
#define pb(x) push_back(x)
#define se second

int x, r, c;

#define MAXPOL 6

typedef pair<int,int> pii;
typedef vector<pii> vpii;

void normalize(vpii &pieces) {
  int mnfi=inf, mnse=inf;
  for(pii &x : pieces) {
    mnfi = min(mnfi, x.fi);
    mnse = min(mnse, x.se);
  }
  for(pii &x : pieces) {
    x.fi -= mnfi;
    x.se -= mnse;
  }
  sort(all(pieces));
}

void rot(vpii &pieces ) {
  vpii npieces;
  for(pii x : pieces) {
    npieces.pb(pii(-x.se, x.fi));
  }
  pieces = npieces;
  normalize(pieces);
}

void ref(vpii &pieces ) {
  vpii npieces;
  for(pii x : pieces) {
    npieces.pb(pii(-x.fi, x.se));
  }
  pieces = npieces;
  normalize(pieces);
}

void really_normalize(vpii &pieces) {
  set< vpii > s;
  for(int i=0; i<4; i++) {
    rot(pieces);
    s.insert(pieces);
  }
  ref(pieces);
  for(int i=0; i<4; i++) {
    rot(pieces);
    s.insert(pieces);
  }

  pieces = *s.begin();
}

set<vpii> poly[MAXPOL+1];

int dirx[] = {-1,+1, 0, 0};
int diry[] = { 0, 0,-1,+1};
int ndir = sizeof(dirx)/sizeof(int);

void pre() {

  poly[1].insert(vpii({pii(0,0)}));
  for(int i=2; i<=MAXPOL; i++) {
    for(const vpii &p : poly[i-1]) {
      for(pii x : p) {
        for(int j=0; j<ndir; j++) {
          pii y = pii(x.fi + dirx[j], x.se + diry[j]);
          if (find(all(p),y) == p.end()) {
            vpii np(all(p));
            np.pb(y);
            really_normalize(np);
            poly[i].insert(np);
          }
        }
      }
    }
  }

}

bool field[21][21];

int dfs(int i, int j, int r, int c) {
  field[i][j] = true;
  int ans = 1;
  for(int k=0; k<ndir; k++) {
    int ni = dirx[k] + i;
    int nj = diry[k] + j;
    if (ni >=0 && ni < r &&
        nj >=0 && nj < c &&
        !field[ni][nj]) {
      ans += dfs(ni,nj,r,c);
    }
  }
  return ans;
}

bool test() {
  for(const vpii &p : poly[x]) {
    int mxfi=0, mxse=0;

    for(pii x : p) {
      mxfi = max(mxfi, x.fi);
      mxse = max(mxse, x.se);
    }

    bool good = true;
    for(pii diam : { pii(r,c), pii(c,r) }) {
      int r = diam.fi;
      int c = diam.se;
      for(int di=0; di<r; di++) {
        if (mxfi + di >= r) continue;
        for(int dj=0; dj<c; dj++) {
          if(mxse + dj >= c) continue;

          memset(field, false, sizeof(field));
          for(pii x: p) {
            field[x.fi + di][x.se + dj] = true;
          }
          bool ok = true;
          for(int i=0; i<r && ok; i++){
            for(int j=0; j<c && ok; j++) {
              if (!field[i][j]) {
                if (dfs(i,j,diam.fi,diam.se) % x != 0) ok = false;
              }
            }
          }
          if (ok) good = false;
        }
      }
    }
    if (good) return true;
  }
  return false;
}


int main() {
  int t; cin >> t;
  pre();

  for(int cn=1; cn<=t; cn++) {
    bool richard;
    cin >> x >> r >> c;

    if ((r*c)%x != 0 || (x>r&&x>c) ) {
      richard = true;
    } else {
      if (x <= 2 || x > MAXPOL) {
        richard = false;
      } else {
        richard = test();
      }
    }

    printf("Case #%d: %s\n", cn, richard?"RICHARD":"GABRIEL");
  }
  return 0;
}
