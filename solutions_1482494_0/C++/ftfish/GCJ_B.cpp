#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define debuging

#ifdef debuging
#define FIN  {freopen("new.in" , "r" , stdin) ;}
#define FOUT {freopen("new.out" , "w" , stdout) ;}
#define OUT(x)  {cout<< #x << "  : " << x <<endl ;}
#define ERR(x)  {cout<<"#error: "<< x ; while(1) ;}
#endif

#ifndef debuging
#define FIN  ;
#define FOUT ;
#define OUT(x)  ;
#define ERR(x)  ;
#endif

#define rep(i,a,b) for(int i=(a);i<(int)(b);i++)
#define REP(i,n) rep(i,0,(n))
#define SZ(x) (int)((x).size())
#define CLR(a) memset((a),0,sizeof (a))
#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define contains(c, e) (find(all(c), (e)) != (c).end())
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> vint;
typedef set<int> sint;
typedef pair<int, int> pint;

const int maxint = -1u >> 2;
const double eps = 1e-8;
const double pi = acos(-1.0);

const int mn =1005, inf = 0x3f3f3f3f;
int a[mn][2], flg[mn];

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int Tn;
	scanf("%d", &Tn);
	for (int Tc = 1; Tc <= Tn; ++Tc) {
		int ans = 0;
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i) {
			scanf("%d%d",&a[i][0],&a[i][1]);
			flg[i] = 0;
		}
		int cur = 0;
		while(cur < 2*n) {
			// find 2star
			bool found2 = 0;
			for(int i=0;i<n;++i)
				if(flg[i]<2 && cur >= a[i][1]){
					cur += 2 - flg[i];
					flg[i] = 2;
					ans ++;
					found2=1;
				}
			if(!found2) {
				int max2=0,maxp=-1;
				for(int i=0;i<n;++i)
					if(flg[i]==0 && cur >= a[i][0] && (maxp==-1 || a[i][1]>max2)) {
						max2 = a[i][1];
						maxp=i;
					}
				if(maxp==-1) {
					ans = -1;
					break;
				}
				flg[maxp] = 1;
				ans ++;
				cur ++;
			}
		}

		printf("Case #%d: ", Tc);
		// output statement(s);
		if(ans!=-1)printf("%d\n", ans);
		else puts("Too Bad");
	}

	return 0;
}

