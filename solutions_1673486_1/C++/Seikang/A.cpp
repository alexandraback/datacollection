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
const int MAXN = (int)1e5 + 5;
const int mod = (int)1e9;
const double eps = 1e-9;
const double pi = acos(-1);

double prob[MAXN];
double corr[MAXN];

int n, p;
double calculate()
{
	corr[0] = 1;
	REP(i, p)
		corr[i + 1] = corr[i] * prob[i];
	double ans = n + 2;
//	cout << "Start "<< ans << endl;
	REP(i, p + 1)
	{
		double temp = (2 * i + n - p + 1) * corr[p - i] + (1 - corr[p - i]) * (2 * i + n - p + 1 + n + 1);
//		cout << "Temp " << temp << endl;
		ans = min(ans, temp);
	}
//	cout << "Ans " << ans << endl;
	return ans;
}

int main()
{
//	freopen ("in.txt", "rt", stdin);
//	freopen ("out.txt", "wt", stdout);
	int T, c = 0;cin >> T;
while(c < T)
{
	c++;
	cin >> p >> n;
	REP(i, p)
		cin >> prob[i];
	printf("Case #%d: %.6lf\n", c, calculate());
}
//system("pause");
	return 0;
}
