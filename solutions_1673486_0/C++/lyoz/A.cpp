#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <complex>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <functional>
#include <iterator>

using namespace std;

#define dump(n) cerr<<"# "<<#n<<"="<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define iter(c) __typeof__((c).begin())
#define foreach(i,c) for(iter(c) i=(c).begin();i!=(c).end();++i)
#define all(c) (c).begin(),(c).end()
#define mp make_pair

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int,int> pii;

template<typename T>
ostream& operator<<(ostream& os,const vector<T>& a)
{
	os<<'[';
	rep(i,a.size())
		os<<(i?" ":"")<<a[i];
	return os<<']';
}

void solve()
{
	int a,b; scanf("%d%d",&a,&b);
	vd ps(a);
	rep(i,a)
		scanf("%lf",&ps[i]);
	
	vd ms(a+1);
	ms[0]=1;
	rep(i,a)
		ms[i+1]=ms[i]*ps[i];
	
	double res=b+2;
	for(int i=0;i<=a;i++){
		double p=ms[a-i];
		int key=i+(b-(a-i))+1;
		res=min(res,p*key+(1-p)*(key+b+1));
	}
	printf("%f\n",res);
}

int main()
{
	int cases; scanf("%d ",&cases);
	rep(i,cases){
		printf("Case #%d: ",i+1);
		solve();
	}
	
	return 0;
}
