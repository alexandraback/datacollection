#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <deque>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <sstream>

#define For(i,a,n) for(int i =a ; i < n ; ++i )
#define all(x) (x).begin(),(x).end()
#define n(x) (int)(x).size()
#define pb(x) push_back(x)
#define double long double

using namespace std;
const int maxn = 210;
const double eps = 1e-7;
typedef pair<int,int> pii;
double s[maxn];
double x;
int n;
int t;

int now;


bool check(double nu)
{
	double mys=s[now]+(nu*x)/100;
	double rem = 100-nu;
	bool bo = false;
	For(i,0,n)
	{
		if(now == i)
			continue;
		if(mys > s[i])
		{
			bo = true;
			double cost = mys-s[i];
			double per = (100*cost)/x;
			rem-=per;
		}
	}
	if(!bo)
		return false;
	if(rem > eps)
		return false;
	return true;
}

double bs(double b,double e)
{
//	cerr << b << " " << e << endl;
	if(e-b < eps)
		return b;
	double mid = (b+e)/2;
	if(check(mid))
		return bs(b,mid);
	else
		return bs(mid,e);
}

int main()
{
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(6) ;
	cin >> t;
	For(it,0,t)
	{
		cin >> n;
		For(i,0,n)
			cin >> s[i];
		x= 0;
		For(i,0,n)
			x+=s[i];
//		cerr << x << endl; 
		cout << "Case #" << it+1 << ": " ;
		For(i,0,n)
		{
			now = i;
			cout << bs(0,100) << " ";
		}
		cout << endl;
	}
	return 0;
}
