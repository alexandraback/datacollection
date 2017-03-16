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

int main()
{
	#ifndef ONLINE_JUDGE 
	freopen("input.txt","rt",stdin); freopen("output.txt","wt",stdout); 
	#endif
	string a[] = {
		"ejp mysljylc kd kxveddknmc re jsicpdrysi",
		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"de kr kd eoya kw aej tysr re ujdr lkgc jv"
	};
	string b[] = {
		"our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up"
	};
	string A, B;
	rept(i, 3) A += a[i], B += b[i];
	map<char, char> M;
	rept(i, L(A))
		M[A[i]] = B[i];
	M['q'] = 'z';
	M['z'] = 'q';
	int n;
	scanf("%d", &n);
	char s[1 << 10];
	gets(s);
	rept(i, n) {
		gets(s);
		int m = strlen(s);
		rept(i, m)
			s[i] = M[s[i]];
		printf("Case #%d: ", i + 1); puts(s);
	}
	return 0;
}
