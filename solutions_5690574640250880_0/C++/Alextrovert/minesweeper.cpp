#include <bitset>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

int T, R, C, M, G[10][10];

void print() {
  for (int r = 1; r <= R; r++) {
    for (int c = 1; c <= C; c++)
      cout << (char)(G[r][c] == 10 ? '*' : (G[r][c] ? G[r][c] + '0' : '.'));
    cout << "\n";
  }
  cout << "----" << endl;
}

const int dr[] = {-1,-1,-1, 0, 0, 1, 1, 1};
const int dc[] = {-1, 0, 1,-1, 1,-1, 0, 1};

int visit[15][15], filled;

void rec(int r, int c) {
  if (G[r][c] == 10 || visit[r][c] ||
      r < 1 || r > R || c < 1 || c > C) return;
  visit[r][c] = true;
  filled++;
  //cout << "(" << r << " " << c << ")\n";
  if (G[r][c] == 0)
    for (int d = 0; d < 8; d++)
      rec(r + dr[d], c + dc[d]);
}

pair<int, int> search() {
  for (int r = 1; r <= R; r++)
    for (int c = 1; c <= C; c++)
      if (G[r][c] == 0) {
        memset(visit, false, sizeof visit);
        filled = 0;
        rec(r, c);
        //cout << ">>" << filled << endl;
        if (filled == R*C - M)
          return make_pair(r, c);
      }
  return make_pair(-1, -1);
}

int main() {
  ifstream cin("C-small-attempt0.in");
  ofstream cout("C-small-attempt0.out");

  /*
  R = 5, C = 10;
  string str("10010001100000100000000001000000000000100000000000");
  bitset<50> bits(string(str.rbegin(), str.rend()));
  for (int r = 0; r < R; r++)
    for (int c = 0; c < C; c++)
      G[r+1][c+1] = (bits[r*C + c] ? 10 : 0);
  for (int r = 1; r <= R; r++)
    for (int c = 1; c <= C; c++) {
      if (G[r][c] == 10) continue;
      for (int d = 0; d < 8; d++)
        G[r][c] += (G[r + dr[d]][c + dc[d]] == 10);
    }

  print();
  filled = 0;
  rec(3, 3);
  cout << filled << endl;

  return 0;
  */
  cin >> T;
  for (int Case = 1; Case <= T; Case++) {
    cin >> R >> C >> M;
    int total = 1<<(R*C), found = 0;
    memset(G, 0, sizeof G);
    for (unsigned int i = 0; i < total; i++) {
      bitset<25> bits(i);
      if (bits.count() != M) continue;
      for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
          G[r+1][c+1] = (bits[r*C + c] ? 10 : 0);
      for (int r = 1; r <= R; r++)
        for (int c = 1; c <= C; c++) {
          if (G[r][c] == 10) continue;
          for (int d = 0; d < 8; d++)
            G[r][c] += (G[r + dr[d]][c + dc[d]] == 10);
        }
      pair<int, int> click = search();
      if (click.first != -1) {
        G[click.first][click.second] = 'c';
        found = 1;
        goto done;
      }
      //print();
    }
done:
    cout << "Case #" << Case << ":\n";
    if (found) {
      for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++)
          cout << (G[r][c] == 10 ? '*' :
            (G[r][c] == 'c' ? 'c' : '.'));
        cout << "\n";
      }
    } else {
      cout << "Impossible\n";
    }
  }
  
  return 0;
}