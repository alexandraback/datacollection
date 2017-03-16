#include <iostream>
#include <cstdio>
//#include <algorithm>
using namespace std;
int *dg;
bool re(int *e, int r, int c, int a) {
	if (a == 0) {
		for (int j = 0; j < r*c; ++j)
			dg[j] = e[j];
		return false;
	}
	int *d = new int[r*c];
	int *x = new int[r*c];
	for (int j = 0; j < r*c; ++j)
		d[j] = e[j];
	for (int j = 0; j < r; ++j)
		for (int k = 0; k < c; ++k)
			if (d[j*c+k] >= 0) {
				int n = 0;
				if (j > 0 && k > 0 && d[j*c-c+k-1] < 0) ++n;
				if (j > 0 && d[j*c-c+k] < 0) ++n;
				if (j > 0 && k < c-1 && d[j*c-c+k+1] < 0) ++n;
				if (k > 0 && d[j*c+k-1] < 0) ++n;
				if (k < c-1 && d[j*c+k+1] < 0) ++n;
				if (j < r-1 && k > 0 && d[j*c+c+k-1] < 0) ++n;
				if (j < r-1 && d[j*c+c+k] < 0) ++n;
				if (j < r-1 && k < c-1 && d[j*c+c+k+1] < 0) ++n;
				x[j*c+k] = d[j*c+k] = n;
			}
			else x[j*c+k] = -1;
	/*for (int j = 0; j < r; ++j) {
		for (int k = 0; k < c; ++k)
			if (x[j*c+k] < 0 ) cout << "- ";
			else cout << x[j*c+k] << ' ';
		cout << endl;
	}*/
	if (a == 1) {
		bool fu = true;
		for (int j = 0; fu && j < r; ++j)
			for (int k = 0; fu && k < c; ++k)
				if (d[j*c+k] == 1) {
					if (j > 0 && k > 0) d[j*c-c+k-1] = 0;
					if (j > 0) d[j*c-c+k] = 0;
					if (j > 0 && k < c-1) d[j*c-c+k+1] = 0;
					if (k > 0) d[j*c+k-1] = 0;
					if (k < c-1) d[j*c+k+1] = 0;
					if (j < r-1 && k > 0) d[j*c+c+k-1] = 0;
					if (j < r-1) d[j*c+c+k] = 0;
					if (j < r-1 && k < c-1) d[j*c+c+k+1] = 0;
					fu = false;
					if (!re(d, r, c, a-1)) {
						delete [] d;
						delete [] x;
						return false;
					}
				}
		//if (fu) { delete [] d; return true; }
		//else {  }
	} else {
		//bool fu = true;
		for (int j = 0; j < r; ++j)
			for (int k = 0; k < c; ++k) {
				for (int i = 0; i < r*c; ++i)
					d[i] = x[i];
				if (d[j*c+k] == 2) {
					if (j > 0 && k > 0) d[j*c-c+k-1] = 0;
					if (j > 0) d[j*c-c+k] = 0;
					if (j > 0 && k < c-1) d[j*c-c+k+1] = 0;
					if (k > 0) d[j*c+k-1] = 0;
					if (k < c-1) d[j*c+k+1] = 0;
					if (j < r-1 && k > 0) d[j*c+c+k-1] = 0;
					if (j < r-1) d[j*c+c+k] = 0;
					if (j < r-1 && k < c-1) d[j*c+c+k+1] = 0;
					//fu = false;
					if (!re(d, r, c, a-2))  {
						delete [] d;
						delete [] x;
						return false;
					}
				}
			}
		//if (fu) { delete [] d; return true; }
		//else { --a; re(d, r, c, a); }
		//else a -= 2;
	}
	delete [] d;
	delete [] x;
	return true;
}

