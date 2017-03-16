#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

typedef pair<int, int> PII;

const int incf[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int incc[] = {1, -1, 0, 0, 1, -1, 1, -1};

int R, C, M;
int v[50][50];
set<PII> pos;
bool fin;

void rec(int qtt) {
  if (fin) return;
  if (R*C - qtt < M) return;
  if (R*C - qtt == M) {
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        if (i == 0 and j == 0) cout << 'c';
        else if (v[i][j] != -1) cout << '.';
        else cout << '*';
      }
      cout << endl;
    }
    fin = true;
    return;
  }
  
  set<PII> aux = pos;
  for (set<PII>::iterator it = aux.begin(); it != aux.end() and not fin; ++it) {
    int f = it->first, c = it->second;
    vector<PII> news;
    for (int i = 0; i < 8; ++i) {
      int nf = f + incf[i], nc = c + incc[i];
      if (nf >= 0 and nf < R and nc >= 0 and nc < C and v[nf][nc] == -1) {
        v[nf][nc] = 1;
        news.push_back(PII(nf, nc));
      }
    }
    for (int i = 0; i < news.size(); ++i) pos.insert(news[i]);
    pos.erase(*it);
    rec(qtt + news.size());
    for (int i = 0; i < news.size(); ++i) {
      pos.erase(news[i]);
      v[news[i].first][news[i].second] = -1;
    }
    pos.insert(*it);
  }
}

void solve() {
  cin >> R >> C >> M;
  memset(v, -1, sizeof(v));
  if (M == R*C - 1) {
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        if (i == 0 and j == 0) cout << 'c';
        else cout << '*';
      }
      cout << endl;
    }
  }
  else {
    v[0][0] = 0;
    pos.clear();
    fin = false;
    if (R > 1) {
      v[1][0] = 1;
      pos.insert(PII(1, 0));
    }
    if (C > 1) {
      v[0][1] = 1;
      pos.insert(PII(0, 1));
    }
    if (R > 1 and C > 1) {
      v[1][1] = 1;
      pos.insert(PII(1, 1));
    }
    rec(1 + pos.size());
    if (not fin) cout << "Impossible" << endl;
  }
}

int main() {
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    cout << "Case #" << cas << ":" << endl;
    solve();
  }
}
