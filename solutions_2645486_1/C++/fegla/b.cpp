/*
TASK:
LANG: C++
 */
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iterator>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <bitset>
#include <cstring>
#include <climits>
#include <deque>
#include <utility>
#include <complex>
#include <numeric>
#include <functional>
#include <stack>
#include <iomanip>
#include <ctime>
#include <valarray>
//#include "vc.h"
#ifdef _MSC_VER
#include <hash_set>
#include <hash_map>
using namespace stdext;
#else
#if __GNUC__ > 2
#include <ext/hash_set>
#include <ext/hash_map>
using namespace __gnu_cxx;
#else
#include <hash_set>
#include <hash_map>
#endif
#endif

template<class key>
struct hashtemp
{

	enum
	{
		bucket_size = 4, min_buckets = 8
	};
	virtual size_t operator()(const key &p) const=0;

};

using namespace std;
#ifndef M_PI
const long double M_PI=acos((long double)-1);
#endif
#define rep(i,n) for(int  i=0;i<(int)(n);++i)
long double ZERO=0;
const long double INF=1/ZERO,EPSILON=1e-12;
#define all(c) (c).begin(),(c).end()
#define rep2(i,a,b) for(int i=(a);i<=((int)b);++i)
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

#define sz(v) ((int)((v).size()))
#define let(x,y) __typeof(y) x(y)

#define rrep(i,n) for(int  i=((int)n)-1;i>=0;--i)
#define rall(c) (c).rbegin(),(c).rend()
#define rrep2(i,a,b) for(int i=(a);i>=((int)b);--i)
#define rforeach(it,c) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();++it)
#define rep2d(i, j, v) rep(i, sz(v)) rep(j, sz(v[i]))
#define foreach2d(i, j, v) foreach(i,v) foreach(j,*i)
#define ABS(x) ((x)>=0?(x):-(x))

template<class T,class OP>
inline int buildTable(vector<T> &v,int start,int size,vector<vector<int> > &ind,const OP& op)
{
	if(!size)
		return start;
	if(ind[start][size]!=-1)
		return 	ind[start][size];
	int x1,x2;
	return ind[start][size]=op(v[x2=buildTable(v,start+(1<<(size-1)),size-1,ind,op)],v[x1=buildTable(v,start,size-1,ind,op)])?x2:x1;
}


template<class T,class OP>
inline int rmq(vector<T> &v,int start,int end,vector<vector<int> > &ind,const OP& op)
{
	int size=(end-start+1);
	int k=0;
	do{
		size>>=1,k++;
	}while(size);
	k--;
	int x1,x2;
	return op(v[x1=buildTable(v,start,k,ind,op)],v[x2=buildTable(v,end-(1<<k)+1,k,ind,op)])?x1:x2;
}

template<class T>
inline int rMinQ(vector<T> &v,int start,int end,bool clear=false)
{
	static int x=int(log(1.0*v.size())/log(2.0)+1e-11);
	static vector<vector<int> > ind(v.size(),vector<int>(x+1,-1));
	if(clear)
	{
		 x=int(log(1.0*v.size())/log(2.0)+1e-11);
		ind.clear();
		ind.resize(v.size(),vector<int>(x+1,-1));
	}
	return rmq(v,start,end,ind,less<T>());
}


template<class T>
inline int rMaxQ(vector<T> &v,int start,int end,bool clear=false)
{

	static int x=log(1.0*v.size())/log(2.0)+1e-11;

	static vector<vector<int> > ind(v.size(),vector<int>(x+1,-1));
	if(clear)
	{ x=log(1.0*v.size())/log(2.0)+1e-11;
		ind.clear();
		ind.resize(v.size(),vector<int>(x+1,-1));
	}
	return rmq(v,start,end,ind,greater<T>());
}
int mn[(int)1e7+1];
vector<int> gn;
int E,R,N;
void solve(int s,int e)
{
	if(e<=s)return;
	int m=rMaxQ(gn,s,e);
	int mne=E;
	rrep2(i,m-1,s)
	{
		mne-=R;
		mn[i]=max(mn[i],mne);
	}
	solve(s,m-1);
	solve(m+1,e);
}
int main() {
std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("1.in","rt",stdin);
	freopen("1.out","wt",stdout);
#endif
	int t,tt=1;
	cin>>t;
	while(t--)
	{
		memset(mn,0,sizeof mn);
		cin>>E>>R>>N;
		gn.resize(N);
		rep(i,N)
			cin>>gn[i];
		rMaxQ(gn,0,N-1,1);
		solve(0,N-1);
		long long res=0;
		long long cur=E;
		rep(i,N)
		{
			long long consume=max(cur-mn[i],0ll);
			res+=(consume)*gn[i];
			cur=cur-consume+R;
		}
		cout<<"Case #"<<tt++<<": "<<res<<endl;
	}
	return 0;
}
