#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool tab[2000];
bool attract[2000];
int bscore[2000];
vector<int> bff;
vector<vector<int> > rbff;
int N;

int circle_sc(int s, int i) {
  if (s == i) return 1;
  if (tab[i]) return -1;
  tab[i] = true;
  int sc = circle_sc(s, bff[i]);
  tab[i] = false;
  if (sc >= 0) return sc + 1;
  return -1;
}

void print_circle_sc(int s, int i) {
  if (s == i) return;
  printf("%d ", i+1);
  print_circle_sc(s, bff[i]);
}

int best_circle() {
  int best = 0;
  int id = 0;
  for (int  i = 0; i < N; i++) {
    int sc = circle_sc(i, bff[i]);
    if (sc > best) { best = sc; id = i; }
  }
  return best;
}

int get_vec(int i, vector<int>& vec) {
  for (int j = 0; j < rbff[i].size(); j++) {
    if (bff[i] == rbff[i][j]) continue;
    if (bscore[i] == 1 + bscore[rbff[i][j]]) get_vec(rbff[i][j], vec);
  }
  vec.push_back(i + 1);  
}
int as(int i) {
  bscore[i] = 1;
  for (int j = 0; j < rbff[i].size(); j++) {
    if (bff[i] == rbff[i][j]) continue;
    bscore[i] = max(bscore[i], 1 + as(rbff[i][j]));
  }
  return bscore[i];
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%d", &N);
    bff.clear();
    rbff = vector<vector<int> >(N);
    for (int i = 0; i < N; i++) {
      int b; scanf("%d", &b);
      bff.push_back(b - 1);
      rbff[b - 1].push_back(i);
    }
    for (int i = 0; i < N; i++) {
      bscore[i] = 0;
      attract[i] = bff[bff[i]] == i;
    }
    int ascore = 0;
    for (int i = 0; i < N; i++) {
      if (attract[i]) {
        if (i < bff[i]) {
		ascore += as(bff[i]);
		ascore += as(i);
        } 
      }
    }
    int score = best_circle();
    cout << "Case #" << t << ": " << std::max(score, ascore);
    printf("\n");
  }
  return 0;
}
