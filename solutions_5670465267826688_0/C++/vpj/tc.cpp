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

int dp[3][11000][12];
int a[11000];
int L, X;
int mul_letter[4][4] = {
 {0, 1, 2, 3},
 {1, 0, 3, 2},
 {2, 3, 0, 1},
 {3, 2, 1, 0}};
int mul_negative[4][4] = {
 {0, 0, 0, 0},
 {0, 1, 0, 1},
 {0, 1, 1, 0},
 {0, 0, 1, 1}};

void read(ifstream &fin) {
 string s;
 fin >> L >> X;
 fin >> s;
 frr(i, L) {
  if(s[i] == 'i') a[i] = 1;
  if(s[i] == 'j') a[i] = 2;
  if(s[i] == 'k') a[i] = 3;
 }
}

bool calc(int n, int pos, int x) {
 if(n == 3) {
  if(pos == 0 && (x + 1) % 4 == 0)
   return true;
  else
   return false;
 }

 int &r = dp[n][pos][x];
 if(r != -1) return r;
 r = 0;

 int letter = 0, negative = 0;
 for(int i = pos; i < L; ++i) {
  negative ^= mul_negative[letter][a[i]];
  letter = mul_letter[letter][a[i]];
  if(letter == n + 1 && negative == 0) {
   r = calc(n + 1, (i + 1) % L, x - (i + 1) / L);
   if(r) return r;
  }
 }

 x--;
 for(int j = 0; j < 4; ++j) {
  if(x < 0) return r;
  for(int i = 0; i < L; ++i) {
   negative ^= mul_negative[letter][a[i]];
   letter = mul_letter[letter][a[i]];
   if(letter == n + 1 && negative == 0) {
    r = calc(n + 1, (i + 1) % L, x - (i + 1) / L);
    if(r) return r;
   }
  }
  x--;
 }

 return r;
}

void proc(ofstream &fout) {
 memset(dp, -1, sizeof(dp));
 bool ans = calc(0, 0, X - 1);
 if(ans)
  fout << "YES" << endl;
 else
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
