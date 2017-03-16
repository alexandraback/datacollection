#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < int(b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define D(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
  printf("Case #%d: ", tc);
  int J, P, S, K;
  scanf("%d%d%d%d", &J, &P, &S, &K);

  int ans = J * P * min(S, K);

  vector<vector<int>> jp(J, vector<int>(P));
  vector<vector<int>> js(J, vector<int>(S));
  vector<vector<int>> ps(P, vector<int>(S));
  vector<vector<vector<int>>> jps(J, ps);
  printf("%d\n", ans);
  for (int i = 0; i < ans; ++i) {
    int j = i / (P * min(S, K));
    int p = i % P;
    int s = (i % P + i / P) % S;
    assert(++jp[j][p] <= K);
    assert(++js[j][s] <= K);
    assert(++ps[p][s] <= K);
    assert(++jps[j][p][s] <= 1);
    printf("%d %d %d\n", j+1, p+1, s+1);
  }
  return;


  for (int i = J * P * S; i >= 0; --i) {

    vector<vector<int>> whichJ(P);
    vector<vector<int>> whichS(P);
    
    int atp = 0;
    rep(j,0,J) {
      rep(it,0,i/J + (j < (i % J))) {
        whichJ[atp].push_back(j);
        jp[j][atp]++;
        atp = (atp + 1) % P;
      }
    }

    int ats = 0;
    rep(j,0,P) {
      rep(it,0,i/P + (j < (i % P))) {
        int theJ = whichJ[j][it];
        int ss = ats;
        while (ps[j][ats] == K || js[whichJ[j][it]][ats] == K || jps[theJ][j][ats]) {
          ats = (ats + 1) % S;
          if (ats == ss) goto nx;
        }
        jps[theJ][j][ats]++;
        whichS[j].push_back(ats);
        ps[j][ats]++;
        js[whichJ[j][it]][ats]++;
      }
    }

    rep(j,0,P) {
      assert(whichJ[j].size() == whichS[j].size());
    }

    rep(j,0,J)
      rep(p,0,P)
        rep(s,0,S) {
          if (jp[j][p] > K || js[j][s] > K || ps[p][s] > K) {
            goto nx;
          }
          assert(jp[j][p] == K || js[j][s] == K || ps[p][s] == K || i == J * P * S);
        }

    printf("%d\n", i);
    rep(j,0,P) {
      rep(k,0,sz(whichJ[j])) {
        printf("%d %d %d\n", whichJ[j][k] + 1, j + 1, whichS[j][k] + 1);
      }
    }
    break;

nx:;
  }

}

int main() {
  int N;
  scanf("%d", &N);
  rep(i,1,N+1) solve(i);
}
