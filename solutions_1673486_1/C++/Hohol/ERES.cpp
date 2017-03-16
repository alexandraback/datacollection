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

int a, b;
vector<double> p;

double solve()
{
	cin >> a >> b;
	p.resize(a);
	fori(i,a)
		cin >> p[i];
	double ans = 1+b+1;
	double pp = 1;
	for(int i = 0; i <= a; i++)
	{
		if(i != 0)
			pp *= p[i-1];
		double g = (a-i+a-i+b-a+1)*pp;
		double bb = (a-i+a-i+1+b-a+b+1)*(1-pp);
		ans = min(ans,g+bb);
	}

	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
	int testCount;
	cin >> testCount;
	for(int testNo = 1; testNo <= testCount; testNo++)
	{
		cout.setf(ios::fixed);
		cout.precision(9);
		double ans = solve();
		cout << "Case #" << testNo << ": " << ans << endl;
	}
}