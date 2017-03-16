#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

#define REP(i,n) FOR(i,0,n)
#define FOR(i,s,n) for (int i = (int)(s); i < (int)(n); ++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

struct triplet {
  int v1, v2, v3;
  //triplet() : v1(-1), v2(-1), v3(-1) { }
  triplet(int a, int b, int c) : v1(a), v2(b), v3(c) { }
  bool atleast(int p) const {
    return (v1 >= p || v2 >= p || v3 >= p);
  }
  bool suprising() const {
    return (v3 - v1 > 1);
  }
};

map<int, vector<triplet> > dic;

void init()
{
  dic.clear();
  // i <= j <= k
  for (int i = 0; i < 11; ++i) {
    for (int j = i; j < 11; ++j) {
      for (int k = j; k < 11; ++k) {
	if (k - i > 2) break;
	int sm = i + j + k;
	if (dic.find(sm) == dic.end()) dic[sm] = vector<triplet>();
	dic[sm].push_back(triplet(i, j, k));
      }
    }
  }

  // REP(i, 31) {
  //   cout << i << ":" << endl;
  //   if (dic.find(i) == dic.end()) continue;
    
  //   const vector<triplet>& d = dic[i];
  //   REP(j, d.size()) {
  //     cout << " " << d[j].v1 << " " << d[j].v2 << " " << d[j].v3 << endl;
  //   }
  // }
}

#define SPR(i) (spr[d[i].a][d[i].b][d[i].c])
int solve(const int S, const int p, const vector<int>& t, int pos = 0, int score = 0, int maxscore = 0)
{
  if (pos >= (int)t.size()) {
    if (S == 0)
      return score;
    else
      return maxscore;
  }

  const vector<triplet>& d = dic[t[pos]];
  REP(i, d.size()) {
    int Sd = S;
    if (d[i].suprising()) {
      if (S == 0) continue;
      Sd = S - 1;
    }
    int scored = (d[i].atleast(p) ? score+1 : score);
    maxscore = max(maxscore, solve(Sd, p, t, pos+1, scored, maxscore));
  }

  return maxscore;
}
#undef SPR

int main()
{
  int T;
  cin >> T;
  init();
  for (int cs = 1; cs <= T; ++cs) {
    int N, S, p;
    cin >> N >> S >> p;
    vector<int> t(N);
    for (int i = 0; i < N; ++i) cin >> t[i];
    
    cout << "Case #" << cs << ": " << solve(S, p, t) << endl;
  }
  
  return 0;
}
