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
struct hashtemp {

	enum {
		bucket_size = 4, min_buckets = 8
	};
	virtual size_t operator()(const key &p) const=0;

};

using namespace std;
#ifndef M_PI
const long double M_PI=acos((long double)-1);
#endif
#define rep(i,n) for(int  i=0;i<(int)(n);++i)
long double ZERO = 0;
const long double INF = 1 / ZERO, EPSILON = 1e-12;
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

int r,c;
int cl[100][100];
int fl[100][100];
int h;
struct state
{
	double t;
	int i,j;
	bool operator<(const state&s)const
	{
		return t>s.t;
	}
};
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

bool getDir(int i,int j,int k,int &ni,int &nj,int r,int c)
{
	ni=i+dir[k][0];
	nj=j+dir[k][1];
	return ni>=0 && ni<r && nj<c && nj>=0;
}
double dist[100][100];
int main() {
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("1.in", "rt", stdin);
	freopen("1.out", "wt", stdout);
#endif
	int T;
	cin >> T;
	rep(t,T) {
		cin>>h>>r>>c;
		rep(i,r)
			rep(j,c)
				cin>>cl[i][j],dist[i][j]=1e18;
		rep(i,r)
			rep(j,c)
				cin>>fl[i][j];
		dist[0][0]=0;
		double res;
		state st={0,0,0};
		priority_queue<state> q;
		q.push(st);

		while(q.size())
		{
			st=q.top();
			q.pop();
			if(dist[st.i][st.j]!=st.t)
				continue;
			if(st.i==r-1 && st.j==c-1)
			{
				res=st.t;
				break;
			}
			state ns;
			rep(k,4)
				if(getDir(st.i,st.j,k,ns.i,ns.j,r,c))
				{
					if(max(fl[st.i][st.j],fl[ns.i][ns.j])+50<=min(cl[st.i][st.j],cl[ns.i][ns.j]))
					{
						double cwl=h-st.t*10;
						double twl=cl[ns.i][ns.j]-50;
						double hanotat=min(cwl,twl);
						double nt=(h-hanotat)/10;
						if(fabs(nt)<1e-9){}
						else
						if(hanotat>=fl[st.i][st.j]+20)
							nt+=1;
						else
							nt+=10;
						if(nt<dist[ns.i][ns.j])
						{
							dist[ns.i][ns.j]=nt;
							ns.t=nt;
							q.push(ns);
						}
					}
				}

		}
		printf("Case #%d: %.7lf\n", t + 1,res);
	}
	return 0;
}
