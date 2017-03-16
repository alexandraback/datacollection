#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <iomanip>
#include <string>
#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include <cassert>
#include <complex>
using namespace std;
#ifdef _GLIBCXX_DEBUG
string filename(__FILE__,string(__FILE__).find(".cpp"));
#endif
#define PB push_back
#define MP make_pair
#define SIZE(a) ((int)a.size())
#define REP(x,a) for(typeof(a.begin()) x=a.begin();x!=a.end();x++)
#define ACS(a,b) (a?a->b:0)
#define EACS(a,b,c) (a?a->b:c)
#define AUTO(a,b) typeof(b) a=(b)
#define ft first
#define sd second
const int INF=0x3f3f3f3f;
const long long INFLL=0x3f3f3f3f3f3f3f3fLL;
template<class T>
inline bool tension(T &a,const T &b)
{
	if(b<a){
		a=b;
		return true;
	}
	return false;
}
template<class T>
inline bool relax(T &a,const T &b)
{
	if(a<b){
		a=b;
		return true;
	}
	return false;
}
#define maxn 1009
int T;
int n;
double a[maxn],b[maxn];
int main()
{
	//freopen((filename+".in").c_str(),"r",stdin);
	//freopen((filename+".out").c_str(),"w",stdout);
	//freopen((filename+".err").c_str(),"w",stderr);
	scanf("%d",&T);
	int CN=0;
	while(T--){
		printf("Case #%d: ",++CN);
		int i,j;
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%lf",a+i);
		for(i=1;i<=n;i++) scanf("%lf",b+i);
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		int ans1=0,ans2=0;
		j=1;
		for(i=1;i<=n;i++){
			for(;b[i]>a[j] && j<=n;j++);
			if(j>n) break;
			ans1++;
			j++;	
		}
		
		j=n;
		for(i=n;i>=1;i--){
			if(b[j]>a[i]) j--;
			else ans2++;
		}
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
