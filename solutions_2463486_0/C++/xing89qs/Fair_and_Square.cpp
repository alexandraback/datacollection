#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
template<class T> inline T sqr(T x) { return x * x; }
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<LL, LL> PLL;
typedef pair<LL, int> PLI;
typedef pair<LD, LD> PDD;
#define MP make_pair
#define PB push_back
#define sz(x) ((int)(x).size())
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

using namespace std;

set<LL> s;
LL num[] = {0,1,4,9,121,484,10201,
12321,14641,40804,44944,1002001,
1234321,4008004,100020001,102030201,
104060401,121242121,123454321,125686521,
400080004,404090404,10000200001,10221412201,
12102420121,12345654321,40000800004,
1000002000001,1002003002001,1004006004001,
1020304030201,1022325232201,1024348434201,
1210024200121,1212225222121,1214428244121,
1232346432321,1234567654321,4000008000004,
4004009004004,100000020000001,100220141022001,
102012040210201,102234363432201,121000242000121,
121242363242121,123212464212321,123456787654321,};

char buffer[20];

int main(void){
      freopen("data.in","r",stdin);
	  freopen("data.out","w",stdout);
	  int t,tt = 1;
	  cin>>t;
	  while(t--){
		  LL a,b;
		  cin>>a>>b;
		  int n = sizeof(num)/sizeof(LL);
		  cout<<"Case #"<<tt++<<": ";
		  cout<<lower_bound(num,num+n,b+1)-lower_bound(num,num+n,a)<<endl;
	  }
}

