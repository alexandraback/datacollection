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

bool used[2000];

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++){
		string s;
		cin >> s;
		for (int i = 0; i< (int)s.size(); i++){
			used[i] = 0;
		}
		int r = (int)s.size() - 1;
		while (r >= 0){
			int mx = r;
			for (int j = r; j >= 0; j--){
				if (s[j] > s[mx]){
					mx = j;
				}
			}
			used[mx] = 1;
			r = mx - 1;
		}

		print(i);
		for (int j = (int)s.size() - 1; j >= 0; j--){
			if (used[j])
			cout << s[j];
		}
		for (int j = 0; j < (int)s.size(); j++){
			if (!used[j]){
				cout << s[j];
			}
		}
		cout << "\n";
	}
	return 0;
}