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


int solve() {
	int a, b, res = 0;
	cin >> a >> b;
	
	for (int x = a; x <= b; x++) {
		int ten = 1;
		while (ten * 10 <= x) ten *= 10;
		int y = x % ten * 10 + x / ten;
		while (y != x) {
			if (y > x && y >= a && y <= b)
				res++;
			y = y % ten * 10 + y / ten;
		}
	}
	
	return res;
}

int main()
{
	#ifndef ONLINE_JUDGE 
	freopen("input.txt","rt",stdin); freopen("output.txt","wt",stdout); 
	#endif
	int TC;
	scanf("%d", &TC);
	rept(tc, TC) {
		printf("Case #%d: %d\n", tc + 1, solve());
	}
	return 0;
}
