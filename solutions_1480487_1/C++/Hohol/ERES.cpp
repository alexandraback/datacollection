#pragma comment(linker,"/STACK:300000000")
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4800)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <iomanip>
#include <memory.h>
#include <cstdio>
#include <sstream>
#include <deque>
#include <bitset>
#include <numeric>
#include <ctime>
#include <queue>

using namespace std;

#define show(x) cout << #x << " = " << (x) << endl;
#define fori(i,n) for(int i = 0; i < (n); i++)
#define forab(i,a,b) for(int i = (a); i <= (b); i++)
#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()
const double pi = 3.1415926535897932384626433832795;
template<class T> T abs(const T &a) { return a >= 0 ? a : -a; };
template<class T> T sqr(const T &x) { return x * x; }
typedef pair<int,int> ii;
typedef long long ll;
///////////////////////////////////////

vector<int> a;
int n;
int sum;

bool can(int k, double val)
{
	double psum = 0;
	fori(i,n)
		if(i != k)
		{
			double x = max((a[k]+sum*val-a[i])/sum,0.0);
			psum += x;
		}
	return psum > 1-val;
}

double f(int k)
{
	double l = 0, r = 1;
	fori(_,100)
	{
		double mid = (l+r)/2;
		if(can(k,mid))
			r = mid;
		else
			l = mid;
	}
	return l;
}

void solve()
{
	cin >> n;
	a.resize(n);
	fori(i,n)
		cin >> a[i];
	sum = accumulate(all(a),0);
	cout.setf(ios::fixed);
	cout.precision(9);
	fori(i,n)
		cout << ' ' << f(i)*100;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
	int testCnt;
	cin >> testCnt;
	for(int testNo = 1; testNo <= testCnt; testNo++)
	{
		cout << "Case #" << testNo << ':';
		solve();
		cout << endl;
	}
}