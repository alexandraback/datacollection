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


int main(){
#ifdef gridnevvvit
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
#endif
	 int T, testcount = 1;
	 scanf("%d", &T);
	 while (T--) {
		 printf("Case #%d:\n", testcount++);
		 int R, N, M, K;
		 cin >> R >> N >> M >> K;
		 for(int iter = 0; iter < R; iter++) {
			 vector < int > products(K);
			 forn(i,K)
				 cin >> products[i];
			 vector < int > answers;
			 for(int i = 222; i <= 555; i++) {
				int tval = i;
				vector < int > digits;
				bool bad = false;
				while(tval) {
					if (!((tval % 10) >= 2 && (tval % 10) <= M))
						bad = true;
					digits.pb(tval%10);
					tval /= 10;
				}
				if (bad) continue;
				vector < int > allsets;
				for(int mask = 0; mask < (1<<N); mask++) {
					int prod = 1;
					forn(i, N) {
						if (mask & (1<<i))
							prod *= digits[i];
					}
					allsets.pb(prod);
				}
				bool ok = true;
				forn(j, sz(products)) {
					bool have = false;
					forn(k, sz(allsets)) {
						if (products[j] == allsets[k])
							have = true;
					}
					ok = ok && have;
				}
				if (ok) {
					answers.pb(i);
				}
			 }
			printf("%d\n", answers[0]);
		 }
	 }
}