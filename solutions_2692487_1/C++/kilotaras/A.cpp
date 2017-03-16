//#pragma comment(linker, "/stack:1000000")

#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>

using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)

#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define ABS(A) ((A) < 0 ? (-(A)) : (A))
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()
#define pb push_back
#define mp make_pair
#define MP make_pair
const double EPS=1e-7;
const double Pi=acos(-1.0);
#define FILL(a,v) memset(a,v,sizeof(a))
#define INF 1000000000

typedef long long Long;
typedef unsigned long long ULong;
typedef unsigned int Uint;
typedef unsigned char Uchar;
typedef vector <int> VI;
typedef pair <int, int> PII;



int dp[1000002][105];

int v[200];
int n;
int m;

int sol(int w, int k)
{
	if (w >= m)
		return 0;
	if (k >= n)
		return 0;

	if (dp[w][k] != -1)
		return dp[w][k];

	if (w>v[k])
		dp[w][k] = sol(w+v[k], k+1);
	else
	{
		dp[w][k] = sol(w,k+1)+1;

		if (w != 1)
			dp[w][k] = min(dp[w][k], sol(2*w-1, k)+1);
	}		

	return dp[w][k];	
}

int sol()
{
	FILL(dp, -1);
	int a;
	cin>>a>>n;	
	REP(i,n)
	{
		cin>>v[i];
		//v[i] = rand()*10+5;
	}
	//v[0] = 1000000;
	sort(v, v+n);
	m = v[n-1]+1;

	return sol(a,0);
}

int main(int argc, char** argv)
{
	int T;
	cin>>T;
	REP(i,T)
	{
		int r = sol();
		printf("Case #%d: %d\n", i+1, r);
	}
	return 0;
}