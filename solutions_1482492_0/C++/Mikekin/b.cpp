#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

const double eps = 1e-9;
struct data
{
	double pos, tim;
};

int tt, n, m;
data a[10];
double len, ded, ans, tmp;

int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin >> tt;
	for (int t = 1; t <= tt; t++) {
		cin >> len >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i].tim >> a[i].pos;
		}
		if (a[0].pos - len > -eps) n = 1;
		printf("Case #%d:\n", t);
		for (int i = 0; i < m; i++) {
			cin >> ded;
			if (n == 1) {
				ans = 2 * len / ded;
				ans = sqrt(ans);
				printf("%.8lf\n", ans);
			} else {
				ans = 2 * len / ded;
				ans = sqrt(ans);
				tmp = a[0].tim + (len - a[0].pos) / (a[1].pos - a[0].pos) * (a[1].tim-a[0].tim);
				ans = max(ans , tmp);
				printf("%.8lf\n", ans);
			}
		} 
	}
	return 0;
}

