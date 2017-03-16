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

int a[10000];
int n;
int cur[100];
int ans;

int rec(int k, int used) {
	if (k == n) {
		for(int i = ans + 1; i <= n; i++) {
			bool flag = true;
			for(int j = 0; j < i; j++) {
				if (a[cur[j]] != cur[(j + 1) % i] && a[cur[j]] != (cur[(j + i - 1) % i])) {
					flag =  false;
					break;
				}
			}
			if (flag)
				ans = max(ans, i);
		}
	} else {
		for(int i = 0; i < n; i++) {
			if (!(used & (1 << i))) {
				cur[k] = i;
				rec(k + 1, used | (1 << i));
			}
		}
	}
}

int main(){ 
	ios_base::sync_with_stdio(false); 
	int T;
	cin >> T;
	for(int test = 1; test <= T; test++) {
		cerr << test << endl;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			a[i]--;
		}
		ans = 1;
		rec(0, 0);
		cout << "Case #" << test << ": " << ans << endl;
	}
	
	
	return 0; 
} 
