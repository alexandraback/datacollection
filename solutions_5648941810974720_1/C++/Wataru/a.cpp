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

const long double eps = 1e-8;

string s;

int n = 26;

string w[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};


long double a[100][100];


void Load()
{
	cin >> s;
}

int Cnt(string &s, char c) {
//	cerr << s << ' ' << c << ' ';
	int i, ans;
	ans = 0;
	for (i = 0; i < (int)s.length(); i++) {
		if (s[i] == c) ans++;
	}
//	cerr << ans << "\n";
	return ans;
}


int has[10];

void Gauss() {
	int i, j, k;
	long double t, f;

	for (i = 0; i < 10; i++) {

/*	
		cerr << "solving for " << i << "\n";
		for (j = 0; j < n; j++) {
			for (k = 0; k <= 10; k++)
				cerr << (double)a[j][k] << " ";
			cerr << "\n";
		}
*/

		for (j = i; j < n; j++) {
			if (fabs(a[j][i]) > eps) break;
		}
		if (j == n) {
			cerr << "Botva1\n";
			//exit(1);
			has[i] = -1;
			continue;
		}
		has[i] = i;
		for (k = 0; k <= 10; k++) {
			t = a[i][k]; 
			a[i][k] = a[j][k]; 
			a[j][k] = t;
		}
		f = 1.0/a[i][i];
		for (k = 0; k <= 10; k++)
			a[i][k] *= f;
	   	for (j = 0; j <= n; j++) {
	   		if (j == i) continue;
	   		f = -a[j][i];
	   		for (k = 0; k <= 10; k++) {
	   			a[j][k] += f*a[i][k];
	   		}
	   	}
	}

	/*
	for (j = 0; j < n; j++) {
		for (k = 0; k <= 10; k++)
			cerr << (double)a[j][k] << " ";
		cerr << "\n";
	}
	*/


	for (i = 10; i <= n; i++) {
		if (fabs(a[i][10]) > eps){ 
			cerr << "Botva2\n";
			exit(1);
		}
	}
}


void Solve()
{
	int i, j;
	for (i = 0; i < 26; i++){
		char c = (char)(i+(int)'A');
		for (j = 0; j < 10; j++){
			a[i][j] = Cnt(w[j], c);
		}
		a[i][10] = Cnt(s, c);
	}
	Gauss();
//	cerr << "fin gauss\n";
	for (i = 0; i < 10; i++) {
		if (has[i] < 0) continue;
		int cur = (int)(a[i][10] + 1e-4);
//		cerr << cur << " ";
		for (j = 0; j < cur; j++)
			cout << has[i];
	}
//	cerr << "\n";
	cout << "\n";
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
