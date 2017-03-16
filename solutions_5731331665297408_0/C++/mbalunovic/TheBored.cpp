#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MaxN = 55;

int tot, N, M, id[MaxN], novi[MaxN], dad[MaxN];
string s[MaxN], sol;
vector <int> E[MaxN];
bool used[MaxN], bio[MaxN], on[MaxN][MaxN];

void dfs (int x) {
  bio[x] = true;
  ++tot;

  for (int i = 0; i < E[x].size(); ++i)
    if (!bio[E[x][i]] && !used[E[x][i]]) {
      //      printf("%s --> %s\n",s[x].c_str(),s[E[x][i]].c_str());
      dfs(E[x][i]);
    }
}

void walk (int x) {
  if (x == -1) return;
  /*  if (dad[x] != -1)
    printf("x = %s, ...dad = %s\n",s[x].c_str(),s[dad[x]].c_str());
  */
  for (int i = 0; i < E[x].size(); ++i)
    if (!used[E[x][i]] && !bio[E[x][i]]) {
      //  printf("... %s ---> %s\n",s[x].c_str(),s[E[x][i]].c_str());
      dfs(E[x][i]);
    }

  walk(dad[x]);
}

int WALK (int x) {
  tot = 0;
  walk(x);
  int ret = tot;
  for (int y = 0; y < N; ++y)
    if (used[y] && !bio[y])
      ++ret;
  return ret;
}

bool cmpf (int i, int j) {
  return s[i] < s[j];
}

void solve (int c) {
  memset(used, false, sizeof(used));
  memset(on, false, sizeof(on));

  scanf("%d %d",&N,&M);
  for (int i = 0; i < N; ++i) {
    cin >> s[i];
    id[i] = i;
    E[i].clear();
  }
  sort(id, id + N, cmpf);
  for (int i = 0; i < N; ++i)
    novi[id[i]] = i;
  sort(s, s + N);

  for (int i = 0; i < M; ++i) {
    int u, v;
    scanf("%d %d",&u,&v);
    --u;
    --v;
    u = novi[u];
    v = novi[v];
    E[u].push_back(v);
    E[v].push_back(u);
    on[u][v] = on[v][u] = true;
  }

  int curr = -1;
  memset(dad, -1, sizeof(dad));

  for (int x = 0; x < N; ++x) {
    memset(bio, false, sizeof(bio));
    tot = 0;
    dfs(x);
    if (tot == N) {
      sol = s[x];
      curr = x;
      used[x] = true;
      break;
    }
  }

  for (int iter = 1; iter < N; ++iter) {
    for (int x = 0; x < N; ++x) {
      if (used[x])
	continue;

      bool ok = false;

      int p = curr;
      do {
	if (on[p][x]) {
	  memset(bio, false, sizeof(bio));
	  dad[x] = p;
	  used[x] = true;
	  if (WALK(x) == N) {
	    ok = true;
	    break;
	  }
	  used[x] = false;
	}
	p = dad[p];
      } while (p != -1);

      if (ok) {
	curr = x;
	sol += s[x];
	//cout << sol << endl;
	break;
      }
    }
  }
  
  printf("Case #%d: %s\n",c,sol.c_str());  
}

int main (void) {
  int t;
  scanf("%d",&t);
  for (int c = 1; c <= t; ++c)
    solve(c);
  return 0;
}
