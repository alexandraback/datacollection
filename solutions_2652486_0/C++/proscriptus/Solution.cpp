#define _CRT_SECURE_NO_DEPRECATE

#pragma comment(linker,"/STACK:267386880")

#include <iostream>
#include <functional>
#include <ctime>
#include <cstdio>
#include <memory>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <utility>
#include <iterator>
#include <bitset>
#include <sstream>
#include <numeric>

#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
#define LL long long
#define ULL unsigned LL
#define VI vector<int>
#define X first
#define Y second
#define sz(_v) ((int)_v.size())
#define all(_v) (_v).begin(),(_v).end()
#define FOR(i,a,b) for (int i(a); i<=(b); ++i)
#define rep(i,a) FOR(i,1,a)
#define rept(i,a) FOR(i,0,(int)(a)-1)
#define x1 X1
#define y1 Y1
#define sqr(a) ((a)*(a))
#define C(a) memset((a),0,sizeof (a))
#define MS(a,x) memset((a),(x),sizeof (a))
#define INF 1000000000
#define PI 3.141592653589
#define eps 0.00000000001
#define MOD 1000000007
#define PRIME 1000003

using namespace std;

vector<VI> var;
vector<map<int,double>> prob;
VI cur;
int N,M;

void getVar()
{
	if (sz(cur)==N)
	{
		var.pb(cur);
		return;
	}
	for (int i=2; i<=M; ++i)
	{
		cur.pb(i);
		getVar();
		cur.pop_back();
	}
}

void countProb()
{
	int mx=1;
	rept(i,N)
		mx*=2;
	prob.resize(sz(var));
	for (int i=0; i<sz(var); ++i)
	{
		int prod;
		rept(x,mx)
		{
			int y(x);
			prod=1;
			rept(j,N)
			{
				if (y%2==1)
					prod*=var[i][j];
				y/=2;
			}
			prob[i][prod]+=1./mx;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}
#endif
	int tst;
	scanf("%d",&tst);
	int r,k;
	scanf("%d%d%d%d",&r,&N,&M,&k);
	getVar();
	countProb();
	printf("Case #1:\n");
	rept(i,r)
	{
		VI smth(k);
		rept(j,k)
			scanf("%d",&smth[j]);
		int curRes(-1);
		double curMax(0.);
		rept(j,sz(var))
		{
			double cur=1.;
			rept(q,k)
				cur*=prob[j][smth[q]];
			if (cur>curMax)
			{
				curMax=cur;
				curRes=j;
			}
		}
		if (curRes==-1)
			curRes=0;
		rept(j,N)
			printf("%c",'0'+var[curRes][j]);
		puts("");
	}
	return 0;
}