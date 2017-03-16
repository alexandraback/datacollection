/*************************
* Stanislaw Szczesniak   *
*2013.luty, out_constest *
*************************/

#include <utility>
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string.h>
#include <tr1/functional>
#include <stack>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <list>
#include <cassert>
#include <numeric>

#define DEBUG(x) printf ("debug%d\n", x);
#define ST first
#define ND second
#define PB push_back
#define PPB pop_back
#define MP make_pair
#define PF push_front
#define PPF pop_front
#define FOR(x,b,e) for (int x=b; x<=(e);x++)
#define FORD(x,b,e) for (int x=b;x>=(e);x--)
#define REP(x,n) for (int x=0;x<(n);x++)
#define DET(a,b,c) (((LL)(b.x-a.x))*(c.y-a.y) - ((LL)(b.y-a.y))*(c.x-a.x))
#define INARR(arr, i, n) REP(i,n) scanf ("%d",&arr[i]);
#define VAR(v,n) __typeof(n) v = n
#define FOREACH(i,c) for (VAR(i,c.begin()); i != c.end(); i++) 
#define SIZE(x) ((int)(x).size())
#define NL printf ("\n")
#define MAXN 1000001
#define IY -1

using namespace std;
using std::tr1::hash;

typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef long long LL;
typedef priority_queue<PII> PQII;

bool czyp (LL a)
{
	LL b=a;
	string res;
	while (b>9)
	{
		res += ('0' + (b%10));
		b/=10;
	}
	res += ('0' + (b%10));

	REP(i,SIZE(res)/2)
	{
		if (res[i] != res[SIZE(res)-1-i])	
			return false;
	}
	return true;
}

int main () 
{
	//czyp(17771);
	
	vector<LL> vec;	
	FOR(i,0,10000001)
	{
		if(czyp((LL)i) && czyp((LL)i*i))
			vec.PB((LL)i*i);
	}

	int n;
	scanf("%d", &n);
	
	
	LL a,b;
	REP(i,n)
	{
		scanf("%lld %lld",&a, &b);
		int res = 0;
		int j = 0;
		while (vec[j] < a && j < SIZE(vec))
			j++;
		while (vec[j] <= b && j < SIZE(vec))
		{
			j++;
			res++;
		}
		printf("Case #%d: %d\n",i+1,res);
	}
	
}
