//============================================================================
// Name        : Codejam2012_1C_1.cpp
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

int N,M;

LL A[101],B[101];
int a[101],b[101];
int dp[101][101];


void solve(int k)
{
	int i,j;

	dp[0][0] = 0;
	for(i=1; i<=N; i++)
		dp[i][0] = 0;
	for(i=1; i<=M; i++)
		dp[0][i] = 0;


	for(i=1; i<=N; i++)
	{
		for(j=1; j<=M; j++)
		{
				;
		}
	}

}

void brute(int t)
{
	int i,j,k;
	LL ct1,ct2,ct3,sol,sol1,sol2,sol3;

	if(N == 3)
	{
		ct1 = 0; sol=0;
		for(i=0; i<=M; i++)
		{
			if(B[i] == A[1])
				ct1 += b[i];
			ct2 = 0;
			sol1 = miN(ct1,a[1]);
			for(j=i+1; j<=M; j++)
			{
				if(B[j] == A[2])
					ct2 += b[j];
				sol2 = sol1 + miN(ct2,a[2]);
				ct3 = 0;
				for(k=j+1; k<=M; k++)
				{
					if(B[k] == A[3])
						ct3 += b[k];
					sol3 = sol2 + miN(ct3,a[3]);
					sol = maX(sol,sol3);
				}
				sol = maX(sol,sol2);
			}
			sol = maX(sol,sol1);
		}
		if(A[1] == A[3])
		{
			ct1 = 0;
			for(i=0; i<=M; i++)
			{
				if(B[i] == A[1])
				{
					ct1 += b[i];
				}
			}
			sol1 = miN(ct1,a[1]+a[3]);
		}
		sol = maX(sol,sol1);
	}

	else if(N == 2)
	{
		ct1 = 0; ct2 = 0;
		sol = 0;
		for(i=0; i<=M; i++)
		{
			if(B[i] == A[1])
				ct1 += b[i];
			ct2 = 0;
			sol1 = miN(ct1,a[1]);
			for(j=i+1; j<=M; j++)
			{
				if(B[j] == A[2])
					ct2 += b[i];

				sol2 = sol1 + miN(ct2,a[2]);
				sol = maX(sol,sol1);
			}
			sol = maX(sol,sol1);
		}
	}

	else if(N == 1)
	{
		ct1 = 0;
		for(i=0; i<=M; i++)
		{
			if(B[i] == A[1])
			{
				ct1 += b[i];
			}
		}
		sol = miN(ct1,a[0]);
	}
	printf("Case #%d: %lld\n",t,sol);
}


int main()
{
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w+", stdout);

	int t,k=1,i;
	s(t);
	while(k<=t)
	{
		s(N); s(M);
		a[0] = 0;
		b[0] = 0;
		A[0] = 1;
		B[0] = 1;
		for(i=1; i<=N; i++)
		{
			sl(a[i]); s(A[i]);
		}
		for(i=1; i<=M; i++)
		{
			sl(b[i]); s(B[i]);
		}
		brute(k);
		k++;
	}

	return 0;
}
