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
const long long inf = 1e9 + 23;

//const long long size = 1000;
const long long N = 200;

long long size[N];
bool used[N];

long long a, n, cnt;

bool eat(){
	bool flag = false;
	for (long long i = 0; i < n; i++)
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

	long long t;

	cin >> t;
	for (long long it = 1; it <= t; it++){
		cout << "Case #" << it << ": ";

		cin >> a >> n;
		long long olda = a;
		for (long long i = 0; i < n; i++){
			used[i] = false;
			cin >> size[i];
		}
		sort(size, size + n);
		long long ans = inf;
		for (long long j = 0; j < 40; j++){
			for (long long i = 0; i < n; i++)
				used[i] = false;
			cnt = n;
			a = olda;
			for (long long i = 0; i < j; i++){
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