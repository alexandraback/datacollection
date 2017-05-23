//============================================================================
// Name        : Password.cpp
// Author      : alpc92
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
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
using namespace std;

#define PB push_back
#define MP make_pair
#define inf 0x3fffffff
#define REP(iterator,upperbound) for(int iterator(0);iterator<(upperbound);++iterator)
#define FOR(iterator,lowerbound,upperbound) for(int iterator(lowerbound);iterator<=(upperbound);++iterator)
#define FORD(iterator,upperbound,lowerbound) for(int iterator(upperbound);iterator>=(lowerbound);--iterator)
#define FORIT(iter,STL) for (typeof(STL.begin()) iter(STL.begin());iter!=STL.end();++iter)
#define SIZE(STL) ((int)STL.size())
#define CLEAR(STL) (STL.clear())
#define CLEAR0(array) memset(array,0,sizeof(array))
#define CLEAR1(array) memset(array,-1,sizeof(array))
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;
#define MAXLOOP 100
#define WORKERNUM 10
#define UPNUM 4
#define DOWNNUM 2
#define PASSWAY 1
template<class T>
inline void chkmax(T &a, T b) {
	if (a < b)
		a = b;
}
template<class T>
inline void chkmin(T &a, T b) {
	if (a > b)
		a = b;
}
vector<double> p;
int main() {
	int A, B;
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int T;
	scanf("%d", &T);
	FOR(ca,1,T) {
		scanf("%d %d", &A, &B);
		p.resize(A);
		REP(i,A)scanf("%lf",&p[i]);
		double ans(B+2),ok(1);
		REP(i,A){
			chkmin(ans,ok*(1+B-i+A-i)+(1-ok)*(2+B-i+A-i+B));
	//		printf("%lf %lf\n",ok*(1+B-i+A-i)+(1-ok)*(2+B-i+A-i+B),ok);
			ok*=p[i];
		}
		chkmin(ans,ok*(1+B-A)+(1-ok)*(B-A+B+2));
		printf("Case #%d: %lf\n",ca,ans);
	}
	return 0;
}
