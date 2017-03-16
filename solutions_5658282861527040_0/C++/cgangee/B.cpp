#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <ctime>

using namespace std;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef long long ll;
template <class T> void checkmax(T &t, T x){ if (x>t) t=x;}
template <class T> void checkmin(T &t, T x){ if (x<t) t=x;}
template <class T> void _checkmax(T &t, T x){ if (t==-1 || x>t) t=x;}
template <class T> void _checkmin(T &t, T x){ if (t==-1 || x<t) t=x;}
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it=(v).begin(); it!=(v).end(); ++it)
#define clr(a, b) memset(a, b, sizeof(a))
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define sz(a) ((int)(a).size())
#define pb push_back
#define itr iterator

int i,j,k,m,n,l;

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int ts;
	scanf("%d", &ts);
	repf(te, 1, ts){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		n=0;
		rep(i, a) rep(j, b) if ((i&j)<c) n++;

		printf("Case #%d: %d\n",te, n);
	}
	return 0;
}

