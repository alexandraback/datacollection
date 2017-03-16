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
int _mx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int _my[] = {-1, -1, 0, 1, 1, 1, 0, -1};

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef istringstream ISS;
typedef ostringstream OSS;
typedef long long ll;

string a[4];

void read(ifstream &fin) {
 frr(i, 4)
  fin >> a[i];
}

bool check(int r, int c, int d, char p) {
 frr(i, 4) {
  if(r < 0 || c < 0 || r > 3 || c > 3) return false;
  if(a[r][c] != 'T' && a[r][c] != p) return false;
  r += _my[d];
  c += _mx[d];
 }

 return true;
}

void proc(ofstream &fout) {
 frr(i, 4) frr(j, 4) frr(d, 8)
  if(check(i, j, d, 'X')) {
   fout << "X won" << endl;
   return;
  } else if(check(i, j, d, 'O')) {
   fout << "O won" << endl;
   return;
  }

 frr(i, 4) frr(j, 4)
  if(a[i][j] == '.') {
   fout << "Game has not completed" << endl;
   return;
  }

 fout << "Draw" << endl;
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
