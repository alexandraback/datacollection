//============================================================================
// Name        : Kingdom.cpp
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
vector<PII> v;
vector<int> cl;
int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int T;
	scanf("%d", &T);
	FOR(ca,1,T) {
		int n;
		scanf("%d", &n);
		v.resize(n);
		cl.resize(n);
		REP(i,n)
			scanf("%d %d", &v[i].first, &v[i].second), cl[i] = 0;

		int cur(0), cnt(0), ans(0);
		while (1) {
			bool ok(0);
			REP(i,n)
				if (cl[i]!=1 && v[i].second <= cur) {
					cur +=cl[i]==0?2:1;
					++cnt;
					++ans;
					ok = 1;
					cl[i] = 1;
					break;
				}
			if (!ok)
				REP(i,n)
					if (cl[i]==0 && v[i].first<= cur) {
						cur ++;
						++ans;
						ok = 1;
						cl[i] = -1;
						break;
					}
			if (!ok) break;
		}
		printf("Case #%d: ",ca);
		if (cnt==n)printf("%d\n",ans);
		else puts("Too Bad");
	}
	return 0;
}
