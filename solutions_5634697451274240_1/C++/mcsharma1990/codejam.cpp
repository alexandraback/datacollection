
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <memory.h>
#include <cassert>

using namespace std;

#define ford(i, a, b, c)        for(int i=(a); i<(b); i+=(c))
#define fori(i, a, b)           ford(i,a,b,1)
#define rep(i, n)               fori(i,0,n)
#define ifor(i, a, b)           for(int i=(a); i>=(b); i--)
#define iter(i, a)              for(auto i=(a).begin(); i!=(a).end(); i++)
#define si(x)                   ((int)x.size())
#define SS                      ({int x;scanf("%d",&x);x;})
#define pb                      push_back
#define mp                      make_pair
#define all(a)                  a.begin(),a.end()
#define fill(a, v)              memset(a, v, sizeof(a))
#define inf                     (int)1e9
#define linf                    (long long)1e18
#define V                       vector
#define S                       string
#define XX                      first
#define YY                      second
#define P(v)                    rep(i, si(v)) cout<<v[i]<<" "; puts("")

typedef V<int> vi;
typedef V<S> vs;
typedef long long ll;
typedef pair<int,int> pii;




int main() {
	freopen("/Users/mahesh/Desktop/in.txt", "r", stdin);
	freopen("/Users/mahesh/Desktop/out.txt", "w", stdout);
	int tt = SS;
	rep(t, tt) {
		S s;
		cin>>s;
		int p = si(s) - 1;
		while (p >= 0 && s[p] == '+') p--;
		int ans = 0;
		if (p < 0) {
			ans = 0;
		} else {
			ans = 1;
			fori(i, 0, p) {
				if (s[i] != s[i+1]) ans++;
			}
		}
		printf("Case #%d: %d\n", t+1, ans);
	}
}




