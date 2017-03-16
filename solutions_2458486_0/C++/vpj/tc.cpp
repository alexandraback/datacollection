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

int N, K;
int treasure[1000][1000];
int have[1000];
int KEY[1000];
int tkeys[1000];
int ntemp[1000];
int temp[1000][1000];
map<int, int> kmap;

bool v[1 << 22];
bool can[1 << 22];
int next[1 << 22];

void read(ifstream &fin) {
 int nk;

 fin >> nk >> N;
 K = 0;
 kmap.clear();
 _cl(treasure);
 _cl(have);

 frr(i, nk)
  fin >> tkeys[i];

 frr(i, N) {
  int kt;
  fin >> kt;
  if(kmap.count(kt) == 0)
   kmap[kt] = K++;
  KEY[i] = kmap[kt];

  fin >> ntemp[i];
  frr(j, ntemp[i])
   fin >> temp[i][j];
 }

 frr(i, nk) {
  if(kmap.count(tkeys[i]))
   have[kmap[tkeys[i]]]++;
 }

 frr(i, N) {
  frr(j, ntemp[i]) {
   if(kmap.count(temp[i][j]))
    treasure[i][kmap[temp[i][j]]]++;
  }
 }
}

bool rec(vector<int> keys, int m) {
 if(v[m]) return can[m];
 v[m] = true;
 can[m] = false;

 frr(i, N) if((m & (1 << i)) == 0)
  if(keys[KEY[i]] > 0) {
   keys[KEY[i]]--;
   frr(j, K)
    keys[j] += treasure[i][j];
   if(rec(keys, m | (1 << i))) {
    can[m] = true;
    next[m] = i;
    return true;
   }
   keys[KEY[i]]++;
   frr(j, K)
    keys[j] -= treasure[i][j];
  }

 return false;
}

void proc(ofstream &fout) {
 vector<int> keys;
 frr(i, K)
  keys.pb(have[i]);

 _cl(can);
 _cl(next);
 _cl(v);

 can[(1 << N) - 1] = true;
 next[(1 << N) - 1] = -1;
 v[(1 << N) - 1] = true;

 if(!rec(keys, 0)) {
  fout << "IMPOSSIBLE" << endl;
  return;
 }

 int p = 0;
 while(true) {
  if(next[p] == -1) break;
  fout << next[p] + 1 << " ";
  p = p | (1 << next[p]);
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
