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

vector<vector<int> > link;

bool backEdge[1001];

bool isExist(int res)
{
	for(int i=0;i<sz(link[res]);++i){
		int next = link[res][i];
		if(backEdge[next]) return true;
		bool flag = isExist(next);
		if(flag) return true;
	}
	backEdge[res] = true;
	return false;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int tests; scanf("%d",&tests);
	for(int test=1;test<=tests;++test){
		link.clear();
		int n; scanf("%d",&n);
		link.assign(n,vector<int>());
		for(int i=0;i<n;++i){
			int m; scanf("%d",&m);
			for(int j=0;j<m;++j){
				int k; scanf("%d",&k);
				link[k-1].push_back(i);
			}
		}

		bool flag = false;
		for(int i=0;i<n;++i){
			memset(backEdge,0,sizeof(backEdge));
			flag = isExist(i);
			if(flag) break;
		}
		if(flag){
			printf("Case #%d: Yes\n",test);
		}else{
			printf("Case #%d: No\n",test);
		}
	}

	return 0;
}
