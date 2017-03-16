#include <algorithm>
#include <limits>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>

#define MOD_PRIME 1000000007
#define MAX_N 100
#define MAX_LENGTH 100
#define BUFFER_SIZE (MAX_N * (MAX_LENGTH + 1))
#define NUM_CHARACTERS 26

using namespace std;

char str[BUFFER_SIZE + 10];
char cars[MAX_N][MAX_LENGTH + 10];
char allcars[MAX_N * MAX_LENGTH + 10];
bool inside[NUM_CHARACTERS];
int singular[NUM_CHARACTERS];
vector<int> neighbours[NUM_CHARACTERS];
vector<int> rev_neighbours[NUM_CHARACTERS];
vector<int> bi_neighbours[NUM_CHARACTERS];
int parent[NUM_CHARACTERS];
bool visited[NUM_CHARACTERS];
int true_root;
int component[NUM_CHARACTERS];
int comp_size[NUM_CHARACTERS];
int num_components;
int fact[MAX_N + 1];

char *trim_line(char *str)
{
  return strtok(str, "\r\n");
}

bool tree_dfs(int root)
{
  visited[root] = 1;
  for (vector<int>::iterator it = neighbours[root].begin(); it != neighbours[root].end(); ++it) {
    int node = *it;
    if (visited[node]) {
      if (node == true_root) {
        return false;
      }
    } else {
      if (!tree_dfs(node)) {
        return false;
      }
    }
  }
  return true;
}

void dfs(int root)
{
  visited[root] = 1;
  component[root] = num_components;
  ++comp_size[num_components];
  for (vector<int>::iterator it = bi_neighbours[root].begin(); it != bi_neighbours[root].end(); ++it) {
    int node = *it;
    if (node != parent[root]) {
      if (!visited[node]) {
        parent[node] = root;
        dfs(node);
      }
    }
  }
}

int addmod(int x, int y)
{
  int sum = x + y;
  if (sum >= MOD_PRIME)
    sum -= MOD_PRIME;
  return sum;
}

int submod(int x, int y)
{
  int diff = x - y;
  if (diff < 0)
    diff += MOD_PRIME;
  return diff;
}

int mulmod(int x, int y)
{
  long long prod = x;
  prod = (prod * y) % MOD_PRIME;
  return (int) prod;
}

int powmod(int x, int e)
{
  long long result = 1;
  long long base = x;

  if (e > 0) {
    while (true) {
      if (e & 1) {
        result = (result * base) % MOD_PRIME;
      }
      e >>= 1;
      if (e <= 0)
        break;
      base = (base * base) % MOD_PRIME;
    }
  }

  return (int) result;
}

void build_fact()
{
  fact[0] = 1;
  for (int i = 0; i < MAX_N; i++)
    fact[i + 1] = mulmod(i + 1, fact[i]);
}

int solve_problem(int num_case)
{
  char *p;
  int n;
  bool possible = true;

  if (fgets(str, sizeof(str), stdin) == NULL)
    return 1;
  n = atoi(str);

  if (fgets(str, sizeof(str), stdin) == NULL)
    return 1;
  trim_line(str);
  p = strtok(str, " ");
  for (int i = 0; p != NULL; i++) {
    strcpy(cars[i], p);
    p = strtok(NULL, " ");
  }

#if 0
  for (int i = 0; i < n; i++)
    printf(" %zu", strlen(cars[i]));
  printf("\n");
#endif

  strcpy(allcars, "");
  for (int i = 0; i < n; i++) {
    strcat(allcars, cars[i]);
  }
  size_t total_length = strlen(allcars);

  fill(inside, inside + NUM_CHARACTERS, false);
  fill(singular, singular + NUM_CHARACTERS, 0);
  for (int i = 0; i < NUM_CHARACTERS; i++) {
    neighbours[i].clear();
    rev_neighbours[i].clear();
    bi_neighbours[i].clear();
  }
  fill(visited, visited + NUM_CHARACTERS, false);
  for (int i = 0; i < n; i++) {
    p = cars[i];
    size_t len = strlen(p);
    size_t j = 0;
    while (j + 1 < len && p[j] == p[j + 1]) {
      ++j;
    }
    size_t k = len - 1;
    while (k > 0 && p[k] == p[k - 1]) {
      --k;
    }
    int x = p[j] - 'a';
    int y = p[k] - 'a';
    if (x != y) {
      neighbours[x].push_back(y);
      rev_neighbours[y].push_back(x);
      bi_neighbours[x].push_back(y);
      bi_neighbours[y].push_back(x);
    } else {
      if (j < k) {
        possible = false;
        break;
      } else {
        ++singular[x];
      }
    }
    for (++j; j < k; j++) {
      inside[p[j] - 'a'] = true;
    }
  }

  for (int i = 0; i < NUM_CHARACTERS && possible; i++) {
    if (inside[i]) {
      char ch = 'a' + i;
      char *s = strchr(allcars, ch);
      char *t = allcars + total_length;
      while (s + 1 < t && *s == *(s + 1)) {
        ++s;
      }
      if (strchr(s + 1, ch) != NULL) {
        possible = false;
        break;
      }
    }
  }
  for (int i = 0; i < NUM_CHARACTERS && possible; i++) {
    if (neighbours[i].size() > 1 || rev_neighbours[i].size() > 1) {
      possible = false;
    }
  }
#if 0
  for (int i = 0; i < NUM_CHARACTERS; i++) {
    printf("i=%d:", i);
    for (size_t j = 0; j < neighbours[i].size(); j++) {
      printf(" %d", neighbours[i][j]);
    }
    printf("\n");
  }
#endif
  for (int i = 0; i < NUM_CHARACTERS && possible; i++) {
    if (!visited[i]) {
      true_root = i;
      if (!tree_dfs(i)) {
        possible = false;
      }
    }
  }

  if (possible) {
    int result = 1;
    fill(visited, visited + NUM_CHARACTERS, false);
    fill(parent, parent + NUM_CHARACTERS, -1);
    fill(component, component + NUM_CHARACTERS, -1);
    fill(comp_size, comp_size + NUM_CHARACTERS, 0);
    num_components = 0;
    for (int i = 0; i < NUM_CHARACTERS; i++) {
      if (!visited[i]) {
        dfs(i);
        if (comp_size[num_components] == 1 && singular[i] == 0) {
          component[i] = -1;
          comp_size[num_components] = 0;
        } else {
          ++num_components;
        }
      }
    }
    for (int i = 0; i < NUM_CHARACTERS; i++) {
      result = mulmod(result, fact[singular[i]]);
    }
    result = mulmod(result, fact[num_components]);
    printf("Case #%d: %d\n", num_case, result);
  } else {
    printf("Case #%d: 0\n", num_case);
  }

  return 0;
}

int main()
{
  int num_tests;

  build_fact();

  if (fgets(str, sizeof(str), stdin) == NULL)
    return 1;
  num_tests = atoi(str);

  for (int i = 0; i < num_tests; i++)
    solve_problem(i + 1);

  return 0;
}
