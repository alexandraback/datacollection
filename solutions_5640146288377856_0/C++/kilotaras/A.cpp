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

int w;
int r;

int f(int l, int r, int len) {
	if (l>=w)
		return f(w-1, r, len);

	if (r>=w)
		return f(l, w-1, len);
	
	if (l+r == len)
		return len;

	if (l+r < len)
		return INF;

	return len+1;
}



int G[30];

int g(int l) {
	if (l < w)
		return INF;

	if (G[l] >= 0)
		return G[l];

	int &res = G[l];

	res = INF;

	REP(s, w) {
		int hit = f(s, l-s-1, w-1)+r;		
		int non_hit = g(l-s-1)+r;

		if (hit >= INF)
			hit = 0;
		if (non_hit >= INF)
			non_hit = 0;

		int tmp = max(hit, non_hit);
		res = min(res, tmp);
	}

	return res;
}

int main(int argc, char** argv)
{
//	freopen("gazmyas.in","r",stdin);
//  freopen("gazmyas.out","w",stdout);
	int t,c;
	cin>>t;
	//t = 1000;
	REP(i, t) {
		FILL(G, -1);
		cin >> r >> c >> w;
		printf("Case #%d: %d\n", i+1, g(c));
	}
	return 0;
}