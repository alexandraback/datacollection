#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<cmath>

#include<algorithm>
#include<bitset>
#include<complex>
#include<deque>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<string>
#include<set>
#include<vector>
using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(a) (int((a).size()))
#define all(a) (a).begin(), (a).end()
#define For(it,c) for(typeof(c) it = ((c).begin()); it != ((c).end()) ; ++it)

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<int(b); ++i)

typedef complex<int> cI;
typedef pair<int,int> pII;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;


int main()
{
  int tn;
  int px,py;
  int dx,dy;
  int i;
  cin >> tn;
  for(int z=1;z<=tn;z++){
    printf("Case #%d: ",z);
    cin >> px >> py;
    dx = abs(px);
    dy = abs(py);
    for(i=0;i<dx;i++){
      if(px > 0) printf("WE");
      else printf("EW");
    }
    for(i=0;i<dy;i++){
      if(py > 0) printf("SN");
      else printf("NS");
    }
    printf("\n");
  }
  return 0;
}
