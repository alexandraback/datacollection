//============================================================================
// Name        : codejam2012_Recycled.cpp
// Author      : Chandan Giri
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>

//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

#define s(n)                                    scanf("%d",&n)
#define sl(n)                                   scanf("%lld",&n)
#define sf(n)                                   scanf("%lf",&n)
#define ss(n)                                   scanf("%s",n)
#define p(n)                                    printf("%d\n",n)
#define pl(n)                                   printf("%lld\n",n)
#define maX(a,b)                                ((a)>(b)?(a):(b))
#define miN(a,b)                                ((a)<(b)?(a):(b))
#define abS(x)                                  ((x)<0?-(x):(x))
#define FOR(i,a,b)                              for(int i=a;i<b;i++)
#define mp                                      make_pair
#define FF                                      first
#define SS                                      second
#define pb                                      push_back
#define SZ(v)                                   ((int)(v.size()))
#define all(x)                                  x.begin(),x.end()
#define INF                                     (int)1e9
#define LINF                                    (long long)1e18
#define EPS                                     1e-9
#define MOD                                     ((1 << 30)-1))
#define MSZ                                     80

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;

//=========================================================================================

/* Main Code begins here */
int A,B,pow10[10];

int noDig(int num)
{
	int ct=0;
	while(num>0)
	{
		ct++;
		num /= 10;
	}
	return ct;
}

int solve()
{
	int i,dig,j,start,end,t,val,sol=0;
	dig = noDig(A);
	map <int,int> mymap;
	for(i=A; i<B; i++)
	{
		end = i;
		start = 0;
		mymap.clear();
		for(j=1; j<dig; j++)
		{
			t = end%10;
			start += pow10[j-1]*t;
			end /= 10;

			if(t!=0 )
			{
				val = start*pow10[dig-j] + end;
				if(mymap.count(val)==0 && val>i && (val>=A && val<=B))
				{
					sol++;
					mymap[val] = 1;
				}
			}
		}
	}
	return sol;
}

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("output.txt", "w+", stdout);

	int t,i,sol;

	pow10[0] = 1;
	for(i=1; i<10; i++)
		pow10[i] = pow10[i-1]*10;

	s(t);
	i = 1;
	while(i<=t)
	{
		s(A); s(B);
		sol = solve();
		printf("Case #%d: %d\n",i,sol);
		i++;
	}

	return 0;
}
