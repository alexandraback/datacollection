#include <algorithm>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>

using namespace std;

struct val {
	int sig;
	char sym;
};

string lusym = "lkjiklijjilkijkl";
string lusig = "0202002220022222";

typedef unsigned long long ull;

void mult(val& v, char c)
{
	int mi = (v.sym - 'i') * 4 + (c - 'i');
	v.sym = lusym[mi];
	v.sig = v.sig * (lusig[mi] - '1');
}

void mult(val& v, val w)
{
	int mi = (v.sym - 'i') * 4 + (w.sym - 'i');
	v.sym = lusym[mi];
	v.sig = v.sig * w.sig * (lusig[mi] - '1');
}

val fastexp(val v, ull e) {
	val b = v;
	v.sym = 'l';
	v.sig = 1;
	while (e) {
		if (e & 1ull) mult(v, b);
		mult(b, b);
		e >>= 1;
	}
	return v;
}

void solve()
{
	ull L, X;
	string a;
	cin >> L >> X >> a;
	val t;
	t.sig = 1;
	t.sym = a[0];
	for (ull i=1; i<L; i++) mult(t, a[i]);
	val z = fastexp(t, X);
	if (z.sym != 'l' || z.sig != -1) {
		cout << "NO";
		return;
	}
	t.sig = 1;
	t.sym = a[0];
	char search = 'i';
	for (ull i=1; i<L*X; i++) {
		if (search == 'i' && t.sym == 'i' && t.sig == 1) {
			search = 'j';
			t.sym = a[i%L];
			t.sig = 1;
		} else if (search == 'j' && t.sym == 'j' && t.sig == 1) {
			cout << "YES";
			return;
		} else if (i > 10000000) {
			break;
		} else {
			mult(t, a[i%L]);
		}
	}
	cout << "NO";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int tn=1; tn<=t; tn++) {
		cout << "Case #" << tn << ": ";
		solve();
		cout << "\n";
	}
	return 0;
}