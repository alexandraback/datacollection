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

char a[1000];

int main()
{
 int i;
 int NT;

 ifstream fin("in");
 ofstream fout("out");
 string ln, ln2;

 for(char c = 'a'; c <= 'z'; ++c)
  a[c] = '-';
 a['z'] = 'q';
 a['q'] = 'z';

 frr(i, 3) {
  getline(fin, ln);
  getline(fin, ln2);
  frr(i, sz(ln))
   a[ln[i]] = ln2[i];
 }

 for(char c = 'a'; c <= 'z'; ++c)
  cout << a[c] << ' ' << c << endl;
 cout << endl;

 getline(fin, ln);
 istringstream is(ln);
 is >> NT;

 fr(i, NT)
 {
  getline(fin, ln);
  fout << "Case #" << i + 1 << ": ";
  cout << "Case #" << i + 1 << endl;
  frr(i, sz(ln))
   fout << a[ln[i]];
  fout << endl;
 }

 return 0;
}
