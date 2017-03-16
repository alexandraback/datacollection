#include <iostream>
#include <vector>
#include <set>
using namespace std;

int R, N, M, K;
int a[20];
vector<vector<int> > c;
vector<set<int> > s;
vector<int> vote;

void add_combination() {
  vector<int> v;
  for (int i = 0; i < N; i++)
    v.push_back(a[i]);
  c.push_back(v);
  s.push_back(set<int>());
}

void generate_combinations(int i = 0) {
  if (i == N) {
    add_combination();
  }
  else {
    for (a[i] = (i==0?2:a[i-1]); a[i] <= M; a[i]++)
      generate_combinations(i+1);
  }
}

void generate_products(int i, int j = 0, int p = 1) {
  if (j == N) {
    s[i].insert(p);
  }
  else {
    generate_products(i, j+1, p);
    generate_products(i, j+1, p*c[i][j]);
  }
}

void generate_products() {
  for (int i = 0; i < c.size(); i++) {
    generate_products(i);
  }
}

void print_combinations() {
  for (int i = 0; i < c.size(); i++) {
    for (int j = 0; j < N; j++)
      cout << c[i][j] << " ";
    for (set<int>::const_iterator si = s[i].begin(); si != s[i].end(); ++si)
      cout << *si << " ";
    cout << endl;
  }
}

int main() {
  int T; cin >> T;
  cin >> R >> N >> M >> K;
  generate_combinations();
  generate_products();
  cout << "Case #1:" << endl;
  for (int r = 1; r <= R; r++) {
    vote = vector<int>(c.size(), 0);
    for (int k = 0; k < K; k++) {
      int p; cin >> p;
      for (int i = 0; i < c.size(); i++)
        if (s[i].find(p) != s[i].end())
          vote[i]++;
    }
    int mi = -1;
    for (int i = 0; i < c.size(); i++)
      if (mi == -1 || vote[i] > vote[mi])
        mi = i;
    for (int j = 0; j < N; j++)
      cout << c[mi][j];
    cout << endl;
  }
  return 0;
}

