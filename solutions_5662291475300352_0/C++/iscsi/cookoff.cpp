#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <list>
using namespace std;
typedef long long LL;
#define FOR(k,a,b) for(int k(a); k < (b); ++k)
#define FORD(k,a,b) for(int k(b-1); k >= (a); --k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ABS(a) ((a)>0?(a):-(a))
#define EPS 1e-9

template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}

int main( int argc, char* argv[] ) {
#ifdef HOME
	freopen("C-small-1-attempt0.in","r",stdin);
	freopen("C-small-1-attempt0.out", "wb", stdout);
	//freopen("B-large.in","r",stdin);
	//freopen("B-large.out", "wb", stdout);
#endif

	int T,N;
	cin>>T;
	FOR(tc,1,T+1)
	{
		cin >> N;
		int D[2],M[2];
		int d,h,m;
		cin >> d >> h >> m;
		int ctr=1;
		if(h==1)
		{
			D[0]=d;
			M[0]=m;
		}
		else
		{
			D[1]=d;
			M[1]=m-1;
			ctr=2;
		}
		if(N>1)
		{
			cin >> d >> h >> m;
			D[1]=d;
			M[1]=m;
			ctr=2;
		}
		int res=0;
		if(ctr<2)
		{
			res = 0;
		}
		else if(M[1]==0 )
		{
			res = 1;
		}
		else
		{
			double tim0 = (360.0-D[0])/M[0];
			double tim1 = (360.0-D[1])/M[1];
			double tmp0 = tim0*M[1]+D[1];
			double tmp1 = tim1*M[0]+D[0];
			if(tmp0>=720-EPS || tmp1>=720-EPS)
				res = 1;
		}
		cout << "Case #" << tc << ": "  << res << endl;
	}
	return 0;
}

