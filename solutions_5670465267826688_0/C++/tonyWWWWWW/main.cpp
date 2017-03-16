#include <iostream>

using namespace std;

typedef struct num{
	int symb; // 1 -1
	char val; // '1' 'i' 'j' 'k'
};

num m[4][4] = 
{ num{ 1, '1' }, num{ 1, 'i' }, num{ 1, 'j' }, num{ 1, 'k' },
num{ 1, 'i' }, num{ -1, '1' }, num{ 1, 'k' }, num{ -1, 'j' },
num{ 1, 'j' }, num{ -1, 'k' }, num{ -1, '1' }, num{ 1, 'i' },
num{ 1, 'k' }, num{ 1, 'j' }, num{ -1, 'i' }, num{ -1, '1' } };

num operator * (num l, num r) {
	num ans;
	int row = l.val == '1' ? 0 : l.val - 'h';
	int col = r.val == '1' ? 0 : r.val - 'h';
	ans.symb = m[row][col].symb * l.symb * r.symb;
	ans.val = m[row][col].val;
	return ans;
}

num operator ^ (num a, long long n) {
	num ans;
	if (a.val == '1') {
		ans.val = '1';
		ans.symb = n % 2 == 0 ? 1 : a.symb;
	}
	else {
		ans.val = n % 2 == 0 ? '1' : a.val;
		ans.symb = n % 2 == 0 ? 1 : a.symb;
		if (n % 4 == 2 || n % 4 == 3) {
			ans.symb = ans.symb * (-1);
		}
	}
	return ans;
}

typedef struct bigIdx {
	long long n; // 0,1,2,3
	int idx;
};

int main() {
	freopen("a.txt", "r", stdin);
	freopen("b.txt", "w", stdout);
	int T = 0;
	cin >> T;
	int t = 0;
	while (t < T) {
		if (t != 0) cout << endl;
		int l;
		long long x;
		cin >> l >> x;
		char *s = new char[l];
		cin >> s;
		int ans = -1; // 0:NO 1:YES
		num t_m = { 1, '1' };
		for (int i = 0; i < l; i++) {
			num new_num = { 1, s[i] };
			t_m = (t_m * new_num);
		}
		t_m = (t_m ^ x);
		if (t_m.symb != -1 || t_m.val != '1') {
			ans = 0;
		}
		else {
			num l_m = { 1, '1' };
			num r_m = { 1, '1' };
			bigIdx l_idx = { x, 0 };
			bigIdx r_idx = { x, 0 };
			for (int i = 0; i < l * 4; i++) {
				num new_num = { 1, s[i % l] };
				l_m = (l_m  * new_num);
				if (l_m.symb == 1 && l_m.val == 'i') {
					l_idx.n = (i + 1) / l;
					l_idx.idx = ((i + 1) % l) - 1;
					break;
				}
			}
			for (int j = 0; j < l * 4; j++) {
				num new_num = { 1, s[l - 1 - (j % l)] };
				r_m = (new_num * r_m);
				if (r_m.symb == 1 && r_m.val == 'k') {
					r_idx.n = (j + 1) / l;
					r_idx.idx = ((j + 1) % l) - 1;
					break;
				}
			}
			if (r_idx.n + l_idx.n + (r_idx.idx + l_idx.idx + 2) / l >= x) {
				ans = 0;
			}
			else {
				ans = 1;
			}
		}
		cout << "Case #" << t + 1 << ": " << (ans == 0 ? "NO" : "YES");
		t++;
	}
}