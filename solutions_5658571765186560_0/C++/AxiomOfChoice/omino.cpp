#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)
#define clr1(i) CLR(i,-1)
#define bit(x,i) ((x>>i)&1)
#define M(x) ((x)%MOD)
#define acc(f,x,y) x=f(x,y)
#define fst first
#define snd second
#define tup make_tuple

bool block(int x, int r, int c)
{
	if(r < c) swap(r, c);
	if(x / 2 > c || (r * c) % x) return true;
	if(x <= c) return false;

	// I manually checked the following cases:
	if(x == 2 && r == 2 && c == 1)
		return false;
	if(x == 2 && r == 4 && c == 1)
		return false;
	if(x == 3 && r == 3 && c == 1)
		return true;
	if(x == 3 && r == 3 && c == 2)
		return false;
	if(x == 4 && r == 2 && c == 2)
		return true;
	if(x == 4 && r == 4 && c == 2)
		return true;
	if(x == 4 && r == 4 && c == 3)
		return false;
	return false;
}

int main()
{
	int t;
	scanf("%d", &t);
	rep(i, t)
	{
		int x, r, c;
		scanf("%d%d%d", &x, &r, &c);
		printf("Case #%d: %s\n", i + 1, block(x, r, c) ? "RICHARD" : "GABRIEL");
	}
	return 0;
}
