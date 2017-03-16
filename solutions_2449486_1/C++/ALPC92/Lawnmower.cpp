//============================================================================
// Name        : Lawnmower.cpp
// Author      : alpc92
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <math.h>
using namespace std;

#define eps 1e-8
#define inf 0x3fffffff
#define zero(x) (fabs(x)<=eps)
#define FORIT(iter,STL) for (typeof(STL.begin()) iter(STL.begin());iter!=STL.end();++iter)
#define PB push_back
#define MP make_pair
#define REP(iterator,upperbound) for(int iterator(0);iterator<(upperbound);++iterator)
#define FOR(iterator,lowerbound,upperbound) for(int iterator(lowerbound);iterator<=(upperbound);++iterator)
#define FORD(iterator,upperbound,lowerbound) for(int iterator(upperbound);iterator>=(lowerbound);--iterator)
#define SZ(STL) ((int)STL.size())
#define CL(STL) (STL.clear())
#define CL0(array) memset(array,0,(int)sizeof(array))
#define CL1(array) memset(array,-1,(int)sizeof(array))
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
template<typename T>
void chkmax(T a, T &b) {
	if (a > b)
		b = a;
}
template<typename T>
void chkmin(T a, T &b) {
	if (a < b)
		b = a;
}
template<typename T>
T sqr(T a) {
	return a * a;
}
template<typename T>
T gcd(T a, T b) {
	while (b != 0) {
		T c = a;
		a = b;
		b = c % b;
	}
	return a;

}
int n, m, g[200][200];
bool check(int r, int c, int dr, int dc) {
	int cur(g[r][c]);
	int t1(1), t2(1);
	int tr(r), tc(c);
	while (g[r][c]) {
		if (g[r][c] > cur)
			t1 = 0;
		r += dr;
		c += dc;

	}
	while (g[tr][tc]) {
		if (g[tr][tc] > cur)
			t2 = 0;
		tr -= dr;
		tc -= dc;
	}
	return t1&&t2;
}
bool work() {
	FOR(i,1,n)
		FOR(j,1,m)
			if (!(check(i,j,1,0)||check(i,j,0,1)))return 0;
	return 1;
}
int main() {
	int t;
	freopen("/Users/yunfengzhou/Downloads/B-large.in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> t;
	int num;
	FOR(ca,1,t)
	{
		num = 0;
		printf("Case #%d: ", ca);
		CL0(g);
		cin >> n >> m;
		FOR(i,1,n)
			FOR(j,1,m)
				cin >> g[i][j];
		cout << (work() ? "YES" : "NO") << endl;
	}
	return 0;
}
