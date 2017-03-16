//Pham Huu Canh
//
//Algorithm:
//Complexity:
//AC:

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define max64 9223372036854775807LL
#define max32 2147483647
#define maxty 1001001001
#define max16 32767
#define EPS 1e-8
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define PQ priority_queue
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define timmax(x, y)    ((x) > (y) ? (x) : (y))
#define timmin(x, y)    ((x) < (y) ? (x) : (y))
#define fori(i, n)      for((i) = 0; (i) < (n); (i)++)
#define ford(i, n)      for((i) = (n-1); (i) >= 0; (i)--)
#define fore(i, v)		for(typeof(v.begin()) i = v.begin(); i != v.end(); i++)
#define repi(i, a, b)   for((i) = (a); (i) <= (b); (i)++)
#define repd(i, a, b)   for((i) = (a); (i) >= (b); (i)--)
#define all(tmpv)      tmpv.begin(), tmpv.end()

#define fii "b.inp"
#define foo "b.out"
#define MOD 1000000007

using namespace std;

typedef pair<int, int> II;
typedef vector<int> VI;

char s[150];
int d[150];
double dp[105][105];

void input()
{
	int itest, ntest, nk, nl, ns;
	int i, j, pos, cur, banana;
	double p;
	
	scanf("%d", &ntest);
	repi(itest,1, ntest){
		scanf("%d %d %d", &nk, &nl, &ns);
		
		memset(d, 0, sizeof(d));
		scanf("%s", &s);
		fori(i, nk)	d[s[i] - 'A']++;
		
		p = 1.0;
		scanf("%s", &s);
		bool can = true;
		fori(i, nl){
			p *= (double)d[s[i] - 'A'] / (double)nk;
			if (d[s[i] - 'A'] == 0)	can = false;
		}
		
		//////////////////////////////////////////////////////////////////////
		if (ns < nl)	banana = 0;
		else{
			pos = -1;
			for (i = 1; i < nl; i++){
				for (j = i; j < nl; j++)	if (s[j] != s[j-i])	break;
				if (j == nl){
					pos = i;
					break;
				}
			}
			if (pos == -1)	banana = ns / nl;
			else{
				banana = 0;
				cur = 0;
				while (cur + nl <= ns){
					banana++;
					cur += pos;
				}
			}
		}
		if (!can)	banana = 0;
		
		/////////////////////////////////////////////////////////
		
		memset(dp, 0.0, sizeof(dp));
		dp[0][0] = 1.0;
		repi(i, 1, ns){
			if (i < nl)	dp[i][0] = 1.0;
			else{
				dp[i][0] = dp[i-nl][0] * (1.0 - p);
				repi(j, 1, ns)	dp[i][j] = dp[i - nl][j] * (1.0 - p) + dp[i - nl][j - 1] * p;
			}
		}
		
		double res = 0;
		repi(i, 0, ns)	res += dp[ns][i] * i;
		
		printf("Case #%d: %.7lf\n", itest, (double)banana - res);
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
    	freopen(fii,"r",stdin);
    	freopen(foo,"w",stdout);
    #endif

    input();

    return 0;
}

