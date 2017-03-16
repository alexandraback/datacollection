#define IOSTREAM_TO_FSTREAM

#include<iostream>
#include<algorithm>
#include<list>
#ifdef IOSTREAM_TO_FSTREAM
#include<fstream>
#endif

using namespace std;

int main()
{
#ifdef IOSTREAM_TO_FSTREAM
	ifstream fin;
	fin.open("D-small-attempt0.in");
	cin.rdbuf(fin.rdbuf());
	ofstream fout;
	fout.open("D-small-attempt0.out");
	cout.rdbuf(fout.rdbuf());
#endif
	int n;
	int m;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		double t;
		list<double> dn, dk;
		cin >> m;
		for (int j = 0 ; j < m ; j++) {
			cin >> t;
			dn.push_back(t);
		}
		for (int j = 0 ; j < m ; j++) {
			cin >> t;
			dk.push_back(t);
		}
		dn.sort();
		dk.sort();
		list<double> rn(dn.rbegin(), dn.rend()), rk(dk.rbegin(), dk.rend());
		cout << "Case #" << i << ": ";
		int r = 0;
		list<double>::iterator tn = rn.begin(), tk = rk.begin();
		while (tk != rk.end()) {
			if (*tn > *tk) {
				tn++;
				tk++;
				r++;
			} else {
				tk++;
			}
		}
		cout << r << " ";
		r = 0;
		tn = dn.begin();
		tk = dk.begin();
		while (tk != dk.end()) {
			if (*tn < *tk) {
				tn++;
				tk++;
				r++;
			} else {
				tk++;
			}
		}
		cout << m - r << endl;
	}
	return 0;
}
