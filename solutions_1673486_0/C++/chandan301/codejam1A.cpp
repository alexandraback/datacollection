//============================================================================
// Name        : codejam1A.cpp
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
#define MSZ                                     100001

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;

//=========================================================================================

int A,B;
double P[MSZ],PB[MSZ];

double solve()
{
	int i;
	PB[0] = 1;
	for(i=1; i<=A; i++)
		PB[i] = PB[i-1]*P[i];

	double min = miN(A+B+1,B+2),val;
	for(i=0; i<A; i++)
	{
		val = PB[A-i]*(B-A+2*i+1) + (1-PB[A-i])*(2*B-A+2*i+2);
		/*cout << PB[A-i] << endl;
		cout << (B-A+2*i+1) << endl;
		cout << (2*B-A+2*i+2) << endl;
		cout << val << endl;
		cout << "\n\n\n\n";*/
		if(val < min)
			min = val;
	}
	return min;
}

int main()
{
	freopen("A-small-attempt0 (1).in", "r", stdin);
	freopen("output.txt", "w+", stdout);

	int t,i,j=1;
	double sol;
	s(t);
	while(j<=t)
	{
		s(A); s(B);
		for(i=1; i<=A; i++)
			cin >> P[i];
		sol = solve();
		printf("Case #%d: %0.6lf\n",j,sol);
		j++;
	}
	return 0;
}
