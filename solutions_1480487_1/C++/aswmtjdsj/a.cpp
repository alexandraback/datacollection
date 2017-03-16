#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <list>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>
using namespace std;

#define len(x) (x).size()
#define PB push_back
#define MP make_pair
#define FORALL(i, a, n, c) for(int i = (a);i < (n);i += c)
#define FOR(i, a, b) FORALL(i, a, b, 1)
#define rep(i, n) FOR(i, 0, n)
#define TYPE int

typedef long long int64;
typedef pair<TYPE,TYPE> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef set <int> si;
typedef vi::iterator vip;

pii operator - (const pii &a)
{
	return pii(-a.first,-a.second);
}
pii operator + (const pii &a,const pii &b)
{
	return pii(a.first+b.first, a.second+b.second);
}
pii operator - (const pii &a, const pii &b)
{
	return a + (-b);
}

const int inf = ~0u >> 1;
const long double pi = acos(-1.0);
const long double eps = 1e-15;
int sgn(long double x)
{
	return fabs(x) < eps ? 0:x < -eps?-1:1;
}
int CASE;
int n;
#define maxn 205
long double num[maxn];
long double sum;
long double ans[maxn];
int main()
{
	cin >> CASE;
	for(int i = 1;i <= CASE;i++)
	{
		cout << "Case #" << i << ": ";
		cin >> n;
		sum = 0;
		for(int j = 0;j < n;j++)
		{
			cin >> num[j];
			sum += num[j];
		}
		for(int j = 0;j < n;j++)
		{
			long double l = 0.0, r = 1.0, mid;
			while((r - l) > eps)
			{
				mid = (l + r) / 2.0;
				long double temp = num[j] + sum * mid;
				bool flag = true;
				long double least = 1.0;
				for(int k = 0;k < n;k++)
				{
					long double what = temp - num[k];
					if(what < 0)
						what = 0;
					long double fuck = what / sum;
					least -= fuck;
				}
				if(sgn(least) > 0)
					flag = false;
				if(flag)
					r = mid;
				else
					l = mid;
			}
			ans[j] = l;
		}
		for(int j = 0;j < n;j++)
			printf("%.6lf%c",(double)ans[j]*100.0,j==n-1?'\n':' ');
	}
}
