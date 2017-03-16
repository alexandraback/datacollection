#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#define MAXN 1010

using namespace std;

ofstream fout ("Dlarge.out");
ifstream fin ("Dlarge.in");

int T;
int n;
double a[MAXN],b[MAXN];

int calcDeceit() {
	for (int i = 0; i < n; i++) {
		bool works = true;
		for (int j = 0; j+i < n && works; j++)
			if (a[i+j] < b[j]) works = false;
		if (works) return n-i;
	}
	return 0;
}

int calcWar() {
	int res = 0;
	for (int i = n-1, j = n-1; i >= 0; i--) {
		if (a[i] < b[j]) j--;
		else res++;
	}
	return res;
}

int main() {
	fin >> T;
	for (int tc = 1; tc <= T; tc++) {
		fin >> n;
		for (int i = 0; i < n; i++) fin >> a[i];
		for (int i = 0; i < n; i++) fin >> b[i];
		sort(a,a+n);
		sort(b,b+n);
		fout << "Case #" << tc << ": ";
		fout << calcDeceit() << ' ' << calcWar() << '\n';
	}
    return 0;
}