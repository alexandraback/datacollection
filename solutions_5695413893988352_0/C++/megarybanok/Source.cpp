#include <iostream>
#include <vector>
#include <string>

using namespace std;

int max = 9999999999999, ind1, ind2;
string a, b;

int ch(string a) {
	int ans = 0;
	for (int i = 0; i < a.length(); i++) {
		ans *= 10;
		ans += (int)a[i] - (int)'0';
	}
	return ans;
}

void rec2(int i) {

	for (int j = i; j<b.length(); j++)
		if (b[j] == '?') {
			for (int n = 0; n <= 9; n++)
			{
				b[j] = (char)(n + (int)'0');
				rec2(j + 1);
				b[j] = '?';
			}
		}

	bool za = true;
	for (int j = 0; j < a.length(); j++)
		if (b[j] == '?') za = false;

	if (za) {
		i = ch(a);
		int j = ch(b);



		if (abs(i - j) < max) {
			max = abs(i - j);
			ind1 = i;
			ind2 = j;
		}
		else
			if (abs(i - j) == max && i < ind1) {
				ind1 = i;
				ind2 = j;
			}
			else
				if (abs(i - j) == max && i == ind1 && j < ind2) {
					ind1 = i;
					ind2 = j;
				}
	}
	
}


void rec1(int i) {

	for (int j = i; j < a.length(); j++)
		if (a[j] == '?') {
			for (int n = 0; n <= 9; n++)
			{
				a[j] = (char)(n + (int)'0');
				rec1(j + 1);
				a[j] = '?';
			}
		}
	bool za = true;
	for (int j = 0; j < a.length(); j++)
		if (a[j] == '?') za = false;
	if (za)
	rec2(0);
	
}

void dop0(int l, int x) {
	string asn = "";
	string abc = "";
	int q = x;
	while (x != 0)
	{
		abc+= (char)(x % 10 + (int)'0');
		x /= 10;
	}
	if (!q) l--;
	while (l != abc.length()) {
		l--;
		cout << 0;
	}
	cout << q;
}

void main() {

	FILE *str, *abc;
	freopen_s(&str, "input.txt", "r", stdin);
	freopen_s(&abc, "out.txt", "w", stdout);

	int t;
	cin >> t;
	
	for (int tt = 0; tt < t; tt++) {
		cout << "Case #" << tt + 1 << ": ";
		
		max = 9999999;
		cin >> a >> b;
		
		rec1(0);

		dop0(a.length(), ind1);
		cout << " ";
		dop0(a.length(), ind2);
		cout << endl;
	}
		
}