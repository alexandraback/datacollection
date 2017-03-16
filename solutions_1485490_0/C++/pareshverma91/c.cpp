
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
#define fi first
#define se second
#define debug(a) { for( typeof(a.begin()) it = a.begin() ; it != a.end() ; it++ ) cout << *it << " "; cout << endl; }

using namespace std;

//class comparators for queue and others
class classcomp{
	public:
		bool operator() (const int& l, const int& r)const{
			return l<r;
		}
};

typedef pair<int, long long> pil;
typedef pair<pil, pil> ppp;
pil a[120],b[120];			//type, count

map<ppp, long long> dd;
int n,m;

void rec(pil x, pil y){			//for x,y fi-> index, se-> count
	ppp tt;
	tt.fi=x; tt.se=y;
	if(dd[tt]!=0){			//==0 -> not initialised
		return;
	}
	if(x.fi>=n || y.fi>=m){
		dd[tt]=-1;
		return;
	}
	long long i,j,k,l;
	if(a[x.fi].fi==b[y.fi].fi){
		k= min(x.se, y.se);
		x.se-=k; y.se-=k;
		if(x.se==0){
			x.fi++;
			x.se=a[x.fi].se;
		}
		if(y.se==0){
			y.fi++;
			y.se=b[y.fi].se;
		}
		rec(x,y);
		ppp t1;
		t1.fi=x; t1.se=y;
		l=dd[t1];
		if(l==-1)
			l=0;
		dd[tt]=k+l;
		return;
	}
	else{
		pil x1, y1;
		x1=x; y1=y;
		x1.fi++; x1.se=a[x1.fi].se;
		y1.fi++; y1.se=b[y1.fi].se;
		rec(x,y1);
		rec(x1,y);
		ppp t1;
		t1.fi=x1; t1.se=y;
		k=dd[t1];
		if(k==-1)
			k=0;
		t1.fi=x; t1.se=y1;
		l=dd[t1];
		if(l==-1)
			l=0;
		dd[tt]=max(k,l);
		return;
	}
}

int main(){
	int T,i,j,k,l;
	scanf("%d",&T);
	for(int p=1;p<=T;p++){
		printf("Case #%d: ",p);
		dd.clear();
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++){
			scanf("%lld%d",&a[i].se, &a[i].fi);
		}
		for(i=0;i<m;i++){
			scanf("%lld%d",&b[i].se, &b[i].fi);
		}
		pil a0=a[0], b0=b[0];
		a0.fi=0; b0.fi=0;
		rec(a0, b0);
		ppp tt;
		tt.fi=a0; tt.se=b0;
		printf("%lld\n",dd[tt]);
	}
	return 0;
}
