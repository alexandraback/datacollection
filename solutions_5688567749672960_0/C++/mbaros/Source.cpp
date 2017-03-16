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
#define topcoder classname

const int N = 100005;

//	srand(time(NULL));
//	cout<<fixed<<setprecision(3)<<"\nExecution time="<<clock()/1000.0<<endl;
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

int T;
int n, m, i, j, k, q, s, w, v, ans;
int a[10 * N];

int main()
{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	//  printf("Case #%d: ", ++T);


	for (i = 2; i <= 1000000; i++)
		a[i] = 1000005;
	a[1] = 1;

	for (i = 2; i <= 1000000; i++)
	{
		a[i] = min(a[i], a[i - 1] + 1);

		k = i;
		s = 0;
		while (k > 0)
		{
			s = s * 10 + k % 10;
			k /= 10;
		}
		if (s>i)
			a[s] = min(a[s], a[i]+1);
	}
	cin >> w;
	while (w--)
	{
		cin >> n;
		printf("Case #%d: %d\n", ++T, a[n]);
		//cout << a[n] << 
	}
	return 0;
}


