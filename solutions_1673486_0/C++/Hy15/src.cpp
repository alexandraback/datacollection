/*
 * GCJ12R1A1.cpp
 *
 *  Created on: 2012-4-28
 *      Author: MacTavish
 */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)
#define CLR(x,val) memset((x),val,sizeof((x)))
#define swap(a,b,t) ((t)=(a),(a)=(b),(b)=(t))
#define sqr(x) ((x)*(x))
#define sgn(a) ((a)>eps?1:((a)<-eps?-1:0))
#define SZ(a) (int((a).size()))
template<class T>inline T MAX(T a,T b){return a>b?a:b;}
template<class T>inline T MIN(T a,T b){return a<b?a:b;}
template<class T>inline T GCD(T a,T b){return b==0?a:GCD(b,a%b);}
inline int rint() {int x;scanf("%d",&x);return x;}
typedef long long i64;
typedef unsigned long long u64;
const double pi = acos(-1.0);
const double eps = 1e-10;
const int inf = 0x3fffffff;
const int MAXN=100000+10;
int nA,nB;
double A[MAXN];

int main(int argc,char *argv[]){
	int test=rint();
	int caser=0;
	while(test--){
		nA=rint();nB=rint();
		FOR(i,1,nA)scanf("%lf",A+i);
		double ac=1;
		FOR(i,1,nA)ac*=A[i];
		double e1=ac*(nB-nA+1)+(1-ac)*(nB+1+nB-nA+1);
		//backspace
		double e2=inf+0.0;
		double tmp;
		FOR(i,1,nA){
			double a=1.0;
			FOR(j,1,nA-i)a*=A[j];
			tmp=a*(nB-nA+1+2*i)+(1-a)*(nB-nA+1+2*i+nB+1);
			e2=MIN(e2,tmp);
		}
		double e3=(nB+2.0);
		double ans=MIN(e1,e2);
		ans=MIN(ans,e3);
		printf("Case #%d: %.6f\n",++caser,ans);
	}
}

