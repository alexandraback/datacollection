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
#include <string.h>

#define pb push_back 
#define mp make_pair 
#define ll long long 
#define abracadabra next 
#define pii pair<int, int> 

using namespace std; 

int a[55][55];
long long d[55];

long long check(int n) {

	memset(d, 0, sizeof(d));
	d[0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j =0; j < n; j++) {
			if (a[i][j])
				d[j] += d[i];
		}
	}
	return d[n - 1];
}


int main(){ 
	ios_base::sync_with_stdio(false); 
	
	int T;
	cin >> T;
	for(int test = 1; test <= T; test++) {
		cout << "Case #" << test << ": ";
		memset(a, 0, sizeof(a));
		long long B, M;
		cin >> B >> M;
		if ((1LL << (B - 2)) < M) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			cout << "POSSIBLE" << endl;
			int n = B;
			while (n > 2 && ((1LL << (n - 3)) >= M)) {
				n--;
				a[n - 1][n] = 1;
			}
			long long k = (1LL << (n - 2)) - M;
			a[0][n-1] = 1;
			for(int i = 1; i < n - 1; i++) {
				if (k & (1LL << (n-2-i))) 
					a[0][i] = 0;
				else
					a[0][i] = 1;
			}
			for(int i = 1; i < n - 1; i++)
				for(int j = i + 1; j < n; j++)
					a[i][j] = 1;
			cerr << "CHECK: M = " << M << " " << "ANS = " << check(B) << endl;
			for(int i = 0; i < B; i++, cout << endl)
				for(int j = 0; j < B; j++)
					cout << a[i][j];
		}
	}
	
	return 0; 
} 
