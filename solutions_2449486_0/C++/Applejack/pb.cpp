#include <iostream>
#include <algorithm>
using namespace std;

int Z, N, M;
int p[110][110];

void read();
void soups_on(int);
bool mow(int, int);

inline int get_min() {
  int ret = 110;

  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j)
      if (p[i][j] > 0)
        ret = min(ret, p[i][j]);

  return ret;
}

int main() {
  cin >> Z;
  for (int zi = 1; zi <= Z; ++zi)
    read(), soups_on(zi);

  return 0;
}

void read() {
  cin >> N >> M;
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j)
      cin >> p[i][j];
}

void soups_on(int zi) {
  int mv;
  bool is_stock = false;

  while (!is_stock && (mv = get_min()) < 110) {
    bool is_success = false;

    for (int i = 1; i <= N; ++i)
      for (int j = 1; j <= M; ++j)
        if (p[i][j] == mv && mow(i, j))
          is_success = true;

    if (!is_success)
      is_stock = true;
  }

  cout << "Case #" << zi << ": " << (is_stock ? "NO\n" : "YES\n");
}

bool mow(int qi, int qj) {
  bool is_valid;
  int v = p[qi][qj];

  is_valid = true;
  for (int j = 1; j <= M && is_valid; ++j)
    if (p[qi][j] > v)
      is_valid = false;

  if (is_valid) {
    for (int j = 1; j <= M; ++j)
      p[qi][j] = 0;
    return true;
  }

  is_valid = true;
  for (int i = 1; i <= N && is_valid; ++i)
    if (p[i][qj] > v)
      is_valid = false;

  if (is_valid) {
    for (int i = 1; i <= N; ++i)
      p[i][qj] = 0;
    return true;
  }

  return false;
}
