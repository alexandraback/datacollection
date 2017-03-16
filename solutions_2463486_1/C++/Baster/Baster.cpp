#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<iomanip>
#include<ctime>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

li a, b;
li v[] = {1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,11011,11111,11211,20002,20102,100001,101101,110011,111111,200002,1000001,1001001,1002001,1010101,1011101,1012101,1100011,1101011,1102011,1110111,1111111,2000002,2001002};

void solve(int test)
{
	int ans = 0;
	printf("Case #%d: ", test);
	forn (i, 39)
		if(v[i] * v[i] >= a && v[i] * v[i] <= b)
			ans++;
	printf("%d\n", ans);
}

bool read()
{
	int t;
	cin >> t;
	forn (i, t)
	{
		scanf("%I64d%I64d", &a, &b);
		solve(i + 1);
	}
	return true;
}

int main()
{
	freopen ("C-large-1.in", "r", stdin);
	freopen ("output.txt", "w", stdout);
	read();
	return 0;
}