#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <algorithm>
#include <set>
#include <iterator>


using namespace std;

int deceitfulGain = 0, fairGain = 0, n = 0;


void QuickSort(long double a[], int iLo, int iHi) {
	int Lo = 0, Hi = 0;
	long double Pivot = 0.0, T = 0.0;
	Lo = iLo;
	Hi = iHi;
	Pivot = a[( Lo + Hi ) / 2];
	do {
		while ( a[Lo] > Pivot )
			Lo++;
		while ( a[Hi] < Pivot )
			Hi--;
		if ( Lo <= Hi ) {
			T = a[Lo];
			a[Lo] = a[Hi];
			a[Hi] = T;
			Lo++;
			Hi--;
		}
	}
	while ( ! ( Lo > Hi ) );
	if ( Hi > iLo )
		QuickSort( a, iLo, Hi );
	if ( Lo < iHi )
		QuickSort( a, Lo, iHi );
}

void copyArray(long double Source[], long double Dest[], int n) {
	for ( int i = 0; i < n; i++)
		Dest[i] = Source[i];
}


void solve(long double a[], long double b[], long double c[], long double d[]) {
	int i = 0, j = 0, m = 0;
	int k = 0;
	QuickSort(a, 0, n - 1);
	QuickSort(b, 0, n - 1);
	if ( a[n - 1] > b[0] ) {
		deceitfulGain = n;
		fairGain = n;
		return;
	}
	if ( a[0] < b[n - 1] ) {
		deceitfulGain = 0;
		fairGain = 0;
		return;
	}
	copyArray(a, c, n);
	copyArray(b, d, n);
	m = n;
	fairGain = 0;
	for (int i = 0; i < n; i++) {
		if ( a[i] > d[0] ) {
			fairGain++;
			m--;
		} else {
			for ( int j = m - 1; j >= 0; j--) {
				if ( d[j] > a[i] ) {
					m--;
					for ( int stop = m - 1, k = j; k <= stop; k++)
						d[k] = d[k + 1];
					break;
				}
			}
		}
	}
	deceitfulGain = 0;
	m = n;
	for ( int stop = 0, i = n - 1; i >= stop; i--) {
		m--;
		if ( a[i] > b[i] ) {
			deceitfulGain++;
		} else
			if ( a[i] < b[0] ) {
				for ( int k = 0; k < m; k++)
					b[k] = b[k + 1];
			}
	}
}

int main(int argc, char* argv[]) {	
	string inputFile = (argc > 1) ? argv[1] : "input.txt";
	string outputFile = (argc > 2) ? argv[2] : (argc > 1) ? (inputFile + "out.txt") : "output.txt";
	ifstream in;
	ofstream out;
	in.open(inputFile);
	out.open(outputFile);
	out.precision(15);
	long double *a, *b, *c, *d;
	int tests;
	in >> tests;
	for (int test = 1; test <= tests; ++test) {
		out << "Case #" << test << ": ";
		// Grab input
		in >> n;
		a = new long double[n];
		b = new long double[n];
		c = new long double[n];
		d = new long double[n];

		for ( int i = 0; i < n; i++ ) {
			in >> a[i];
		}
		for ( int i = 0; i < n; i++ ) {
			in >> b[i];
		}

		// Solve the problem
		solve(a, b, c, d);
		// Give feedback to the end user;
		out << deceitfulGain << " " << fairGain << endl;
		cerr << ": " << test << endl;
	}

	in.close();
	out.close();

	cout << inputFile << '\n' << outputFile << '\n';

	cin.get();
	return 0;
}