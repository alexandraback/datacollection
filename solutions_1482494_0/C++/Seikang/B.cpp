//Seikang

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <utility>

#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>

#include <cmath>
#include <complex>
#include <algorithm>

#include <ctime>
#define gtime clock()

using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, lo, hi) for(int i = (lo); i <= (hi); i++)
#define FORD(i, hi, lo) for(int i = (hi); i >= (lo); i--)
#define FE(it, cont) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define ALL(cont) (cont).begin(), (cont).end()
#define SZ(cont) (int)((cont).size())
#define PB  push_back
#define MP  make_pair

template<class T> vector<T> split(const string &s){stringstream ss(s);vector<T> a;T t;while(ss >> t)a.PB(t);return a;}
template<class T> T parse(const string &s){stringstream ss(s);T e;ss >> e;return e;}
template<class T> string toString(const T &e){stringstream ss();ss << e;return ss.str();}

typedef long long int64;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;

const int64 oo = (1ll << 30);
const int MAXN = (int)1e5 + 1;
const int mod = (int)1e9;
const double eps = 1e-9;
const double pi = acos(-1);

int a[MAXN], b[MAXN];
int step[MAXN];
int n;
int stars;
int steps;
int get_next()
{
	int ans = -1;
	int maxB = -1;
	int ans2 = -1;
	int maxB2 = -1;
	REP(i, n)
	{
		if(step[i] == 0 && stars >= b[i])
			return i;
		if(step[i] == 2)continue;
		if(step[i] == 1)
		{
			if(b[i] > maxB && stars >= b[i])
			{
				ans = i;
				maxB = b[i];
			}
		}
		if(step[i] == 0)
		{
			if(b[i] > maxB2 && stars >= a[i])
			{
				ans2 = i;
				maxB2 = b[i];
			}			
		}
	}
	if(ans != -1)return ans;
	return ans2;
}

void simulate()
{
	while(1)
	{
		int m = get_next();
		if(m == -1)return;
		steps++;
		if(step[m] == 1)
		{
			stars++;
			step[m]++;
		}
		else
		{
			if(stars >= b[m])
			{
				stars += 2;
				step[m] = 2;
			}
			else
			{
				stars++;
				step[m] = 1;
			}
		}
	}
}

int main()
{
//	freopen ("in.txt", "rt", stdin);
//	freopen ("out.txt", "wt", stdout);
	int T;cin >> T;
	int c = 0;
while(c < T)
{
	c++;
	memset(step, 0, sizeof step);
	cin >> n;
	REP(i, n)
		cin >> a[i] >> b[i];
	stars = 0;
	steps = 0;
	simulate();
	REP(i, n)
		if(step[i] < 2)
			steps = -1;
	if(steps == -1)
		printf("Case #%d: Too Bad\n", c);
	else
		printf("Case #%d: %d\n", c, steps);
	
}
//system("pause");
	return 0;
}
