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

#define fii "c.inp"
#define foo "c.out"
#define MOD 1000000007

using namespace std;

typedef pair<int, int> II;
typedef vector<int> VI;

bool m[55];

void input()
{
	int itest, ntest, c, d, v;
	int res, i, j, x;
	
	scanf("%d", &ntest);
	repi(itest,1, ntest){
		scanf("%d %d %d", &c, &d, &v);
		
		repi(i, 1, v)	m[i] = false;
		m[0] = true;
		
		fori(i, d){
			scanf("%d", &x);
			repd(j, v, x)	m[j] |= m[j - x];
		}
		
		res = 0;
		while (1){
			repi(i, 1, v)	if (!m[i])	break;
			if (i > v)	break;
			
			res++;
			repd(j, v, i)	m[j] |= m[j - i];
		}
		
		printf("Case #%d: %d\n", itest, res);
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

