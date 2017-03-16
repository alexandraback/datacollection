//============================================================================
// Name        : Codejam2012_Dancing.cpp
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

int A[110],N,S,P;
PII B[110];
bool F[110];

int solve()
{
	int i,sol=0;

	fill(F,F+N,true);

	for(i=0; i<N; i++)
	{
		if(A[i]<0 || A[i]>30)
		{
			F[i] = false;
			continue;
		}

		if(A[i] == 0)
		{
			if(P <= 0)
				sol++;
			F[i] = false;
			continue;
		}

		if(A[i] == 1)
		{
			if(P <= 1)
				sol++;
			F[i] = false;
			continue;
		}

		if(A[i] == 29 || A[i] == 30)
		{
			if(P <= 10)
				sol++;
			F[i] = false;
			continue;
		}

		if(A[i] == 0)
		{
			if(P <= 1)
				sol++;
			F[i] = false;
			continue;
		}



		if(A[i]%3 == 0)
		{
			B[i].FF = A[i]/3;
			B[i].SS = B[i].FF+1;
		}
		else if(A[i]%3 == 1)
		{
			B[i].FF = A[i]/3+1;
			B[i].SS = B[i].FF;
		}
		else
		{
			B[i].FF = A[i]/3+1;
			B[i].SS = B[i].FF+1;
		}
		//printf("%d : %d %d\n",i,B[i].FF,B[i].SS);
	}

	for(i=0; i<N; i++)
	{
		if(S>0)
		{
			if(F[i] && B[i].FF==P-1 && B[i].SS==P)
			{
				F[i] = false;
				sol++;
				S--;
			}
		}
		else
			break;

	}
	//cout << "sol1 : "<<sol<<endl;
	for(i=0; i<N; i++)
	{
		if(F[i])
		{
			if(B[i].FF>=P)
				sol++;
		}
	}
	//cout << "sol2 : "<<sol<<endl;
	return sol;
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w+", stdout);

	int t,i,j=1,sol;
	s(t);
	while(j<=t)
	{
		s(N); s(S); s(P);
		for(i=0; i<N; i++)
			s(A[i]);
		sol = solve();
		printf("Case #%d: %d\n",j,sol);
		j++;
	}

	return 0;
}
