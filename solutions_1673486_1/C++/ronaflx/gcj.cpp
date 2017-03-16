#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
#include <algorithm>
#include <iterator>
#include <functional>
#include <limits>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <list>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <stdexcept>
#include <utility>
#include <cassert>
#include <complex>
using namespace std;
#define LT(i) ((i) << 1)
#define RT(i) (((i) << 1) | 1)
#define MID(i) ((l[i] + r[i]) >> 1)
#define CC(i, v) memset(i, v, sizeof(i))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
typedef pair<int, int> PII;
template<class T> void string_reader(string s, vector<T>& vec){
	istringstream sin(s);
	copy(istream_iterator<T>(sin), istream_iterator<T>(), back_inserter(vec));
}
const int N = 100000;
const double INF = 100000000;
double p[N], sum[N];

double SUM(int x)
{
	if(x == 0) return 1;
	else return sum[x - 1];
}
double backspace(int times, int n, int m) 
{
	int rest = m - times;
	double res = 0;
	res = (times + 1 + n - rest) + (1 - SUM(rest)) * (n + 1);
	return res;
}
int main()
{
	int t, n, m;
	scanf("%d", &t);
	REP(cas, 0, t)
	{
		scanf("%d %d", &m, &n);
		double res = INF;
		REP(i, 0, m) scanf("%lf", &p[i]);
		REP(i, 0, m) 
		{
			sum[i] = p[i];
			if(i) sum[i] *= sum[i - 1];
		}
		checkmin(res, n + 2.0);
		REP(i, 0, m)
		{
			checkmin(res, backspace(i, n, m));
		}
		printf("Case #%d: %.6lf\n", cas + 1, res);
	}
	return 0;
}
