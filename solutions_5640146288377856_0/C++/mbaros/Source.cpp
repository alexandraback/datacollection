#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>
using namespace std;

#define inf 2147483647
#define eps 0.0000000001
#define e  2.718281828459
#define pi 3.1415926535897932
#define mod 1000000007

#define LL long long
#define ULL unsigned long long
#define LD long double
#define ULD unsigned long double

const int N = 100005;

// printf("Case #%d: ",T)
//	srand(time(NULL));
//	cout<<fixed<<setprecision(3)<<"\nExecution time="<<clock()/1000.0<<endl;
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

int n, m, i, j, k, q, s, w, v, ans;
int T;

int main()
{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	cin >> w;
	while (w--)
	{
		T++; ans = 0;
		cin >> n >> m >> s;
		ans += (n - 1)*(m / s);
		ans += m / s;
		if (m%s != 0)
			ans++;
			ans += s-1;
		printf("Case #%d: %d\n", T, ans);
	}
	return 0;
}