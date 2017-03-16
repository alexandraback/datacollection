#include <iostream> 
#include <fstream> 
#include <cmath> 
#include <algorithm> 
#include <cassert> 
#include <string> 
#include <cstdlib> 
#include <cstdio> 
#include <vector> 
#include <map> 
#include <set> 
#include <stack> 
#include <iomanip> 
#include <queue> 

#define pb push_back 
#define mp make_pair 
#define ll long long 
#define abracadabra next 
#define pii pair<int, int> 

using namespace std; 

int v[33][3];
int n, k, mask;
int it;
int cc[3][3][3];
int used[3][3][3];

bool check() {
	it++;
	for(int i =0; i < n; i++) {
		if (mask & (1 << i)) {
			if (used[0][v[i][1]][v[i][2]] != it) {
				used[0][v[i][1]][v[i][2]] = it;
				cc[0][v[i][1]][v[i][2]] = 1;
			} else if (cc[0][v[i][1]][v[i][2]] + 1 > k)
				return false;
			else
				cc[0][v[i][1]][v[i][2]]++;
				
			if (used[1][v[i][0]][v[i][2]] != it) {
				used[1][v[i][0]][v[i][2]] = it;
				cc[1][v[i][0]][v[i][2]] = 1;
			} else if (cc[1][v[i][0]][v[i][2]] + 1 > k)
				return false;
			else
				cc[1][v[i][0]][v[i][2]]++;
				
			if (used[2][v[i][0]][v[i][1]] != it) {
				used[2][v[i][0]][v[i][1]] = it;
				cc[2][v[i][0]][v[i][1]] = 1;
			} else if (cc[2][v[i][0]][v[i][1]] + 1 > k)
				return false;
			else
				cc[2][v[i][0]][v[i][1]]++;
		}
	}
	return true;
}

int main(){ 
	ios_base::sync_with_stdio(false); 
	
	int T;
	cin >> T;
	for(int test = 1; test <= T; test++) {
		cout << "Case #" << test << ": ";
		int a, b, c;
		cin >> a >> b >> c >> k;
		cerr << test << " " << a << " " << b << " " << c << " " << k << endl;
		if (k >= c) {
			cout  << a * b * c << endl;
			for(int i = 0; i < a; i++)
				for(int j = 0; j < b; j++)
					for(int k = 0; k < c; k++)
						cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
		} else {
			n = 0;
			int ans = 0, ansm = 0;
			for(int i = 0; i < a; i++)
				for(int j = 0; j < b; j++)
					for(int l = 0; l < c; l++) {
						v[n][0] = i; 
						v[n][1] = j; 
						v[n][2] = l;
						n++;
					}
			for(mask = 0; mask < (1 << n); mask++) {
				if (__builtin_popcount(mask) > ans)
					if (check()) {
						ans = __builtin_popcount(mask);
						ansm = mask;
					}
			}
			cout << ans << endl;
			for(int i =0; i < n; i++) {
				if (ansm& (1 << i)) {
					cout << v[i][0]+1 << " " << v[i][1]+1 << " " << v[i][2]+1 << endl;
				}
			}
		}
	}
	
	return 0; 
} 
