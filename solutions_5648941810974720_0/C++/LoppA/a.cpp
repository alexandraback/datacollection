#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double E = 2.71828182846;

string s;
int res[20];
int cont[300];

void go () {

	for (int i = 0; i < (int)s.size(); i++) {
		cont[(int)s[i]]++;
	}

	if (cont['Z']) {
		res[0] += cont['Z'];
		cont['E'] -= cont['Z'];
		cont['R'] -= cont['Z'];
		cont['O'] -= cont['Z'];
		cont['Z'] -= cont['Z'];
	}

	if (cont['W']) {
		res[2] += cont['W'];
		cont['T'] -= cont['W'];
		cont['O'] -= cont['W'];
		cont['W'] -= cont['W'];
	}


	if (cont['U']) {
		res[4] += cont['U'];
		cont['F'] -= cont['U'];
		cont['O'] -= cont['U'];
		cont['R'] -= cont['U'];
		cont['U'] -= cont['U'];
	}

	if (cont['X']) {
		res[6] += cont['X'];
		cont['S'] -= cont['X'];
		cont['I'] -= cont['X'];
		cont['X'] -= cont['X'];
	}

	if (cont['G']) {
		res[8] += cont['G'];
		cont['E'] -= cont['G'];
		cont['I'] -= cont['G'];
		cont['H'] -= cont['G'];
		cont['T'] -= cont['G'];
		cont['G'] -= cont['G'];
	}

	res[1] += cont['O'];
	cont['N'] -= cont['O'];
	cont['E'] -= cont['O'];
	cont['O'] -= cont['O'];

	res[3] += cont['H'];
	cont['T'] -= cont['H'];
	cont['R'] -= cont['H'];
	cont['E'] -= cont['H'];
	cont['E'] -= cont['H'];
	cont['H'] -= cont['H'];

	res[5] += cont['F'];
	cont['I'] -= cont['F'];
	cont['V'] -= cont['F'];
	cont['E'] -= cont['F'];
	cont['F'] -= cont['F'];

	res[7] += cont['S'];

	res[9] += cont['I'];
}

void imp () {

	for (int i = 0; i <= 9; i++) {
		while (res[i]) {
			cout << i;
			res[i]--;
		}
	}

}

int main (void) {
	ios_base::sync_with_stdio(false);

	int t;	cin >> t;
	for (int T = 1; T <= t; T++) {
		memset(res, 0, sizeof res);
		memset(cont, 0, sizeof cont);
		cin >> s;
		cout << "Case #" << T << ": ";
		go ();
		imp();
		cout << endl;
	}

	return 0;
}
