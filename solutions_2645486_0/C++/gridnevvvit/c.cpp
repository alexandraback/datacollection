#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment(linker, "/STACK:200000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <complex>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <fstream>
#include <iostream>
#include <map>
#include <memory.h>
#include <numeric>
#include <iomanip>
#include <queue>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

#define pb push_back
#define mp make_pair
#define mset(mas,val) memset(mas,val,sizeof(mas))
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<int(b); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
	
const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

int v[30], E, R, N;
int dp[100][100];
int calc(int have, int pos) {
	int &ans = dp[have][pos];
	if (ans != -1)
		return ans;
	if (pos == N) {
		return ans = 0;
	}
	ans = 0;
	for(int i = 0; i <= have; i++){
		ans = max(ans, calc(min(E,have-i+R),pos+1) + i*v[pos]);
	}
	return ans;
}
int main(){
#ifdef gridnevvvit
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
#endif
	 int T, testcount = 1;
	 scanf("%d", &T);
	 while (T--) {
		 printf("Case #%d: ", testcount++);
		 mset(dp, -1);
		 cin >> E >> R >> N;
		 forn(i,N) {
			cin >> v[i];
		 }
		 cout << calc(E, 0) <<'\n';
	 }
}