#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<queue>
#include <stdlib.h>
#include <unordered_set>
#include <memory.h>
#include <iomanip>
#include<stack>
#include<vector>
#include<string>
#include <deque>
#include <unordered_map>
//#include<unordered_set>
using namespace std;
typedef long long ll;
typedef long double ld;

set <pair<int, int> > st;
void print(int tst){
	cout << "Case #" << tst << ": ";
}

ll d[100];

int ans[100][100];

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++){
		ll n, m;
		cin >> n >> m;
		print(i);
		if ((1ll << (n - 2)) < m){
			cout << "IMPOSSIBLE" << "\n";
			continue;
		}
		cout << "POSSIBLE" << "\n";
		for (int i = 1; i <= n; i++){
			d[i] = 0;
			for (int j = 1; j <= n; j++){
				ans[i][j] = 0;
			}
		}
		m--;
		ans[1][n] = 1;
		for (int i = n - 1; i >1; i--){
			if (m < (1ll << (n - i - 1))){
				break;
			}
			if (m & (1ll << (n - i - 1))){
				ans[1][i] = 1;
			}
			for (int j = i + 1; j <= n; j++){
				ans[i][j] = 1;
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				cout << ans[i][j];
			}
			cout << "\n";
		}
		d[n] = 1;
		for (int i = n - 1; i >= 1; i--){
			for (int j = i + 1; j <= n; j++){
				if (ans[i][j]){
					d[i] += d[j];
				}
			}
		}
		if (d[1] != m + 1){
			return 0;
		}


	}

	return 0;
}