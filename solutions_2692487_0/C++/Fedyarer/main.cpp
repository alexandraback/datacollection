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

//const int size = 1000;
const int N = 200;

int size[N];
bool used[N];

int a, n, cnt;

bool eat(){
	bool flag = false;
	for (int i = 0; i < n; i++)
		if (!used[i] && size[i] < a){
			used[i] = true;
			a += size[i];
			flag = true;
			cnt --;
		}
	return flag;
}

int main (void){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;

	cin >> t;
	for (int it = 1; it <= t; it++){
		cout << "Case #" << it << ": ";

		cin >> a >> n;
		int olda = a;
		for (int i = 0; i < n; i++){
			used[i] = false;
			cin >> size[i];
		}
		sort(size, size + n);
		int ans = inf;
		for (int j = 0; j < 40; j++){
			for (int i = 0; i < n; i++)
				used[i] = false;
			cnt = n;
			a = olda;
			for (int i = 0; i < j; i++){
				eat();
				a *= 2;
				a--;
			}
			eat();
			if (ans > j + cnt)
				ans = j + cnt;
			if (cnt == 0)
				break;
		}
		cout << ans << endl;
	}

	return 0;
}