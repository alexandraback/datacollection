#include <cstdio>
#include <fstream>
#include <iostream>

#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <vector>
#include <bitset>
#include <string>
#include <cstring>
#include <algorithm>

#include <ctime>
#include <cstdlib>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(A) (int) (A).size()

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eputs(A) fputs((A), stderr)

#define sqr(A) ((A) * (A))
#define x first
#define y second
  
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair <int, int> pii;

const int T = 25;
const int N = 20;
const int SZ = 1 << N;

struct node
{
	bool flag;
	vector <int> res;
	
	node (bool flag = false)
	{
		node :: flag = flag; 
	}

	node (bool flag, vector <int> res)
	{
		node :: flag = flag;
		node :: res = res;
	}
};

int t, n, k, type[N], fcnt[T];
vector <int> tmp, v[N];
node dp[SZ];

void update (node & v, node a, int d)
{
	tmp = a.res;
	tmp.push_back(d);

	if (!v.flag || v.res > tmp)
		v = node(true, tmp);
}

bool have (int mask, int num)
{
	int cnt = fcnt[num];
	for (int i = 0; i < n; i++)
		if (mask >> i & 1) { 
			if (type[i] == num)
				cnt--;
			for (int j = 0; j < sz(v[i]); j++)
				if (v[i][j] == num)
					cnt++;
		}
	
	return cnt;
}

int main () 
{
    #ifdef DEBUG
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    #endif

    cin >> t;
    for (int test = 0; test < t; test++) {
    	cerr << test << endl;
    	
    	memset(fcnt, 0, sizeof(fcnt));
    	for (int i = 0; i < SZ; i++)	
			dp[i] = node();

    	cin >> k >> n;

    	cerr << k << ' ' << n << endl;

    	for (int i = 0; i < k; i++) {
    		int val;
    		cin >> val;
    		fcnt[val - 1]++;
    	} 

    	for (int i = 0; i < n; i++) {
    		cin >> type[i];
    		v[i].clear();
    		type[i]--;

    		int cnt;
    		cin >> cnt;
    		for (int j = 0; j < cnt; j++) {
    			int num;
    			cin >> num;
    			v[i].push_back(num - 1);
    		}
    	} 

    	dp[0] = node(true);
    	for (int i = 0; i < (1 << n); i++) 
    		if (dp[i].flag) {
    			for (int j = 0; j < n; j++) {
    				if (!(i >> j & 1) && have(i, type[j])) {
    					update(dp[i ^ (1 << j)], dp[i], j); 
					}
				}
    		}
    
		int last = (1 << n) - 1;

		printf("Case #%d: ", test + 1); 
    	if (dp[last].flag) {
    		for (int i = 0; i < n; i++)
    			printf("%d ", dp[last].res[i] + 1);
			puts("");
    	}
    	else
    		puts("IMPOSSIBLE");
    }

    return 0; 
}

