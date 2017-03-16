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
}

int sprpt[] = {-1, -1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10, -1, -1};
int maxpt[] = {0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10};

int solve(const int S, const int p, const vector<int>& t)
{
  int score = 0;
  int ss = S;
  REP(i, t.size()) {
    const int ti = t[i];
    if (maxpt[ti] >= p) {
      score++;
    } else if (ss > 0 && sprpt[ti] >= p) {
      score++;
      ss--;
    }
  }
  return score;
}


int solve2(const int S, const int p, const vector<int>& t,
	  int pos = 0, int score = 0, int maxscore = 0)
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
      if (S <= 0) continue;
      Sd = S - 1;
    }
    int scored = (d[i].atleast(p) ? score+1 : score);
    maxscore = max(maxscore, solve2(Sd, p, t, pos+1, scored, maxscore));
  }

  return maxscore;
}

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
