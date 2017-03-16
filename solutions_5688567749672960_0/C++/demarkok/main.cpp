#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > pii;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second       
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

const int inf = 1e9;

int t;

LL rev(int x) {
	int res = 0;
	while (x) {
		res *= 10;
		res += x % 10;
		x /= 10;
	}
	return res;
}

int bfs(LL x) {
    queue < pair < LL, int > > qu;
	unordered_map < LL, bool > used;    
	qu.push(mp(x, 1));
	used[x] = true;           
	while (!qu.empty()) {
		pair < LL, int > v = qu.front();
		qu.pop();     
		if (v.ff == 1) {
			return v.ss;	
		}
		if (rev(v.ff) < v.ff && v.ff % 10) {
			if (!used[rev(v.ff)])
		 		qu.push(mp(rev(v.ff), v.ss + 1));
			used[rev(v.ff)] = true;
		}
		if (!used[v.ff - 1])
			qu.push(mp(v.ff - 1, v.ss + 1));    
		used[v.ff - 1] = true;
	}                          
	return -1;
}
             
int main() {
	scanf("%d", &t);

	forn(q, t) {
	    LL n;
		scanf("%I64d", &n);
		printf("Case #%d: %d\n", q + 1, bfs(n));                    
	}

	return 0;
}    
