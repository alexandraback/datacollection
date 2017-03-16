#include <iostream>
#include <fstream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <cstdio>
#include <assert.h>

#define mset(x,y) memset(x,y,sizeof(x))
#define INF 1000000000
#define MOD 1000000007
#define pb(X) push_back(X) 
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define FOR(i,n) for (int i=0; i<(n); i++)
#define foreach(it, c) for(__typeof(c.begin()) it = c.begin(); it != c.end(); ++it)
#define sz(v) ((int) v.size())
#define mp(a, b) make_pair(a, b)
#define printr printf("Case #%d: RICHARD\n", tt)
#define printg printf("Case #%d: GABRIEL\n", tt)
 
using namespace std;
 
typedef long long int lli;
typedef pair<int,int> pii;


int main()
{
	int t;
	scanf("%d", &t);

	for(int tt = 1; tt<= t; tt++)
	{
		int x,r,c ;
		scanf("%d%d%d", &x, &r, &c);
		if(r > c) swap(r,c);

		if(x == 1) {printg; continue;}
		if(x > c) {printr; continue;}
		if((r*c)%x) {printr; continue;}
		if(x > 2*r) {printr; continue;}
		if(x < 2*r-1) {printg; continue;}
		if(x >= 7) {printr; continue;}
		if(r == 1) {printg; continue;}
		if(r == 2)
		{
			if(x == 3) {printg; continue;}
			if(x == 4) {printr; continue;}
		}
		if(r == 3)
		{
			if(x == 5)
			{
				if(c > 5) {printg; continue;}
				else {printr; continue;}
			}
			if(x == 6) {printr; continue;}
		}

		printf("%d %d %d\n", x,r,c);
		assert(0);
	}

    return 0;
}