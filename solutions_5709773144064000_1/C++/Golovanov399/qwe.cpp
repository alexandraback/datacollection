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
		double c, f, x;
		cin >> c >> f >> x;
		int k = max((int)((x * f - c * 2) / (c * f)), 0);
		double ans = 0;
		for (int i = 0; i < k; i++) ans += c / (2 + i * f);
		ans += x / (2 + k * f);
		cout << setprecision(10) << fixed;
		cout << ans << "\n";
	}

	return 0;
	
}