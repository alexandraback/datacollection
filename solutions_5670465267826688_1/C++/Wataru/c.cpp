#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;


int l;
long long k;
string s;


class Quat
{
public:
	char val;
	bool sign;

	Quat(char c) {
		sign = false;
		val = -1;
		switch (c) {
		case '1':
			val = 0;
			break;
		case 'i':
			val = 1;
			break;
		case 'j':
			val = 2;
			break;	
		case 'k':
			val = 3;
			break;	
		}
	}

	Quat(char v, bool s) {
		val = v;
		sign = s;
	}

	Quat() {
		val = 0;
		sign = false;
	}

};


bool operator == (const Quat &a, const Quat &b) {
	return a.val == b.val && a.sign == b.sign;
}

Quat operator *(const Quat &a, const Quat &b) {
	bool s;
	int v;
	s = (a.sign != b.sign);
	if (a.val == 0) {
		v = b.val;
	} else if (b.val == 0) {
		v = a.val;
	} else if (a.val != b.val) {
		v = a.val ^ b.val;
		if (b.val != (a.val)%3+1)
			s = !s;
	} else {
		v = 0;
		s = !s;
	}
	return Quat(v,s);
}



Quat Inv(const Quat &a) {
	if (a.val == 0) return a;
	return Quat(a.val, !a.sign);
}


Quat ss[10010];
Quat pref[10010];
Quat suf[10010];

void Load()
{
	cin >> l >> k;
	cin >> s;
}

void Solve()
{
	int i, j;
	for (i = 0; i < l; i++) {
		ss[i] = Quat(s[i]);
	}
	pref[0] = Quat('1');
	suf[0] = Quat('1');
	for (i = 1; i <= l; i++) {
		pref[i] = pref[i-1] * ss[i-1];
        suf[i] = ss[l - i] * suf[i - 1] ;
	}


	Quat sp[4];
	sp[0] = Quat('1');
	sp[1] = sp[0] * pref[l];
	sp[2] = sp[1] * pref[l];
	sp[3] = sp[2] * pref[l];		

	int x, y;
	for (x = 0; x < l; x++) {
		for (i = 0; i < 4; i++) {
			if (!(sp[i] * pref[x] == Quat('i'))) continue;
			for (y = 0; y < l; y++) {
				for (j = 0; j < 4; j++) {
					if (!(suf[y] * sp[j] == Quat('k'))) continue;								
					if (i > k - j - 1) continue;				
					
					int left = k - i - j - 2;
					if (i == k - j - 1) {
						left = 0;
						if (x >= l-y) continue;
						if (Inv(pref[x])*sp[1]*Inv(suf[y]) == Quat('j')) {
							cout << "YES\n";
							return;						
						}
					} else {
						if (suf[l-x] * sp[left%4] * pref[l-y] == Quat('j')) {
							cout << "YES\n";
							return;
						}
					}

				}
			}
		}
	}

	cout << "NO\n";
}

int main()
{
	cout.setf(ios::fixed|ios::showpoint);
	cout.precision(10);
	int nt, tt;
	cin >> nt;
	for (tt = 1; tt <= nt; tt++) {
		cout << "Case #" << tt << ": ";
		Load();
		Solve(); 
	}
	return 0;
}
