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

int val[20];
int n;

int dp[21][2000100];

int canMake(int mask, int i, int wantVal){
	if(wantVal < 0) return -1;
	if(wantVal == 0) return 0;
	if(i < 0) return -1;
	if((mask & (1<<i)) == 0) return canMake(mask, i-1, wantVal);
	int& res = dp[i][wantVal];
	if(res != -1){
		return res;
	}

	int ret1 = canMake(mask^(1<<i),i-1, wantVal - val[i]);
	if(ret1 != -1){
		return res = (ret1 | (1<<i));
	}

	int ret2 = canMake(mask^(1<<i),i-1, wantVal);
	if(ret2 != -1){
		return res = (ret2);
	}

	return res = -1;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int tests; scanf("%d",&tests);
	for(int test=1;test<=tests;++test){
		printf("Case #%d:", test);
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%d",&val[i]);
		}
		memset(dp,0xff,sizeof(dp));

		int coMask;
		int retMask = -1;
		for(coMask=1;coMask<(1<<(n));++coMask){
			int sum = 0;
			for(int j=0;j<n;++j){
				if((coMask&(1<<j)) > 0) sum += val[j];
			}
			if(sum%2 != 0) continue;

			retMask = canMake(coMask, n-1, sum/2);
			if(retMask != -1) break;
		}

		if(retMask == -1){
			printf(" Impossible\n");
		}else{
			printf("\n");
			int aMask = coMask ^ retMask;
			for(int i=0;i<n;++i){
				if((retMask&(1<<i)) > 0) printf("%d ",val[i]);
			}
			printf("\n");
			for(int i=0;i<n;++i){
				if((aMask&(1<<i)) > 0) printf("%d ",val[i]);
			}
		}

		printf("\n");
	}

	return 0;
}
