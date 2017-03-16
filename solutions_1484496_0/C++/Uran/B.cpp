#pragma region predefinition
#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <stack>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <memory>
using namespace std;
#define pb push_back
#define INF 1000000000
#define L(s) (int)((s).size())
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define rep(i, n) FOR(i, 1, (n))
#define rept(i, n) FOR(i, 0, (n)-1)
#define C(a) memset((a), 0, sizeof(a))
#define ll long long
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define VI vector<int>
#define ppb pop_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
#define sqr(a) (a)*(a)
#define D(a,b) sqrt(((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y))
#define pi 3.1415926535897932384626433832795028841971
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define rnd() ((rand() << 16) ^ rand())
#pragma endregion
//#define x first
//#define y second

vector<int> v[2000003];

int main()
{ 
	freopen("input.txt","rt",stdin); freopen("output.txt","wt",stdout); 
	int TC;
	scanf("%d", &TC);
	rept(tc, TC) {
		rept(i, 2000003) v[i].clear();
		int n;
		scanf("%d", &n);
		vector<int> s(n);
		rept(i, n) scanf("%d", &s[i]);
		int resa = -1, resb = -1;
		rept(mask, 1 << n) {
			int sum = 0;
			rept(i, n)
				if (mask & 1 << i)
					sum += s[i];
			rept(i, L(v[sum]))
				if ((v[sum][i] & mask) == 0) {
					resa = mask;
					resb = v[sum][i];
					mask = INF;
					break;
				}
			v[sum].pb(mask);
		}

		printf("Case #%d:\n", tc + 1);
		if (resa == -1) {
			puts("Impossible");
			continue;
		}
		VI a, b;
		rept(i, n)
			if (resa & 1 << i)
				a.pb(i);
		rept(i, n)
			if (resb & 1 << i)
				b.pb(i);
		rept(i, L(a)) {
			if (i) printf(" ");
			printf("%d", s[a[i]]);
		}
		puts("");
		rept(i, L(b)) {
			if (i) printf(" ");
			printf("%d", s[b[i]]);
		}
		puts("");
	}
	return 0;
}
