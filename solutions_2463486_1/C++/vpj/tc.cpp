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

ll A, B;
int a[1000];

void read(ifstream &fin) {
 fin >> A >> B;
}

inline bool ispalin(ll x) {
 int i = 0;

 for(i = 0; x > 0; ++i) {
  a[i] = (int)(x % 10);
  x /= 10;
 }
 int n = i - 1;
 for(int i = 0; i <= n; ++i)
  if(a[i] != a[n - i])
   return false;

 return true;
}

void proc(ofstream &fout) {
 ll res = 0;

 ll x = (ll)ceil(sqrt((double)A));
 ll y = (ll)floor(sqrt((double)B));

 for(ll i = x; i <= y; ++i) {
  if(ispalin(i) && ispalin(i * i)) {
//   cout << i << endl;
   res++;
  }
 }

 fout << res << endl;
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
