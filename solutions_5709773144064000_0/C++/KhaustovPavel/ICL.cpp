#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <algorithm>
#include <cstdio>
#include <ctime>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <iostream>
#include <cmath>
#include <sstream>
#include <complex>
#include <memory.h>

using namespace std;

#pragma comment(linker, "/STACK:128000000")

typedef long long int64;
typedef unsigned long long uint64;

#define y1 _dsfkjdsfksdj
#define y0 _sfsdkfdop

typedef unsigned uint;
typedef vector<int64> vi64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int64,int64> pii64;
typedef pair<int,pii> piii;
typedef pair<pii,pii> piiii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;
typedef pair<int,string> pis;

int n;
double c, f, x;

int main()
{	
	freopen("b_1204.txt", "r", stdin); freopen("output.txt", "w", stdout);

	cin >> n;
	for (int tn = 1; tn <= n; ++tn)
	{
		cin >> c >> f >> x;
		double res = x / 2.0;
		double y = 2.0;
		double t = 0.0;
		for (int i = 0; i < 1000000; ++i)
		{
			t += c / y;
			y += f;
			double t2 = t + (x / y);
			res = min(res, t2);
		}
		cout.precision(15);
		cout << "Case #" << tn << ": ";
		cout << fixed << res << endl;
	}
	
    return 0;
}