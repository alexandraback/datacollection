#include <bits/stdc++.h>

using namespace std;

#define ll long long

int t;
/*

int c,d,v;
vector <int> vals;

int solve(int num) {

}
*/
int main() {
	ios::sync_with_stdio(0);
	freopen("A-small-attempt1.in","r",stdin);
	freopen("final.out","w",stdout);
	cin >> t;
	for (int cntt = 1; cntt <= t; cntt++) {
		cout << "Case #" << cntt << ": ";
		//cin >> c >> d >> v;
		//vals.resize(d);
		//for (int i = 0; i < d; i++) {
		//	cin >> vals[i];
		//}
		//sort(vals.begin(),vals.end());
		//int res = 0;
		//cout << solve(1);
		int r,c,w;
		cin >> r >> c >> w;
		int res = 0;
		int avoided = 0;
		while (c >= 2*w) {
			res++;
			c-= w;
		}
		res+= w;
		if (c > w)
			res++;
		cout << res;
		cout << endl;
	}
	return 0;
}
