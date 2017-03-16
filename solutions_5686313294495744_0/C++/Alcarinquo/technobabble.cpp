#include <bits/stdc++.h>

using namespace std;

#define UNKNOWN 0
#define RIGHT 1
#define LEFT 2
#define FAKE 3
#define REAL 4

int status[1000];
map<string, int> idx1, idx2;
vector<int> count1, count2;
vector<pair<int, int> > pares;
bool appear1[1000], appear2[1000];

int main() {
  int T;
  int N;
  int i1, i2;
  string s1, s2;

  scanf("%d", &T);

  for(int caso = 1; caso <= T; caso++) {
    scanf("%d", &N);
    idx1.clear();
    idx2.clear();
    count1.clear();
    count2.clear();

    i1 = i2 = 0;
    pares.resize(N);
    memset(status, UNKNOWN, sizeof(status));
    memset(appear1, false, sizeof(appear1));
    memset(appear2, false, sizeof(appear2));

    for(int i = 0; i < N; i++) {
      cin >> s1 >> s2;

      if(idx1.find(s1) == idx1.end()) {
        idx1.insert(make_pair(s1, i1));
        count1.push_back(0);
        i1++;
      }
      if(idx2.find(s2) == idx2.end()) {
        idx2.insert(make_pair(s2, i2));
        count2.push_back(0);
        i2++;
      }

      pares[i] = make_pair(idx1[s1], idx2[s2]);
      count1[idx1[s1]]++;
      count2[idx2[s2]]++;
    }

    int stat = 0, fak = 0;

    for(int i = 0; i < N; i++) {
      if(count1[pares[i].first] == 1 || count2[pares[i].second] == 1) {
        appear1[pares[i].first] = true;
        appear2[pares[i].second] = true;
        status[i] = REAL;
        stat++;
      }
    }

    while(stat < N) {
      for(int i = 0; i < N; i++) {
        if(status[i] == UNKNOWN) {
          if(appear1[pares[i].first] && appear2[pares[i].second]) {
            status[i] = FAKE;
            fak++;
            stat++;
          }
        }
      }

      bool found = false;
      for(int i = 0; i < N; i++) {
        if(status[i] == UNKNOWN) {
          appear1[pares[i].first] = true;
          appear2[pares[i].second] = true;
          status[i] = REAL;
          stat++;
          found = true;
          break;
        }
      }

      if(!found) {
        for(int i = 0; i < N; i++) {
        if(status[i] == LEFT || status[i] == RIGHT) {
          appear1[pares[i].first] = true;
          appear2[pares[i].second] = true;
          status[i] = REAL;
          stat++;
          found = true;
          break;
        }
      }
      }

      for(int i = 0; i < N; i++) {
        if(status[i] == UNKNOWN || status[i] == LEFT || status[i] == RIGHT) {
          if(appear1[pares[i].first])
            status[i] |= LEFT;
          if(appear2[pares[i].second])
            status[i] |= RIGHT;
          if(status[i] == FAKE) {
            fak++;
            stat++;
          }
        }

      }
    }

    printf("Case #%d: %d\n", caso, fak);
  }

  return 0;
}
