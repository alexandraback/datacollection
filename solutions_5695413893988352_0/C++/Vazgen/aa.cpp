#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
const int N = (int)1e5 + 5, INF = (int)1e9;
const ld EPS = 1e-9;

int a[20];

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("b.txt", "w", stdout);
	int T;
	cin >> T;
	for(int z = 1; z <= T; z++){
		cout << "Case #" << z << ": ";
		string c, j;
		cin >> c >> j;
		int k = (int)c.size(), p = 1;
		for(int i = 0; i < k; i++)
			p *= 10;
		int mn = 100000, mn1, mn2;
		for(int x = 0; x < p; x++)
			for(int y = 0; y < p; y++){
				bool f = 1;
				a[0] = x % 10; a[1] = x / 10 % 10; a[2] = x / 100;
				for(int q = 0; q < k; q++)
					if(c[k - q - 1] != '?' && c[k - q - 1] - '0' != a[q]){
						f = 0;
						break;
					}
				a[0] = y % 10; a[1] = y / 10 % 10; a[2] = y / 100;
				for(int q = 0; q < k; q++)
					if(j[k - q - 1] != '?' && j[k - q - 1] - '0' != a[q]){
						f = 0;
						break;
					}
				if(f == 1 && abs(x - y) < mn){
					mn = abs(x - y);
					mn1 = x; mn2 = y;
				}
			}
		a[0] = mn1 % 10; a[1] = mn1 / 10 % 10; a[2] = mn1 / 100;
		for(int i = k - 1; i >= 0; i--)
			cout << a[i]; cout << " ";
		a[0] = mn2 % 10; a[1] = mn2 / 10 % 10; a[2] = mn2 / 100;
		for(int i = k - 1; i >= 0; i--)
			cout << a[i]; cout << "\n";
	}
	return 0;
}