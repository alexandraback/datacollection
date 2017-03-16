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
		string s;
		cin >> s;
		int i = 0, k = 0;
		while (i < s.size()) {
			int l = i;
			while (i < s.size() && s[i] == s[l])
				i++;
			k++;
		}
		cout << k - (s[s.size() - 1] == '+') << endl;
	}
	
	
	return 0; 
} 
