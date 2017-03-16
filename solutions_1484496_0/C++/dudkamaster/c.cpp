#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment(linker, "/STACK:200000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
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
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<=int(b); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
	int t;
	cin >> t;
	forn(tc,t){
		int n;
		cin >> n;
		vector <int> a(n);
		int sum = 0;
		forn(i,n){
			cin >> a[i];
			sum += a[i];
		}
		vector <int> s(sum+1,-1);
		bool ok = false;
		printf("Case #%d:\n", tc+1);		
		forn(i,(1<<n)){
			int tsum = 0;
			forn(j,n)
				if ((1<<j) & i)
					tsum += a[j];
			if (s[tsum]!=-1){
				ok = true;
				forn(j,n)
					if ((1<<j) & s[tsum])
						printf("%d ", a[j]);
				puts("");
				forn(j,n)
					if ((1<<j) & i)
						printf("%d ", a[j]);
				puts("");
				break;
			}
			if (i!=0)
				s[tsum] = i;
		}
		if (!ok)
			puts("Impossible");
	}
	return 0;
}