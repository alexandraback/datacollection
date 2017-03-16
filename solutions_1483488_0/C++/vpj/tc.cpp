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

int A, B;
int a[10];

void read(ifstream &fin)
{
 fin >> A >> B;
}

int cal(int n) {
 int lim = 1, cnt = 0;

 while(lim <= n) lim *= 10;

 for(int s = 10; s < lim; s *= 10) {
  int m = (n / s) + (n % s) * (lim / s);
  if(m < lim / 10)
   continue;
  if(m < n && m >= A) {
   frr(i, cnt)
    if(a[i] == m) {
     m = -1;
     break;
    }
   if(m != -1) {
    a[cnt] = m;
    cnt++;
   }
  }
 }

 return cnt;
}

void proc(ofstream &fout)
{
 int ans = 0;
 for(int n = A; n <= B; ++n)
  ans += cal(n);

 fout << ans << endl; 
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
