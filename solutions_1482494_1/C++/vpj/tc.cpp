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

struct Level {
 int low, high;

 bool operator <(const Level &l) const {
  return high < l.high;
 }
};

int N;
Level a[100000];
bool v1[100000], v2[100000];

void read(ifstream &fin)
{
 fin >> N;
 frr(i, N)
  fin >> a[i].low >> a[i].high;
}

int cal() {
 int res = 0, stars = 0;

 sort(a, a + N);
 _cl(v1), _cl(v2);

 while(true) {
  frr(i, N)
   if(!v2[i] && a[i].high <= stars) {
    v2[i] = true;
    stars += 1 + (v1[i] ? 0 : 1);
    v1[i] = true;
    res++;
   }

  bool fin = true;
  frr(i, N) if(!v2[i]) fin = false;
  if(fin)
   break;

  int n = -1;
  for(int i = N - 1; i >= 0; --i)
   if(!v1[i] && a[i].low <= stars) {
    n = i;
    break;
   }

  if(n == -1)
   return -1;

  v1[n] = true;
  stars++;
  res++;
 }

 return res;
}

void proc(ofstream &fout)
{
 int r = cal();
 if(r == -1)
  fout << "Too Bad";
 else
  fout << r;
 fout << endl;
}

int main()
{
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
