#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstring>
#include <ctime>
#include <queue>

using namespace std;

#define	sqr(a)		((a)*(a))
#define	rep(i,a,b)	for(int i=(a);i<(int)(b);i++)
#define	per(i,a,b)	for(int i=((a)-1);i>=(int)(b);i--)
#define	PER(i,n)	per(i,n,0)
#define	REP(i,n)	rep(i,0,n)
#define	clr(a)		memset((a),0,sizeof (a))
#define	SZ(a)		((int)((a).size()))
#define	ALL(x)		x.begin(),x.end()
#define	mabs(a)		((a)>0?(a):(-(a)))
#define	inf			(0x7fffffff)
#define	eps			1e-6

#define	MAXN		
#define MODN		(1000000007)

typedef long long ll;

#define TEST_LOCAL 1


map<string,int> mp;
int cnt = 0;

int dp[2000][2];
int rp[2000][2];

#define MAXN 2001
#define _clr(x) memset(x,0xff,sizeof(int)*n)

int hungary(int n,int mat[][MAXN],int* match1,int* match2){
	int s[MAXN],t[MAXN],p,q,ret=0,i,j,k;
	for (_clr(match1),_clr(match2),i=0;i<n;ret+=(match1[i++]>=0))
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<n&&match1[i]<0;j++)
				if (mat[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
				return ret;
}

int mat[MAXN][MAXN];
void init()
{
	cnt = 0;
	mp.clear();
	clr(dp);
	clr(rp);
}

int f(string s)
{
	if (mp.find(s) == mp.end())
	{
		mp[s] = cnt;
		cnt++;
	}
	return mp[s];
}

int g(vector<pair<int,int> > v)
{
	int n = v.size();
	vector<int> r;
	int t = 1;
	REP(i,n)
	{
		r.push_back(i);
		t *= i + 1;
	}

	int res = 0;
	while (t--)
	{
		map<int,int> mm;
		map<int,int> nn;
		int cc = 0;
		REP(i,n)
		{
			int x = v[r[i]].first;
			int y = v[r[i]].second;
			if (mm[x] > 0 && nn[y] > 0)
			{
				cc++;
			}
			mm[x]++;
			nn[y]++;
		}
		if (res < cc)
		{
			res = cc;
		}
		next_permutation(r.begin(),r.end());
	}
	return res;
}

int main()
{
#if TEST_LOCAL
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif

	int T;
	scanf("%d",&T);

	rep(CASE,1,T + 1)
	{
		init();
		int n;
		scanf("%d",&n);
		vector<pair<int,int> > v;
		REP(i,n)
		{
			char s[30],t[30];
			scanf("%s %s",s,t);
			string r = s;
			r += "_1";
			int x = f(r);
			r = t;
			r += "_2";
			int y = f(r);
			v.push_back(make_pair(x,y));
		}
		
		clr(mat);
		REP(i,n)
		{
			int x = v[i].first;
			int y = v[i].second;
			mat[x][y] = 1;
		}
		int m1[MAXN];
		int m2[MAXN];
		int res = hungary(cnt,mat,m1,m2);

		for (int i = 0;i < cnt;i++)
		{
			if (m1[i] == -1 && m2[i] == -1)
			{
				res++;
			}
		}

		printf("Case #%d: ",CASE);
		printf("%d\n",n - res);
	}

	return 0;
}
