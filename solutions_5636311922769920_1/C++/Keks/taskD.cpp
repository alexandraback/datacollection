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

int main(){ 
	ios_base::sync_with_stdio(false); 
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		int k, c, s;
		cin >> k >> c >> s;
		if (s * c < k) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			int cur = 0;
			while (cur < k) {
				long long q = 1, t = 0;
				for(int i = 0; i < c; i++, cur++) {
					if (cur < k)
						t += q * cur;
					q *= k;
				}
				cout << t + 1 << " ";
			}
			cout << endl;
		}
	}
	
	
	return 0; 
} 
