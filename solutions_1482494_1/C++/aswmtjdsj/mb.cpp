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
const double eps = 1e-8;
const double pi = acos(-1.0);
int sgn(double x)
{
	return fabs(x) < eps ? 0:x < -eps?-1:1;
}
int n;
#define maxn 1005
struct daan
{
	int a, b, num;
	daan(){}
	daan(int _a,int _b):a(_a),b(_b){}
} d[maxn];
bool cmp(daan x,daan y)
{
	return x.b < y.b;
}
int main()
{
	int t;
	cin >> t;
	for(int cas = 1;cas <= t;cas++)
	{
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
		{
			cin >> d[i].a >> d[i].b;
			d[i].num = 2;
		}
		sort(d,d + n, cmp);
		int cnt = 0;
		int zong = 0;
		bool mark = true;
		for(int i = 0;i < n;i++)
		{
			//cout << i << ' ' << d[i].b << endl;
			//cout << cnt << " haha " << d[i].num << endl;
			while(cnt < d[i].b)
			{
				bool flag = false;
			//	cout << cnt << " fuck " << endl;
				for(int j = n - 1;j >= 0;j--)
				{
					if(cnt >= d[j].a && d[j].num == 2)
					{
						//cout << cnt << ' ' << d[i].a << endl;
						cnt += 1;
						d[j].num = 1;
						zong ++;
						flag = true;
						break;
					}
				}
				if(!flag)
					break;
			}
			if(cnt >= d[i].b)
			{
				cnt += d[i].num;
				d[i].num = 0;
				zong ++;
			}
			else
			{
				mark = false;
				break;
			}
		}
		printf("Case #%d: ",cas);
		if(mark)
			printf("%d\n",zong);
		else
			puts("Too Bad");
	}
}
