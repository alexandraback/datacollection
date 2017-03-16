#define TASKNAME "text"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cassert>
#include <functional>
#include <iomanip>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
 
#define EPS 1e-9
#define INF int(1e9)
#define INFLONG (long long)(1e18)
#define sqr(a) ((a) * (a))
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define abs(a) (((a) < 0) ? -(a) : (a))
#define sz(a) (int)a.size()
#define fst first
#define snd second
#define y1 osrughosduvgarligybakrybrogvba
#define y0 aosfigdalrowgyalsouvgrlvygalri                               
#define mp make_pair
#define pb push_back
#define next dlkjdslfkdj
#define prev dsdflksdfjl
#define hash lkdfjldskfj
#define pi 3.1415926535897932384626433832795
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;
typedef vector <ll> vll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef vector <pii> vpii;

vector<int> f;
vector<int> ts;
vector<vector<int>> graph;
vector<bool> was;

void topsort(int v) {
    was[v] = true;
    for (int u : graph[v]) {
        if (!was[u]) {
            topsort(u);
        }
    }
    ts.push_back(v);
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  /* Precalc */

  int tests_count;
  scanf("%d\n", &tests_count);
  for (int test_number = 1; test_number <= tests_count; ++test_number)
  {
    printf("Case #%d: ", test_number);
    cerr<<test_number;
    /* Clear all! */
    
    /* Solution */
    int n;
    cin >> n;
    f.resize(n);
    graph.resize(n);
    for (int i = 0; i < n; i++) graph[i].clear();
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        f[i]--;
    }
    vector<int> p(n);
    int ans = 0;
    for (int i = 0; i < n; i++) p[i] = i;
    do {
        for (int i = 0; i < n; i++) {
            bool ok = 1;
            for (int j = 0; j <= i; j++) {
                int ne = (j == i ? 0 : j + 1);
                int pr = (j == 0 ? i : j - 1);
                if (f[p[j]] != p[ne] && f[p[j]] != p[pr]) {
                    ok = 0;
                }
            }
            if (ok) {
                ans = max(ans, i + 1);
            }
        }
    } while (next_permutation(all(p)));
    cout << ans <<endl;
  }
  return 0;
}

