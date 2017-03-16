//I hate this town, bacause it's too filled with memories I'd rather forget.
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

//kAc
const double pi = acos(-1.0), eps = 1e-9;
const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
const int MO = (int)(1e9 + 7);

//Two becomes one,and it through all eternity.
#define ALL(x) x.begin(), x.end()
#define fr(x, E) for (__typeof(E.begin()) x = E.begin(); x != E.end(); x++)
#define MP make_pair
#define PB push_back
#define FR first
#define SC second
#define ERR cerr << "ERROR" << endl
#define LL long long
#define LD long double
#define PII pair<int, int>
#define PIII pair<PII, int>
#define PDI pair<double, int>
#define PID pair<int, double>
#define SZ(a) (int)((a).size())
#define VEC vector
#define STR string
#define ISS istringstream
#define OSS ostringstream
#define CLR(a, b) memset(a, b, sizeof(a))
#define gmin(a, b) { if (b < a) a = b; }
#define gmax(a, b) { if (b > a) a = b; }

using namespace std;
struct Tq{
	int sig, num;
	Tq() { }
	Tq(char c)
	{
		sig = 0;
		switch(c){
			case 'i' : num = 1; break;
			case 'j' : num = 2; break;
			case 'k' : num = 3; break;
		}
	}
	Tq operator + (const Tq & a)
	{
		Tq ret;
		ret.sig = sig ^ a.sig;
		if (num == 0) ret.num = a.num;
		if (a.num == 0) ret.num = num;
		if (num == a.num){
			ret.sig = !ret.sig;
			ret.num = 0;
		}
		if (num == 1)
			if (a.num == 2)
				ret.num = 3;
			else if (a.num == 3){
				ret.num = 2;
				ret.sig = !ret.sig;
			}
		if (num == 2){
			if (a.num == 1){
				ret.num = 3;
				ret.sig = !ret.sig;
			}
			else if (a.num == 3)
				ret.num = 1;
		}
		if (num == 3){
			if (a.num == 1)
				ret.num = 2;
			else if (a.num == 2){
				ret.sig = !ret.sig;
				ret.num = 1;
			}
		}
		return ret;
	}
	operator int ()
	{
		return 4 * sig + num;
	}
};
Tq get(int x)
{
	Tq ret;
	ret.sig = x / 4;
	ret.num = x % 4;
	return ret;
}
char c[1000001];
int n, m;
int f[1000001][10][10];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("temp.in", "r", stdin); freopen("temp.out", "w", stdout);
#endif
int TestCase; scanf("%d", &TestCase);
for (int ti = 1; ti <= TestCase; ti++){
	printf("Case #%d: ", ti);
	scanf("%d%d", &n, &m);
	scanf(" ");
	scanf("%s", c + 1);
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++)
			c[(i - 1) * n + j] = c[j];
	}
	memset(f, 0, sizeof(f));
	f[0][0][0] = true;
	for (int i = 0; i < n * m; i++)
		for (int j = 0; j < 8; j++)
			for (int k = 0; k <= 2; k++) if (f[i][j][k]){
				Tq now(c[i + 1]);
				if (k == 0 && j == 1){
					f[i + 1][(int)now][1] = true;
				}
				if (k == 1 && j == 2){
					f[i + 1][(int)now][2] = true;
				}
				f[i + 1][(int)(get(j) + now)][k] = true;
			}
	puts(f[n*m][3][2] ? "YES" : "NO");

}    

}
