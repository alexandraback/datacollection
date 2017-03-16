/*
 * GCJ12R1A2.cpp
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

const int MAXN=1000+10;
struct node{
	int l1,l2;
	int c;
};
node a[MAXN];
int cmp(node x,node y){
	if(x.l2!=y.l2)return x.l2<y.l2;
	return x.l1<y.l1;
}
int cp2(node x,node y){
	if(x.l1!=y.l1)return x.l1<y.l1;
	return x.l2<y.l2;
}
node b[MAXN];
pair<int,int>ct[MAXN];
int main(int argc,char *argv[]){
	int test=rint();
	int caser=0;
	while(test--){
		int n=rint();
		int ans=0;
		int star=0;
		FOR(i,1,n){
			b[i].l1=a[i].l1=rint();b[i].l2=a[i].l2=rint();
			b[i].c=a[i].c=0;
		}
		sort(a+1,a+1+n,cmp);
		FOR(i,1,n){
			if(star>=a[i].l2){
				if(a[i].c)++star;
				else star+=2;
				a[i].c=1;
				++ans;
			}else{
				int k,tot=0;

				for(k=i;k<=n;++k)if(a[k].c==0){
					ct[tot].first=a[k].l1;
					ct[tot].second=k;
					++tot;
				}
				sort(ct,ct+tot);
				for(k=0;k<tot;++k){
					if(ct[k].first>star)break;
					++star;++ans;
					a[ct[k].second].c=1;
					if(star>=a[i].l2)break;
				}
				if(star<a[i].l2){
					ans=-1;break;
				}
				if(a[i].c)++star;
				else star+=2;
				a[i].c=1;
				++ans;
			}
		}
		printf("Case #%d: ",++caser);
		if(ans!=-1)printf("%d\n",ans);
		else puts("Too Bad");
	}return 0;
}

