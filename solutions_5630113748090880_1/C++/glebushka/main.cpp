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
#include<stack>
#include<vector>
#include<string>
#include <deque>
//#include<unordered_set>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef long double ld;

void print(int tst){
	cout << "Case #" << tst << ": ";
}

const int N = 3000;

int used[N];

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++){
		int n;
		cin >> n;
		for (int j = 1; j < N; j++)used[j] = 0;
		for (int i = 1; i <= 2 * n - 1; i++){
			for (int j = 1; j <= n; j++){
				int x;
				cin >> x;
				used[x]++;
			}
		}
		print(i);
		for (int j = 1; j < N; j++){
			if (used[j] % 2){
				cout << j << " ";
			}
		}
		cout << endl;
	}
	return 0;
}