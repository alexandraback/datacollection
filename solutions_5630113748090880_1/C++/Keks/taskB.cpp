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

vector<int> a[200];

int ans[50][50];
int k;

bool cmp(const vector<int> &a, const vector<int> &b) {
	return a[k] < b[k];
}

int main(){ 
	ios_base::sync_with_stdio(false); 
	int T;
	cin >> T;
	for(int test = 1; test <= T; test++) {
	cerr << test << endl;
		int n;
		cin >> n;
		for(int i =0; i < (2 * n - 1); i++)
			a[i].clear();
			
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				ans[i][j] = -1;
				
		for(int i = 0; i < 2 * n - 1; i++) {
			for(int j = 0; j < n; j++) {
				int x;
				cin >> x;
				a[i].push_back(x);
			}
		}
		int ansk = -1;
		for(k = 0; k < n; k++) {
			cerr << " " << k << endl;
			sort(a, a + 2 * n - 1, cmp);
			if ((ansk == -1 && k == n - 1) || a[2 * k][k] != a[2 * k + 1][k]) {
				assert(ansk == -1);
				ansk = k;
				for(int i = 0; i < n; i++)
					ans[k][i] = a[2 * k][i];
				break;
			}
		}
		cout << "Case #" << test << ": ";
		
		int t = 0;
		for(k = 0; k < n; k++) {
			if (k > 0)
				cout << " ";
			sort(a, a + 2 * n - 1, cmp);
			if (k == ansk) {
				cout << a[2 * k][k];
				t = -1;
				continue;
			}
			if (a[2 * k + t][ansk] == ans[ansk][k]) {
				cout << a[2 * k + 1 + t][ansk];
			} else {
				cout << a[2 * k + t][ansk];
			}
		}
		cout << endl;

		
	}
	
	
	return 0; 
} 
