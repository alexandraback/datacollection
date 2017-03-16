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

int a[N];
int d[N];
bool used[N];
int cnt[N];
int mx[N];

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			mx[i] = 0;
		}
		for (int i = 0; i < n; i++){
			cin >> d[i];
			d[i]--;
		}
		int pp = 0;
		for (int i = 0; i < n; i++){
			if (cnt[i] >= 0){
				for (int j = 0; j < n; j++){
					used[j] = 0;
				}
				int nxt = i;
				int cur = 0;
				int prev = i;
				while (1){
					int tmp = nxt;
					used[nxt] = 1;
					cur++;
					nxt = d[nxt];
					if (used[nxt] && nxt != prev){
						cur = -1;
						break;
					}
					prev = tmp;
					if (used[nxt])break;
				}
				mx[d[nxt]] = max(cur, mx[d[nxt]]);
			}
		}
		for (int i = 0; i < n; i++){
			if (i == d[d[i]]){
				pp += mx[i] + mx[d[i]] - 2;
			}
		}
		pp /= 2;

		int ans = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				used[j] = 0;
			}
			int nxt = i;
			int cur = 0;
			int st = i;
			while (1){
				int prev = nxt;
				used[nxt] = 1;
				cur++;
				nxt = d[nxt];
				if (used[nxt] && nxt != st){
					cur = 0;
					break;
				}
				if (used[nxt])break;
			}
			ans = max(ans, cur);
		}
		print(i);
		cout << max(ans, pp) << "\n";
	}
	return 0;
}