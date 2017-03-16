#include <stdio.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <ctime>
#include <cstring>

using namespace std;

#define FOR(i,a,b)      for(int i(a);i<b;++i)
#define FORD(i,a,b)      for(int i(a-1);i>=b;--i)
#define REP(i,n)        FOR(i,0,n)
#define CL(a,x)         memset(a,x,sizeof(a))
#define all(ar)         (ar).begin(), (ar).end()
#define sz(a)           int((a).size())
#define foreach(x,a)    if(bool __B=true)for(const typeof(a)&__A=a;__B;__B=false)for(typeof(const_cast<typeof(a)&>(__A).begin())__T=const_cast<typeof(a)&>(__A).begin();__B && (__B=false,__T!=const_cast<typeof(a)&>(__A).end());++__T)for(x=*__T;!__B;__B=true)
#define cstr(x)         ((stringstream&)((stringstream()<<(x)))).str()
#define pb                      push_back
#define X                       first
#define Y                       second
#define infinity        -1u/2
#define grid(t)         vector<vector<t> >
#define scanI(i)                scanf("%d",&i)
#define printI(i)               printf("%d ",i)
#define printIln(i)             printf("%d\n",i)
#define scanS(i)                scanf("%s",&i)
#define printS(i)               printf("%s ",i)
#define printSln(i)             printf("%s\n",i)

int lawn[100][100];
int n, m, rmax[100], cmax[100];

bool possible()
{
	int mx;
	REP(i, n)
	{
		mx = lawn[i][0];
		FOR(j, 1, m) mx = max(mx, lawn[i][j]);
		rmax[i] = mx;
	}
	REP(i, m)
	{
		mx = lawn[0][i];
		FOR(j, 1, n) mx = max(mx, lawn[j][i]);
		cmax[i] = mx;
	}
	REP(i, n)
		REP(j, m)
		if (lawn[i][j] < rmax[i] && lawn[i][j] < cmax[j]) return false;
	return true;
}
int main()
{
	int T; scanI(T);
	REP(t, T)
	{
		scanI(n); scanI(m);
		REP(i, n)
			REP(j, m)
			scanI(lawn[i][j]);
		printf("Case #%d: ", t+1);
		if (possible()) printSln("YES");
		else printSln("NO");	
	}
    return 0;
}
