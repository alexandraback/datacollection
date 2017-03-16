#include <cstdio>
#include <algorithm>
#include <set>

std::pair<int, int> data[10000];

struct cmp1 {
  inline bool operator()(const int &a, const int &b) {
    return data[a].first < data[b].first || (data[a].first == data[b].first && a < b);
  }
};

struct cmp2 {
  inline bool operator()(const int &a, const int &b) {
    return data[a].second < data[b].second || (data[a].second == data[b].second && a < b);
  }
};


struct Rcmp2 {
  inline bool operator()(const int &a, const int &b) {
    return data[a].second > data[b].second || (data[a].second == data[b].second && a < b);
  }
};

std::set<int, Rcmp2> fst;
std::set<int> pure_snd;
std::set<int> snd; 

std::set<int, cmp1> fst_e;
std::set<int, cmp2> pure_snd_e; 
std::set<int, cmp2> snd_e; 

int done[10000];

int main() {
  int T;
  scanf("%d", &T);
  for(int tc = 1; tc <= T; ++tc) {
    int N, stars = 0, result = 0;
    scanf("%d", &N);

    for(int i = 0; i < N; ++i) {
      scanf("%d%d", &data[i].first, &data[i].second);
      if(data[i].first <= stars)
        fst.insert(i);
      else
        fst_e.insert(i);

      if(data[i].second <= stars)
        pure_snd.insert(i);
      else
        pure_snd_e.insert(i);

      done[i] = 0;
    }

    while(!fst.empty() || !snd.empty() || !pure_snd.empty()) {
      int cn;

      if(!pure_snd.empty()) {
        cn = *pure_snd.begin(), stars += 2;
        pure_snd.erase(cn);

        done[cn] = 2;

        fst.erase(cn);
      }
      else if(snd.empty()) {
        cn = *fst.begin(), stars++;
        fst.erase(cn);

        pure_snd_e.erase(cn);
        snd_e.insert(cn);

        done[cn] = 1;
      }
      else {
        cn = *snd.begin(), stars++;
        snd.erase(cn);

        done[cn] = 2;
      }

      result++;

      while(!fst_e.empty() && data[*fst_e.begin()].first <= stars) {
        fst.insert(*fst_e.begin());
        fst_e.erase(fst_e.begin());
      }

      while(!snd_e.empty() && data[*snd_e.begin()].second <= stars) {
        snd.insert(*snd_e.begin());
        snd_e.erase(snd_e.begin());
      }

      while(!pure_snd_e.empty() && data[*pure_snd_e.begin()].second <= stars) {
        pure_snd.insert(*pure_snd_e.begin());
        pure_snd_e.erase(pure_snd_e.begin());
      }

    }

    bool ok = stars == 2 * N;

    for(int i = 0; i < N; ++i)
      ok &= (done[i] == 2);

    if(ok)
      printf("Case #%d: %d\n", tc, result);
    else
      printf("Case #%d: Too Bad\n", tc);

    fst.clear();
    snd.clear();
    pure_snd.clear();
    fst_e.clear();
    snd_e.clear();
    pure_snd_e.clear();
  }
  return 0;
}
