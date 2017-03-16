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
		int x;
		cin >> x;
		if (x == 0) 
			cout << "INSOMNIA" << endl;
		else {
			set<int> st;
			int a = x;
			while (st.size() < 10) {
				int s = a;
				while (s > 0) {
					st.insert(s % 10);
					s /= 10;
				}
				a += x;
			}
			cout << a - x << endl;
		}
	}
	
	
	return 0; 
} 
