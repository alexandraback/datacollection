#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

const int q[8][8] = {{0,1,2,3,4,5,6,7},{1,0,3,2,5,4,7,6},
	{2,3,1,0,6,7,5,4},{3,2,0,1,7,6,4,5},
	{4,5,7,6,1,0,2,3},{5,4,6,7,0,1,3,2},
	{6,7,4,5,3,2,1,0},{7,6,5,4,2,3,0,1}};
int t, l;
ll x;
string s;

int pot(int a, ll b) {
	int ret = 0;
	while (b>0) {
		if (b%2 != 0) ret = q[ret][a];
		a = q[a][a];
		b /= 2;
	}
	return ret;
}

int main() {
	cin >> t;
	for (int i=1;i<=t;i++) {
		cin >> l >> x;
		int tot = 0;
		bool beg = false;
		bool mid = false;
		cin >> s;
		for (int j=0; j<l;j++) {
			if (s[j] == 'i') tot = q[tot][2];
			else if (s[j] == 'j') tot = q[tot][4];
			else tot = q[tot][6];
			if (beg) {
				if (tot == 6) mid = true;
			} else {
				if (tot == 2) beg = true;
			}
		}
		if (pot(tot,x) != 1) {
			cout << "Case #" << i << ": NO\n";
			continue;
		}
		int k = 4;
		if (x-1 < 4) k = x-1;
		for (ll j=0;j<k*l;j++) {
			if (s[j%l] == 'i') tot = q[tot][2];
			else if (s[j%l] == 'j') tot = q[tot][4];
			else tot = q[tot][6];
			if (beg) {
				if (tot == 6) {
					mid = true;
					break;
				}
			} else {
				if (tot == 2) beg = true;
			}
		}
		cout << "Case #" << i << ": ";
		if (mid) cout << "YES\n";
		else cout << "NO\n";
	}
}
