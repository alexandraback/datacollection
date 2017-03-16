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
#define LL long long
#define S(N) scanf("%d", &N)
#define SL(N) scanf("%lld", &N)
#define PB push_back
#define MP make_pair
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define cell pair<int,int>
#define edge pair<int, cell>
#define clear(x) memset(x,0,sizeof(x))
#define CHECK_BIT(var,pos) ((var) & (1<<(pos))
#define sp system("pause")
typedef vector<int> vi;
typedef vector<LL> vii;
cell dir[4]={cell(0,1), cell(1,0), cell(0,-1), cell(-1,0) };

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output2.txt","w",stdout);
	int t; S(t);
	REP(t1, t)
	{
		printf("Case #%d: ", t1+1);
		int x, y;
        S(x); S(y);
		if(x>0)
		REP(i,x) printf("WE");
		else REP(i,-1*x) printf("EW");
		if(y>0) REP(i,y) printf("SN");
		else REP(i,-1*y) printf("NS");
		printf("\n");
	}
	return 0;
}
