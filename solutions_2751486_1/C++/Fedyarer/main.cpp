#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

const double eps = 1e-9;
const int inf = 1e9 + 23;

const int size = 1000 * 1000 +3;

char s[size];
int l[size], type[size];
int u[size], v[size];

bool isv(char a){
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
		return true;
	return false;
}

int main (void){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t, n;
	char b;

	cin >> t;
	for (int it = 1; it <= t; it++){
		printf("Case #%d: ", it);
		cin >> s >> n;
		long long len = strlen(s);
		long long ans = len * (len + 1) / 2;
		u[0] = 1 - isv(s[0]);
		if (n == 1 && u[0] == 1)
			v[0] = 0;
		else
			v[0] = 1;
		for (int i = 1; i < len; i++){
			if (isv(s[i]) == 0){
				u[i] = u[i - 1] + 1;
			}
			else
				u[i] = 0;
			if (u[i] >= n)
				v[i] = n - 1;
			else
				v[i] = v[i - 1] + 1;
		}
		for (int i = 0; i < len; i++){
			ans -= v[i];
			//cout << "v[i] = " << v[i] << " u[i] = " << u[i] << " ";
			
		}
		cout << ans << endl;
	}

	return 0;
}