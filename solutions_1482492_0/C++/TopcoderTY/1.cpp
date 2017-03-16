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

double dVal;
int nVal, aVal;
double tt[2001];
double xx[2001];
double vv[2001];

double acc[251];

double getValue(double a, double b, double c)
{
	double ans1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
	double ans2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
	if(ans1 > 0.0) return ans1;
	if(ans2 > 0.0) return ans2;
	return -1.0;
}

double getPosRemainTime(double pos, double ac)
{
	if(fabs(pos - dVal) < 1e-8) return 0;
	double ret = 0.0;

	int lec = (lower_bound(xx,xx+nVal,pos) - xx);
	--lec;

	double nPos = pos;
	for(int i=lec;i<nVal-1;++i){
		double tPos = xx[i+1];
		if(tPos > dVal) tPos = dVal;
		ret += (tPos - nPos) / vv[i+1];
		nPos = xx[i+1];

		if(fabs(tPos - dVal) < 1e-8) break;
	}

	return ret;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int tests; scanf("%d",&tests);
	for(int test=1;test<=tests;++test){
		scanf("%lf %d %d",&dVal,&nVal,&aVal);

		for(int i=0;i<nVal;++i){
			scanf("%lf %lf",&tt[i], &xx[i]);
			if(i != 0){
				vv[i] = (xx[i] - xx[i-1]) / (tt[i] - tt[i-1]);
			}
		}
		for(int i=0;i<aVal;++i){
			scanf("%lf",&acc[i]);
		}

		printf("Case #%d:\n",test);
		for(int i=0;i<aVal;++i){
			for(int j=0;j<nVal;++j){
				double val = getValue(0.5 * acc[i], -vv[j+1], -xx[j]);
				if(val < 0.0) continue;

				double dis = val*val*acc[i]*0.5;
				if(dis >= dVal){
					printf("%.8llf\n", sqrt(dVal*2/acc[i]));
				}else{
					printf("%.8llf\n",val + getPosRemainTime(dis,acc[i]));
				}
				break;
			}
		}
	}

	return 0;
}
