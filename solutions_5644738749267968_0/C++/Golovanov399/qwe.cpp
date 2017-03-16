#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <iomanip>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define double long double
#define LL long long
#define itn int

using namespace std;

int main(){

	int T;
	cin >> T;
	for (int _ = 0; _ < T; _++){
		cout << "Case #" << _ + 1 << ": ";
		int n;
		cin >> n;
		vector<double> a(n), b(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		/*
		cerr << "\n";
		cerr << setprecision(3) << fixed;
		for (int i = 0; i < n; i++) cerr << a[i] << " ";
		cerr << "\n";
		for (int i = 0; i < n; i++) cerr << b[i] << " ";
		cerr << "\n\n";
		*/
		int i = 0, j = 0;
		while (j < n && a[i] > b[j]) j++;
		while (j < n && i < n){
			i++; j++;
			while (j < n && a[i] > b[j]) j++;
		}
		int z = n - i;
		int y = 0;
		int l = 0, r = n - 1;
		for (int i = n - 1; i >= 0; i--){
			if (b[i] > a[r]) l++; else {
				y++;
				r--;
			}
		}
		cout << y << " " << z << "\n";
	}

	return 0;
	
}