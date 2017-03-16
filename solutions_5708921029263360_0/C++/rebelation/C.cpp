#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <cmath>
#include <algorithm>

#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair< int, pair<int, int> > triplet;

triplet mt(int a, int b, int c){
  return make_pair(a, make_pair(b, c));
}

bool great(triplet& a, triplet& b){
  if(a.first != b.first)
    return a.first < b.first;
  if(a.second.first != b.second.first)
    return a.second.first < b.second.first;
  return a.second.second < b.second.second;
}

int J, P, S, K;
vector<triplet> best;

void dfs(vector<triplet>& cur, map<triplet, int>& freq){
  triplet last = cur.back();
  int j = last.first, p = last.second.first, s = last.second.second;
  bool f = false;
  for(int a = 1; a <= J; a++)
    for(int b = 1; b <= P; b++){
      triplet ab = mt(a, b, 0);
      if(freq[ab] >= K)
        continue;
      for(int c = 1; c <= S; c++){
        triplet ac = mt(a, 0, c);
        triplet abc = mt(a, b, c);
        if(!great(last, abc))
          continue;
        if(freq[ac] >= K)
          continue;
        triplet bc = mt(0, b, c);
        if(freq[bc] >= K)
          continue;
        if(freq[abc] > 0)
          continue;
        f = true;
        cur.push_back(abc);
        freq[abc]++;
        freq[ab]++; freq[ac]++; freq[bc]++;
        dfs(cur, freq);
        cur.pop_back();
        freq[abc] = 0;
        freq[ab]--; freq[ac]--; freq[bc]--;
      }
    }
  if(!f && cur.size() > best.size())best = cur;
}


int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  for(int o = 1; o <= T; o++){
    printf("Case #%d: ", o);
    cin >> J >> P >> S >> K;
    int mx = max(J, max(P, S));
    if(mx <= K){
      printf("%d\n", J * P * S);
      for(int i = 1; i <= J; i++)
        for(int j = 1; j <= P; j++)
          for(int k = 1; k <= S; k++)
            printf("%d %d %d\n", i, j, k);
      continue;
    }
    best.clear();
    triplet t = mt(1, 1, 1);
    vector<triplet> cur;
    cur.push_back(t);
    map<triplet, int> freq;
    freq[t] = 1;
    freq[mt(1, 1, 0)]++; freq[mt(1, 0, 1)]++; freq[mt(0, 1, 1)]++;
    dfs(cur, freq);
    printf("%d\n", (int)best.size());
    for(int i = 0; i < best.size(); i++)
      printf("%d %d %d\n", best[i].first, best[i].second.first, best[i].second.second);
    fflush(stdout);
  }

  return 0;
}
