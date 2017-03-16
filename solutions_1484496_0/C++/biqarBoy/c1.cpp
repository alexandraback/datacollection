#pragma warning ( disable : 4786 )

#include <iostream>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>

#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
using namespace std;

//#define _rep( i, a, b, x ) for( __typeof(b) i = ( a ); i <= ( b ); i += x )
#define _rep( i, a, b, x ) for( i = ( a ); i <= ( b ); i += x )
#define rep( i, n ) _rep( i, 0, n - 1, 1 )

#define ff first
#define ss second

#define pii pair< int, int >
#define psi pair< string, int >

#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

#define set(p) memset(p, -1, sizeof(p))
#define clr(p) memset(p, 0, sizeof(p))

//typedef long long i64;
//typedef __int64 i64;
typedef long double ld;

//const double pi = (2.0*acos(0.0));
const double pi = acos(-1.0);
const double eps = 1e-9;
const int inf = (1<<28);
const int MAX = 25;

int n, a[MAX], flg[MAX];

bool isPos(int sum) {
	//printf("->>%d\n", sum);
	int i, j, k;
	int tmp, ss;
	bool ff;

	for(i=1; i<(1<<n); i++) {
		ss = 0;
		ff = true;
		tmp = 1;
		for(j=0; j<n; j++) {
			if(i&tmp) {
				if(flg[j]) {
					ff = false;
					break;
				}
				//flg[j] = 1;
				ss += a[j];
			}
			tmp = (tmp << 1);
		}
		if(!ff) continue;
		if(sum == ss) return true;
	}
	return false;
}

void printFunc(int sum) {
	int i, j, k;
	int tmp, ss;
	bool ff;

	//printf("->>%d\n", sum);
	for(i=1; i<(1<<n); i++) {
		tmp = 1;
		ss = 0;
		ff = true;
		for(j=0; j<n; j++) {
			if(i&tmp) {
				if(flg[j]) {
					ff = false;
					break;
				}
				//flg[j] = 1;
				ss += a[j];
			}
			tmp = (tmp << 1);
		}
		if(!ff) continue;
		if(sum == ss) {
			//printf("ekhane achi! :P\n");
			k = 0;
			tmp = 1;
			for(j=0; j<n; j++) {
				if(i&tmp) {
					if(k) printf(" ");
					printf("%d", a[j]);
					k = 1;
					flg[j] = 1;
				}
				tmp = (tmp << 1);
			}
			printf("\n");
		}
	}
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int i, j, k;
	int test, t = 0, kase=0;
	int tmp, sum;
	bool ff;

	scanf("%d", &test);
	while(test--) {
		scanf("%d", &n);
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}

		ff = false;
		for(i=1; i<(1<<n); i++) {
			memset(flg, 0, sizeof(flg));
			tmp = 1;
			sum = 0;
			for(j=0; j<n; j++) {
				if(i&tmp) {
					flg[j] = 1;
					sum += a[j];
				}
				tmp = (tmp << 1);
			}
			//if(i==3) printf(">>%d\n", sum);
			if(isPos(sum)) {
				ff = true;
				break;
			}
		}
		//printf("->%d %d\n", sum, i);
		//continue;

		printf("Case #%d:\n", ++t);
		if(ff) {
			//printf("ekhane:P\n");
			//continue;

			k = 0;
			for(j=0; j<n; j++) {
				if(flg[j]) {
					if(k) printf(" ");
					printf("%d", a[j]);
					k = 1;
				}
				tmp = (tmp << 1);
			}
			printf("\n");
			//continue;
			printFunc(sum);
		}
		else {
			printf("Impossible\n");
		}
	}
	return 0;
}
