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

int X, R, C;

void read(ifstream &fin) {
 fin >> X >> R >> C;
}

bool calc() {
 if(X >= 8) return false;
 int l = (X + 1) / 2;
 //cout << "Circle" << l << ' ' << R << ' ' << C << endl;
 if(l > R || l > C) return false;
 //cout << "L shape" << endl;
 if((R * C) % X != 0) return false;
 if(l == R || l == C) {
  int n = R;
  if(l == R) n = C;
  n -= l;
  if(X % 2 == 0)
   n--;

  int t = l * (l - 1) / 2;
  for(int i = 0; i <= t; ++i) {
   bool found = false;
   for(int j = 0; j <= n; ++j) {
    if((j * l + i) % X == 0) {
     found = true;
     break;
    }
   }
   if(!found) {
    return false;
   }
  }
 }

 return true;
}

void proc(ofstream &fout) {
 if(calc())
  fout << "GABRIEL" << endl;
 else
  fout << "RICHARD" << endl;
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
