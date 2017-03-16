#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define f(i,a,b) for(int i=(a);i<(b);++i)
#define r(i,n) f(i,0,n)
#define fe(i,a,b) for(int i=(a);i<=(b);++i)
#define re(i,n) fe(i,0,n)
#define fsz(i,a,v) f(i,a,sz(v))
#define rsz(i,v) r(i,sz(v))
#define all(v) v.begin(),v.end()
#define set(x,with) memset(x,with,sizeof(x))
string itoa(int i) { stringstream ss; ss<<i; return ss.str(); }
#define same(a,b) (fabs((a)-(b))<0.0000001)
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int tests; scanf("%d",&tests);
	for(int test=1;test<=tests;++test){
		int n; scanf("%d",&n);
		int sum = 0;
		vector<int> vals;
		for(int i=0;i<n;++i){
			int x; scanf("%d",&x);
			vals.push_back(x);
			sum += x;
		}
		printf("Case #%d:", test);

		int nSum = sum;
		int m = n;
		bool vis[201]; memset(vis,0,sizeof(vis));
		for(int i=0;i<n;++i){
			double ans = (((sum*2.0) - vals[i]*1.0*n)*100.0)/(sum*n);
			if(ans < 0.0){
				ans = 0.0;
				vis[i] = true;
				nSum -= vals[i];
				--m;
			}
		}

		for(int i=0;i<n;++i){
			if(vis[i]){
				printf(" %.6llf",0.0);
				continue;
			}
			double ans = (((sum + nSum) - vals[i]*1.0*m)*100.0)/(sum*m);
			printf(" %.10llf",ans);
		}

		printf("\n");
	}

	return 0;
}
