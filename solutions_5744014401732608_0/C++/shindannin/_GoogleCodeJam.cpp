// topcoder.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <unordered_map>
#include "assert.h"

using namespace std;

static const double EPS = 1e-9;
template<class T> bool INRANGE(T x,T a,T b){return a<=x&&x<=b;}
template<class T> void amin(T &a,T v){if(a>v) a=v;}
template<class T> void amax(T &a,T v){if(a<v) a=v;}
int ROUND(double x) { return (int)(x+0.5); }
bool ISINT(double x) { return fabs(ROUND(x)-x)<=EPS; }
bool ISEQUAL(double x,double y) { return fabs(x-y)<=EPS*max(1.0,max(fabs(x),fabs(y))); }
double SQSUM(double x,double y) { return x*x+y*y; }
#define PI  (acos(-1))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define NG (-1)
#define BIG ((int)1e9)
#define BIGLL ((ll)4e18)
#define SZ(a) ((int)(a).size())
#define SQ(a) ((a)*(a))
typedef unsigned long long ull;
typedef long long ll;

#define PRINTF(fmt,...) fprintf(stderr,fmt,__VA_ARGS__); printf(fmt,__VA_ARGS__);


#if 1

ll numRoots(const vector <vector <ll> >& vvi )
{
	const int N = SZ(vvi);
	
	vector <ll> freq(N);
	freq[0] = 1;
	
	ll ret = 0;
	while(1)
	{
		ll sum = 0;
		for(auto a : freq)
		{
			sum += a;
		}
		if(sum==0)
		{
			break;
		}
		
		vector <ll> tmp(N);
		
		for(int a=0;a<N;++a)
			for(int b=0;b<N;++b)
			{
				tmp[a] += freq[b] * vvi[b][a];
			}
		
		ret += tmp[N-1];
		freq = tmp;
	}
	
	return ret;
}

int main(){

	freopen("../_google_code_jam_input.txt","r",stdin);
	freopen("../_google_code_jam_output.txt","w",stdout);
	
	int T;
	scanf("%d ",&T);

	for (int testcase = 0; testcase < T; ++testcase)
	{
		ll B,M;
		cin >> B >> M;
		
		vector <vector <ll> > ansvvi(B, vector <ll>(B));
		
		ll ans = NG;
		for(int i=0;i<1<<15;++i)
		{
			vector <vector <ll> > vvi(B, vector <ll>(B));
			
			if(B>=2)
			{
				if( i & (1<<0) )  vvi[0][1] = 1;
			}
			
			if(B>=3)
			{
				if( i & (1<<1) )  vvi[0][2] = 1;
				if( i & (1<<2) )  vvi[1][2] = 1;
			}
			
			if(B>=4)
			{
				if( i & (1<<3) )  vvi[0][3] = 1;
				if( i & (1<<4) )  vvi[1][3] = 1;
				if( i & (1<<5) )  vvi[2][3] = 1;
			}
			
			if(B>=5)
			{
				if( i & (1<<6) )  vvi[0][4] = 1;
				if( i & (1<<7) )  vvi[1][4] = 1;
				if( i & (1<<8) )  vvi[2][4] = 1;
				if( i & (1<<9) )  vvi[3][4] = 1;
			}
			
			if(B>=6)
			{
				if( i & (1<<10) ) vvi[0][5] = 1;
				if( i & (1<<11) ) vvi[1][5] = 1;
				if( i & (1<<12) ) vvi[2][5] = 1;
				if( i & (1<<13) ) vvi[3][5] = 1;
				if( i & (1<<14) ) vvi[4][5] = 1;
			}
			
			ll ret = numRoots(vvi);
			
/*
			for(int y=0;y<B;++y)
			{
				for(int x=0;x<B;++x)
				{
					if(x==B-1)
					{
						PRINTF("%lld\n",vvi[y][x]);
					}
					else
					{
						PRINTF("%lld",vvi[y][x]);
					}
				}
			}
			PRINTF("ret=%lld\n",ret);
*/			

			if(ret==M)
			{
				ans = ret;
				ansvvi = vvi;
				break;
			}
		}
		

		if(ans==NG)
		{
			PRINTF("Case #%d: IMPOSSIBLE\n",testcase+1);
		}
		else
		{
			PRINTF("Case #%d: POSSIBLE\n",testcase+1);

			for(int y=0;y<B;++y)
			{
				for(int x=0;x<B;++x)
				{
					if(x==B-1)
					{
						PRINTF("%lld\n",ansvvi[y][x]);
					}
					else
					{
						PRINTF("%lld",ansvvi[y][x]);
					}
				}
			}
		}
	}
	
	return 0;
}


#else

int main(){

	freopen("../_google_code_jam_input.txt","r",stdin);
	freopen("../_google_code_jam_output.txt","w",stdout);

	int T;
	scanf("%d ",&T);

	for (int testcase = 0; testcase < T; ++testcase)
	{
		int N;
		cin >> N;
		
		vector <pair <int, int> > vi(N);
		for(int i=0;i<N;++i)
		{
			int tmp;
			cin >> tmp;
			vi[i].first = tmp;
			vi[i].second = i;
		}
		
		vector <string> eva;
		while(1)
		{
			sort(vi.rbegin(),vi.rend());
			if(vi[0].first==0)
			{
				break;
			}
			
			string s;
			s += string(1, 'A'+vi[0].second);
			vi[0].first--;

			sort(vi.rbegin(),vi.rend());
			if(vi[0].first==0)
			{
				eva.push_back(s);
				break;
			}
			
			int sum = 0;
			for(int i=0;i<N;++i)
			{
				sum += vi[i].first;
			}
			
			
			if(vi[0].first*2>sum)
			{
				s += string(1, 'A'+vi[0].second);
				vi[0].first--;
			}
			eva.push_back(s);
		}
		
		
		
		PRINTF("Case #%d:",testcase+1);
		
		for(int i=0;i<SZ(eva);++i)
		{
			if(i==SZ(eva)-1)
			{
				PRINTF(" %s\n",eva[i].c_str());
			}
			else
			{
				PRINTF(" %s",eva[i].c_str());
			}
		}

	}

	return 0;
}

#endif