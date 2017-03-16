#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;

typedef vector<int> VI;

double a[15], t[3], x[3];
double des;
int n, m;

void Process(double A){
	double res;
	if (n == 1){res = sqrt(2.0*des/A); printf("%.7lf\n", res); return;}
	double v = (x[1]-x[0])/t[1];
	double delta = 4*v*v+8*A*x[0];
	double meettime = (2.0*v+sqrt(delta))/(2.0*A);
	double pos = 0.5*A*meettime*meettime;
	if (pos >= des) res = sqrt(2.0*des/A);
	else res = meettime + (des-pos)/v;
	printf("%.7lf\n", res);
}

void Solve(){
	scanf("%lf %d %d", &des, &n, &m);
	for(int i = 0; i < n; i++) scanf("%lf %lf", &t[i], &x[i]);
	for(int i = 0; i < m; i++) scanf("%lf", &a[i]);
	for(int i = 0; i < m; i++)
		Process(a[i]);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int ntest;
	cin >> ntest;
	for(int test = 1; test <= ntest; test++){
		printf("Case #%d:\n", test);
		Solve();
	}

	return 0;
}
