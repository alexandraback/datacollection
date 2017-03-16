// solution for 

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cassert>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include <cstdio>
#include <map>
#include <deque>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

// setiosflags(ios¡Ëscientific)
// setw()
// setfill('x')
// setioflags(ios::showpos)
// setiosflags(ios¡Ëright)

#define COUT_HEX(x) hex << x
#define COUT_F_PRE(n,f) setiosflags(ios::fixed)<<setprecision(n)<<f
#define ZERO(n) memset(n,0,sizeof(n))
#define M1SET(n) memset(n,-1,sizeof(n))
#define MIN(m,n) ((m<n)?m:n)
#define MAX(m,n) ((m>n)?m:n)

#define UL unsigned long long
#define UI unsigned int
#define LL long long

#define FOR(i,a,b)   for(LL(i) = (LL)(a);(i) < (LL)(b);(i)++)
#define FOREQ(i,a,b) for(LL(i) = (LL)(a);(i) <= (LL)(b);(i)++)
#define RFOR(i,a,b)  for(LL(i) = (a), _b(b);(i) >= _b; --(i))
//#define FOREACH(c,itr) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end();itr++)
#define ALL(a)   (a).begin(),(a).end()
#define SZ(a)	 ((int)(a).size())

#define MO 1000000007UL

#define MOD(i) (i = ((i >= MO) ? i%MO : i))



LL E,R,N;
LL v[10000];

LL dp[6][2];

LL solvesub()
{
	LL rt = 0;
	M1SET(dp);

	dp[E][1] = 0;

	FOR(i,0,N)
	{
		FOREQ(j,R,E)
		{
			LL max = -1;

			FOREQ(k,R,E)
			{
				if(-1 != dp[k][(i+1)%2] && j <= k+R)
				{
					max = MAX(max,dp[k][(i+1)%2] + (k-j+R)*v[i]);
				}
			}

			if(-1 != max)
			{
				dp[j][i%2] = max;
				rt = MAX(rt,max);
			}
		}
	}

	return rt;
}

bool solve(istream &in,ostream &out)
{
	LL T;
	in >> T;

	FOR(i,0,T)
	{
		LL ret;
		in >> E >> R >> N;

		FOR(j,0,N)
			in >> v[j];

		ret = solvesub();

		out << "Case #"<<i+1<<": "<< ret;

		out << endl;
	}

	return true;
}


int main()
{
	bool bSolved;
	time_t timeBegin = time(NULL);

	#ifndef ONLINE_JUDGE
	ifstream in("in.in");
	ofstream out("out.out");
	bSolved = solve(in,out);
	#else
	bSolved = solve(cin,cout);
	#endif
	

	#ifndef ONLINE_JUDGE
	in.close();
	if(!bSolved)
		cout << "not solved Time: " << time(NULL) - timeBegin << endl;
	else
		cout << "solved Time:" << time(NULL) - timeBegin <<endl;
	system("pause");
	#endif
	
	return 0;
}
