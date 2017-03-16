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
 
using namespace std;
 
typedef long long int lli;
typedef pair<int,int> pii;

char str[1010];

int main()
{
	int t;
	scanf("%d", &t);
	for(int tt = 1; tt<=t; tt++)
	{
		int n;
		scanf("%d", &n);
		scanf("%s", str);

		int add = 0;
		int curr = 0;

		for(int i=0; i<=n; i++)
		{
			str[i] -= '0';
			if(str[i] > 0 and curr < i)
			{
				add += i-curr;
				curr = i+str[i];
			}
			else curr += str[i];
		}

		printf("Case #%d: %d\n", tt, add);
	}
    return 0;
}