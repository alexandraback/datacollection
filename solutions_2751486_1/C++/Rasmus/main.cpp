#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:16777216")
#include <algorithm>
#include <numeric>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <stdio.h>
#include <stack>
#include <time.h>

using namespace std;

#define FOR(i,n) for (int i=0; i<n; ++i)
#define FORE(i,n) for (int i=0; i<=n; ++i)
#define REP(i,a,b) for (int i=a; i<b; ++i)
#define REPE(i,a,b) for (int i=a; i<=b; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define mp make_pair
#define pb push_back
#define INF (1e9)

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long int LL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VI> VVI;
const double pi = acos(-1.0);
const int inf =(int) 1e9;

const double eps = 1e-4;
const int ss=(int)1e6+3;
const int base=inf;

bool pred (const pair<PII,int>& i, const pair<PII,int>& j) 
{
	if (i.first.first == j.first.first) {
		return j.first.second<i.first.second;
	} else {
		return i.first.first<j.first.first;
	}
}

char a[5] = {'a','e','i','o','u'};

int main()
{
#ifdef _DEBUG
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
	//freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	FOR(tt,t) {
		printf("Case #%d: ",tt+1);
		string s;
		int n;
		cin.get();
		getline(cin,s,' ');
		scanf("%d",&n);
		int sz = s.size();
		int now = 0;
		int pr = 0;
		LL res = 0;
		FOR(i,sz) {
			bool t = true;
			FOR(j,5) {
				if (s[i] == a[j]) {
					t = false;
					break;
				}
			}
			if (t) {
				++now;
				if (now >= n) {
					LL right = sz-i-1;
					LL left = i-n+1-pr;
					res += 1 + left + right;
					res += left*right;
					pr = i-n+1+1;
				}
			} else {
				now = 0;
			}
		}
		printf("%lld\n",res);
	}
#ifdef _DEBUG
    fprintf(stderr, "Time: %.2lf sec\n", (clock()*1./CLOCKS_PER_SEC));
#else
	//fprintf(stderr, "Time: %.2lf sec\n", (clock()*1./CLOCKS_PER_SEC));
#endif

    return 0;
}

