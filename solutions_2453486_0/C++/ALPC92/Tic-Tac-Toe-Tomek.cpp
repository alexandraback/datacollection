//============================================================================
// Name        : Tic-Tac-Toe-Tomek.cpp
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
char g[4][4];
bool check(char C) {
	REP(i,4)
	{
		bool r(1), c(1);
		REP(j,4)
		{ //	cout<<r<<" "<<c<<" "<<i<<" "<<j<<endl;
			if (g[i][j] != C && g[i][j] != 'T')
				r = 0;
			if (g[j][i] != C && g[j][i] != 'T')
				c = 0;
		}
		if (r || c)
			return 1;
	}
	bool r(1), c(1);
	REP(j,4)
	{ //	cout<<r<<" "<<c<<" "<<i<<" "<<j<<endl;
		if (g[j][j] != C && g[j][j] != 'T')
			r = 0;
		if (g[j][4-j-1] != C && g[j][4-j-1] != 'T')
			c = 0;
	}
	if (r || c)
		return 1;
	return 0;
}
int main() {
	int t;
	freopen("/Users/yunfengzhou/Downloads/A-small-attempt0.in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin >> t;
	int num;
	FOR(ca,1,t)
	{
		num = 0;
		printf("Case #%d: ", ca);
		REP(i,4)
		{
			scanf("%s", g[i]);
			REP(j,4)
				num += g[i][j] == '.';
		}
		if (check('O'))
			puts("O won");
		else if (check('X'))
			puts("X won");
		else if (num == 0)
			puts("Draw");
		else
			puts("Game has not completed");
	}
	return 0;
}
