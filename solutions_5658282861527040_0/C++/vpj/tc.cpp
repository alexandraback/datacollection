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

ll A, B, K;

void read(ifstream &fin) {
 fin >> A >> B >> K;
}

ll rec(ll a, ll b, int l) {
 ll k = a & b;
 if(k >= K || a >= A || b >= B) return 0;
 ll mask = (1LL << (l + 1)) - 1;
 ll L = 1LL << l;

 if(l < 0) {
  if(k < K) return 1;
  else return 0;
 }

 ll _k = K - (K & mask);
 ll _a = A - (A & mask);
 ll _b = B - (B & mask);

 if(k == _k) {
  return
    rec(a, b, l - 1) +
    rec(a, b + L, l - 1) +
    rec(a + L, b, l - 1) +
    rec(a + L, b + L, l - 1);
 }

 if(a < _a) {
  if(b < _b) {
   return (1LL << (2 * (l + 1)));
  }
  return 2 * rec(a, b, l - 1) + 2 * rec(a, b + L, l - 1);
 }
 if(b < _b) {
  return 2 * rec(a, b, l - 1) + 2 * rec(a + L, b, l - 1);
 }

 return
   rec(a, b, l - 1) +
   rec(a, b + L, l - 1) +
   rec(a + L, b, l - 1) +
   rec(a + L, b + L, l - 1);
}

void proc(ofstream &fout) {
 fout << rec(0, 0, 30) << endl;
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
