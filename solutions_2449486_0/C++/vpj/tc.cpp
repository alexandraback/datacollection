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

const int inf = 1000;

int R, C;
int M;
int a[1000][1000];

void read(ifstream &fin) {
 fin >> R >> C;
 frr(r, R) frr(c, C)
  fin >> a[r][c];
}

void findMin() {
 M = inf;

 frr(r, R) frr(c, C) if(a[r][c] != -1)
  M = min(M, a[r][c]);
}

bool can(int r, int c, int dy, int dx, int n) {
 bool found = false;

 frr(i, n) {
  if(a[r][c] > M) return false;
  if(a[r][c] == M) found = true;
  r += dy;
  c += dx;
 }

 return found;
}

void cut(int r, int c, int dy, int dx, int n) {
 frr(i, n) {
  a[r][c] = -1;
  r += dy;
  c += dx;
 }
}

bool lawn() {
 frr(r, R)
  if(can(r, 0, 0, 1, C)) {
   cut(r, 0, 0, 1, C);
   return true;
  }

 frr(c, C)
  if(can(0, c, 1, 0, R)) {
   cut(0, c, 1, 0, R);
   return true;
  }

 return false;
}

void proc(ofstream &fout) {
 while(true) {
  findMin();
  if(M >= inf) {
   fout << "YES" << endl;
   return;
  }
  if(!lawn()) {
   break;
  }
 }

 fout << "NO" << endl;
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
