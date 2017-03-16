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

int n, lim;
long long a[11];




int main(){ 
	ios_base::sync_with_stdio(false); 
	int n, lim;
	cin >> n >> lim;
	n /= 2;
	cout << "Case #1:" << endl;
	for(int i = 1, k = 0; k < lim; k++, i += 2) {
		for(int j = 0; j < n; j++) {
			cout << ((i >> j) & 1);
		}
		for(int j = 0; j < n; j++) {
			cout << ((i >> (n - j - 1)) & 1);
		}
		for(int j = 3; j <= 11; j++)
			cout << " " << j;
		cout << endl;
	}
	
	
	
	
	return 0; 
} 
