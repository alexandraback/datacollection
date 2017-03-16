#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cstring>
#include <limits>

using namespace std;

#define FOR(I,A,B) for(int I= (A); I<(B); ++I)
#define REP(I,N) FOR(I,0,N)
#define S(N) scanf("%d", &N)
#define SL(N) scanf("%lld", &N)
#define PB push_back
#define MP make_pair
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define cell pair<int,int>
#define edge pair<int, cell>
typedef vector<char *> vs;
typedef long long int LL;
typedef vector<int> vi;
typedef vector<LL> vii;
int main()
{
	int t;S(t);
	REP(t1,t)
	{
		printf("Case #%d: ", t1+1);
		int x,y;S(x);S(y);
		if(x>0)
			REP(i,x)
				cout<<"WE";
		else
			REP(i,-1*x)
				cout<<"EW";
		if(y>0)
			REP(i,y)
				cout<<"SN";
		else
			REP(i,-1*y)
				cout<<"NS";
		cout<<endl;
	}
	return 0;
}