int main() {
	int t; cin >> t;

	for (int i = 0; i < t; ++i) {
		bool im = false;
		int r, c, m; cin >> r >> c >> m;
		int a = r*c - m; //cout << a << endl;
		char *b = new char[r*c];
		int *d = new int[r*c];
		dg = new int[r*c];
		for (int j = 0; j < r*c; ++j) d[j] = -1;
				/*for (int j = 0; j < r; ++j) {
					for (int k = 0; k < c; ++k)
						cout << d[j*c+k] << ' ';
					cout << endl;
				}*/
		if (a == 1) {
			//for (int j = 0; j < r*c; ++j) b[j] = '*';
			//b[0] = 'c';
		} else if (r == 1 || c == 1) {
			//for (int j = 0; j < m; ++j) b[j] = '*';
			for (int j = 0; j < a; ++j) d[j] = 0;
			//b[r*c-1] = 'c';
		} else if (a < 4) {
			im = true;
		} else {
			d[0] = d[1] = d[c] = d[c+1] = 0; a -= 4;
			/*cout << a << endl;
				for (int j = 0; j < r; ++j) {
					for (int k = 0; k < c; ++k)
						cout << d[j*c+k] << ' ';
					cout << endl;
				}*/

			im = re(d, r, c, a);
			for (int j = 0; j < r*c; ++j)
				d[j] = dg[j];
		}
			/*while (a > 0) {
				for (int j = 0; j < r; ++j)
					for (int k = 0; k < c; ++k)
							if (d[j*c+k] >= 0) {
						int n = 0;
						if (j > 0 && k > 0 && d[j*c-c+k-1] < 0) ++n;
						if (j > 0 && d[j*c-c+k] < 0) ++n;
						if (j > 0 && k < c-1 && d[j*c-c+k+1] < 0) ++n;
						if (k > 0 && d[j*c+k-1] < 0) ++n;
						if (k < c-1 && d[j*c+k+1] < 0) ++n;
						if (j < r-1 && k > 0 && d[j*c+c+k-1] < 0) ++n;
						if (j < r-1 && d[j*c+c+k] < 0) ++n;
						if (j < r-1 && k < c-1 && d[j*c+c+k+1] < 0) ++n;
						d[j*c+k] = n;
					}*/
				/*for (int j = 0; j < r; ++j) {
					for (int k = 0; k < c; ++k)
						cout << d[j*c+k] << ' ';
					cout << endl;
				}*/
				/*if (a == 1) {
					bool fu = true;
					for (int j = 0; fu && j < r; ++j)
						for (int k = 0; fu && k < c; ++k)
							if (d[j*c+k] == 1) {
								if (j > 0 && k > 0) d[j*c-c+k-1] = 0;
								if (j > 0) d[j*c-c+k] = 0;
								if (j > 0 && k < c-1) d[j*c-c+k+1] = 0;
								if (k > 0) d[j*c+k-1] = 0;
								if (k < c-1) d[j*c+k+1] = 0;
								if (j < r-1 && k > 0) d[j*c+c+k-1] = 0;
								if (j < r-1) d[j*c+c+k] = 0;
								if (j < r-1 && k < c-1) d[j*c+c+k+1] = 0;
								fu = false;
							}
					if (fu) { im = true; break; }
					else --a;
				} else {
					bool fu = true;
					for (int j = 0; fu && j < r; ++j)
						for (int k = 0; fu && k < c; ++k)
							if (d[j*c+k] == 2) {
								if (j > 0 && k > 0) d[j*c-c+k-1] = 0;
								if (j > 0) d[j*c-c+k] = 0;
								if (j > 0 && k < c-1) d[j*c-c+k+1] = 0;
								if (k > 0) d[j*c+k-1] = 0;
								if (k < c-1) d[j*c+k+1] = 0;
								if (j < r-1 && k > 0) d[j*c+c+k-1] = 0;
								if (j < r-1) d[j*c+c+k] = 0;
								if (j < r-1 && k < c-1) d[j*c+c+k+1] = 0;
								fu = false;
							}
					if (fu) { im = true; break; }
					else a -= 2;
				}
			}
		}*/
/*
		} else if (r == 2) {
			if (m % 2 == 1) im = true;
			else {
				for (int j = 0; j < m/2; ++j) b[j+c] = b[j] = '*';
				for (int j = m/2; j < c; ++j) b[j+c] = b[j] = '.';
				b[r*c-1] = 'c';
			}
		} else if (c == 2) {
			if (m % 2 == 1) im = true;
			else {
				for (int j = 0; j < m; ++j) b[j] = '*';
				for (int j = m; j < r*c-1; ++j) b[j] = '.';
				b[r*c-1] = 'c';
			}
		}*/
		cout << "Case #" << i+1 << ":\n";
		if (im) cout << "Impossible\n";
		else
			for (int j = 0; j < r; ++j) {
				for (int k = 0; k < c; ++k) {
					if (d[j*c+k] < 0) b[j*c+k] = '*';
					else b[j*c+k] = '.';
					b[0] = 'c';
					printf("%c", b[j*c+k]);
				}
				cout << endl;
			}
		delete [] b;
		delete [] d;
		delete [] dg;
	}
}

/*
3 5 6
4 4 3
4 5 9
5 3 2
5 4 3
5 4 7
5 4 11
5 5 4
5 5 14
5 5 16
*/
