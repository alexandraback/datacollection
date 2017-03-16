#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

#define PRINT(x) cout << "DEBUG " << #x << " = " << x <<  endl;

#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fr(i, n) for(i = 0; i < (n); i++)
#define frr(i, n) for(int i = 0; i < (n); i++)
#define _cl(x) memset(x, 0, sizeof(x))
#define _rs(x) memset(x, -1, sizeof(x))

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef istringstream ISS;
typedef ostringstream OSS;
typedef long long ll;

const int inf = 1100100;

int N, M;
bool a[100][100];
int zip[100];
bool v[100];
bool reachable[100][100];
int P;
int path[100];
int IDX;

void read(ifstream &fin) {
 fin >> N >> M;
 frr(i, N) fin >> zip[i];
 int x, y;
 _cl(a);
 frr(i, M) {
  fin >> x >> y;
  --x, --y;
  a[x][y] = true;
  a[y][x] = true;
 }
}

void rec(int n) {
 reachable[IDX][n] = true;

 frr(i, N) if(a[n][i] && !v[i] && !reachable[IDX][i])
  rec(i);
}

void calcReachable(int n, int idx) {
 IDX = idx;
 _cl(reachable[idx]);

 rec(n);
}

void proc(ofstream &fout) {
 _cl(v);
 P = 0;
 int mn = inf;
 int n = -1;
 frr(i, N) {
  if(mn > zip[i]) {
   mn = zip[i];
   n = i;
  }
 }
 fout << mn;
 path[0] = n;
 v[n] = true;

 frr(_i, N - 1) {
  frr(i, P + 1) calcReachable(path[i], i);
  frr(i, N) frr(j, P)
   reachable[j + 1][i] |= reachable[j][i];
  for(int j = P; j >= 0; --j) {
   n = -1;
   mn = inf;
   int mfrom = -1;

   bool stuck = false;
   frr(i, N)
    if(!v[i] && reachable[j][i] && (j == 0 || !reachable[j - 1][i]))
     stuck = true;

   if(stuck) {
    frr(i, N) if(!v[i] && reachable[j][i]) {
     int from = -1;
     for(int k = P; k >= j; --k) {
      if(a[path[k]][i]) {
       from = k;
       break;
      }
     }
     if(from != -1 && mn > zip[i]) mn = zip[i], n = i, mfrom = from;
    }

    v[n] = true;
    P = mfrom + 1;
    path[P] = n;
    fout << mn;
    break;
   }
  }
 }

 fout << endl;
}

int main() {
 int i;
 int NT;

 ifstream fin("in");
 ofstream fout("out");
 string ln;

 getline(fin, ln);
 istringstream is(ln);
 is >> NT;

 fr(i, NT)
 {
  read(fin);
  fout << "Case #" << i + 1 << ": ";
  cout << "Case #" << i + 1 << endl;
  proc(fout);
 }

 return 0;
}
