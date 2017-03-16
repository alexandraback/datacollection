
/*Paresh Verma*/
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
#include <cstring>
#include <queue>		//max heap implementation
#include <limits.h>

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mkp make_pair
#define fi first
#define se second
#define LL long long
#define fill(x,y) memset(x, y, sizeof(x))
#define debug(a) { for( typeof(a.begin()) it = a.begin() ; it != a.end() ; it++ ) cout << *it << " "; cout << endl; }

using namespace std;

//class comparators for queue and others
class classcomp{
	public:
		bool operator() (const int& l, const int& r)const{
			return l<r;
		}
};

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

long long e, r, n;
#define maxn 10001
long long v[maxn];

typedef long long ll;
typedef pair<long long, int> pli;
pli a[maxn];

int main(){
	int T;
	scanf("%d",&T);
	int i,j,k,l;
	for(int p=1; p<=T; p++){
		printf("Case #%d: ",p);
		scanf("%lld%lld%lld",&e,&r,&n);
		long long gain=0;
		for(i=0;i<n;i++){
			scanf("%lld",&v[i]);
			a[i].fi=v[i]; a[i].se=i;
		}
		sort(a,a+n,greater<pli>());
		map<int, long long> dd;
		typedef map<int,long long>::iterator itr;
		dd[-1]=e; dd[n-1]=r;
		for(i=0;i<n;i++){
			itr lo,up;	
			lo=dd.lower_bound(a[i].se);
			lo--;
			up=dd.upper_bound(a[i].se-1);
			//cout << a[i].se << " " << lo->fi << " " << up->fi << endl;
			int num=(up->fi) - (lo->fi);
			long long total=lo->se + num*r;
			long long tospend=0;
			ll leave=up->se-(up->fi - a[i].se )*r;
			if(leave<r)
				leave=r;
			ll maxreach = lo->se + (a[i].se - lo->fi - 1)*r;
			if(maxreach>e)
				maxreach=e;
			tospend=maxreach-leave+r;
			//cout << "reach" << maxreach << " leave" << leave << " spend" << tospend << endl;
			dd[a[i].se]=leave;
			dd[a[i].se-1]=maxreach;
			gain+=a[i].fi*tospend;
		}
		printf("%lld\n",gain);
	}

	return 0;
}
