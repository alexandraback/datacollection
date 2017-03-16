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
	freopen("output2.txt", "w", stdout);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> d[i];
			d[i]--;
		}
		vector <int> v;
		int ans = 0;
		for (int i = 0; i < n; i++){
			v.push_back(i);
		}
		do{
			int r = 0;
			for (int i = 0; i < n; i++){
				if (d[v[0]] == v[i]){
					r = i;
					break;
				}
			}
			int cur = r + 1;
			for (int i = 1; i <= r; i++){
				int pp = d[v[i]];
				if (pp != v[i - 1] && pp != v[(i + 1) % (r + 1)]){
					cur = 0;
				}
			}
			ans = max(ans, cur);
		}while (next_permutation(v.begin(), v.end()));
		print(i);
		cout << ans << "\n";
	}
	return 0;
}