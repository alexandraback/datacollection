#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<bitset>
#include<vector>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<iomanip>
#include <functional>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int INF = 1 << 28;
//cout << fixed << std::setprecision(9)
//memset(a, 0, sizeof(a));
//--------------------------

int t;
int j, p, s, k;
int a[12][12][12];

int min(int a, int b)
{
	if (a > b) return b;
	else return a;
}

void solve()
{
	queue<int> x, y, z;
	queue<int> xx, yy, zz;

	while (1) {
		int flag = 0;
		for (int jj = 1; jj <= j; jj++)
			for (int pp = 1; pp <= p; pp++)
				for (int ss = 1; ss <= s; ss++) {
					if (a[jj][pp][ss] == 0) {
						x.push(jj);
						y.push(pp);
						z.push(ss);
						flag = 1;
						for (int f = 1; f <= j; f++) a[f][pp][ss] = 2;
						for (int f = 1; f <= p; f++) a[jj][f][ss] = 2;
						for (int f = 1; f <= s; f++) a[jj][pp][f] = 2;
						a[jj][pp][ss] = 1;
					}
				}
		if (flag == 0) break;
	}

	for (int jj = 1; jj <= j; jj++)
		for (int pp = 1; pp <= p; pp++)
			for (int ss = 1; ss <= s; ss++) {
				if (a[jj][pp][ss] == 2) {
					xx.push(jj);
					yy.push(pp);
					zz.push(ss);
				}
			}

	cout << min(k, xx.size()) + x.size() << endl;

	while (!x.empty()) {
		cout << x.front() << " " << y.front() << " " << z.front() << endl;
		x.pop();
		y.pop();
		z.pop();
	}

	int count = 0;
	while (count < k && !xx.empty()) {
		cout << xx.front() << " " << yy.front() << " " << zz.front() << endl;
		xx.pop();
		yy.pop();
		zz.pop();
		count++;
	}

	return;
}

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> j >> p >> s >> k;
		cout << "Case #" << i + 1 << ": ";
		solve();
	}
	return 0;
}

//int t, n;
//int p[26];
//double r[26];
//
//void calc(int n)
//{
//	int sum = 0;
//	for (int i = 0; i < n; i++) {
//		sum += p[i];
//	}
//
//	for (int i = 0; i < n; i++) {
//		r[i] = (double)p[i] / (double)sum;
//	}
//}
//
//void solve(int n)
//{
//	while (1) {
//		calc(n);
//
//		int sum = 0;
//		for (int i = 0; i < n; i++) {
//			sum += p[i];
//		}
//		if (sum == 3) {
//			int i = 0;
//			while (!p[i]) i++;
//			p[i]--;
//			cout << " " << (char)(i + 'A');
//			continue;
//		}
//
//		double max = 0.0;
//		int maxi = 0;
//		for (int i = 0; i < n; i++) {
//			if (max < r[i]) {
//				max = r[i];
//				maxi = i;
//			}
//		}
//		if (max == 0.0) break;
//		else {
//			p[maxi]--;
//			cout << " " << (char)(maxi + 'A');
//		}
//
//		calc(n);
//		max = 0.0;
//		maxi = 0;
//		for (int i = 0; i < n; i++) {
//			if (max < r[i]) {
//				max = r[i];
//				maxi = i;
//			}
//		}
//		if (max == 0.0) break;
//		else {
//			p[maxi]--;
//			cout << (char)(maxi + 'A');
//		}
//	}
//	return;
//}
//
//
//
//int main()
//{
//	cin >> t;
//	for (int i = 0; i < t; i++) {
//		cin >> n;
//		memset(p, 0, sizeof(p));
//		for (int j = 0; j < n; j++) {
//			cin >> p[j];
//		}
//		cout << "Case #" << i + 1 << ":";
//		solve(n);
//		cout << endl;
//	}
//
//	return 0;
//}