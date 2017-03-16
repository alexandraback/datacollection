#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int zipcode[50];
int n, m;
bool mp[50][50];

bool visited[50];
int stack[50], top;
bool _visited[50];
int _stack[50], _top;
bool _mp[50][50], _need[50];

bool add(int id, bool visited[50], int stack[50], int& top) {
  visited[id] = true;
  if (top == 0) {
    stack[top++] = id;
    return true;
  }
  for (int i = top - 1; i >= 0; i--) {
    if (mp[stack[i]][id]) {
      stack[i + 1] = id;
      top = i + 2;
      return true;
    }
  }
  return false;
}
bool test(int id) {
//  cout << "Test " << id << endl;
  if (top == 0) {
    return true;
  }
//  cout << "top = " << top << endl;
  _top = top;
  for (int i = 0; i < _top; i++) {
    _stack[i] = stack[i];
  }
  for (int i = 0; i < n; i++) {
    _visited[i] = visited[i];
  }
  if (add(id, _visited, _stack, _top) == false) {
    return false;
  }

  memset(_mp, false, sizeof(_mp));
  memset(_need, false ,sizeof(_need));
  for (int i = 0; i < n; i++) {
    if (_visited[i] == false) {
      _need[i] = true;
    }
  }
  for (int i = 0; i < _top; i++) {
    _need[_stack[i]] = true;
  }
  for (int i = 0; i < n; i++) {
    if (_need[i]) {
      for (int j = 0; j < n; j++) {
        if (_need[j]) {
          _mp[i][j] = mp[i][j];
        }
      }
    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (_mp[i][k] && _mp[k][j]) {
          _mp[i][j] = true;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (_need[i]) {
      for (int j = 0; j < n; j++) {
        if (_need[j]) {
          if (_mp[i][j] == false) {
            return false;
          }
        }
      }
    }
  }
  return true;
}

int main() {
  freopen("C-small-attempt0.in", "r", stdin);
  freopen("C-small-attempt0.out", "w", stdout);
  int totCas;
  scanf("%d", &totCas);
  for (int cas = 1; cas <= totCas; cas++) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%d", &zipcode[i]);
    }
    memset(mp, false, sizeof(mp));
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--;
      v--;

      mp[u][v] = mp[v][u] = true;
    }

    memset(visited, false, sizeof(visited));
    top = 0;

    printf("Case #%d: ", cas);
    for (int times = 0; times < n; times++) {
//      cout << "Time " << times << endl;
      int best = -1;
      for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
          if (test(i)) {
            if (best == -1 || zipcode[i] < zipcode[best]) {
              best = i;
            }
          }
        }
      }

      add(best, visited, stack, top);
      printf("%5d", zipcode[best]);
    }
    printf("\n");
  }
	return 0;
}

