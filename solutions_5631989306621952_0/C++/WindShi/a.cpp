#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

string str, f[1001], v[1011];
int test;
 
int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d", &test); //test = 1;
	for (int uu = 1; uu <= test; uu++) {
		cin >> str;
		int n = str.size();
		v[n + 1] = "";
		for (int i = 0; i <= n; i++) f[i] = "";
		for (int i = 1; i <= n; i++) {
			string app = "";
			for (int j = i; j; j--) {
				//cerr << i << " " << j << str << endl; 
				//cerr << str[j - 1] + f[j - 1] + app << endl; 
				f[i] = max(f[i], str[j - 1] + f[j - 1] + app);
				app = str[j - 1] + app;
			}
		}
		printf("Case #%d: ", uu);
		cout << f[n] << endl;
	}
}
		 	
