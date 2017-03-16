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
		cout << "Case #" << t<< ": ";
		string s;
		cin >> s;
		string cur;
		cur.push_back(s[0]);
		for(int i = 1; i < s.length(); i++) {
			if (cur[0] <= s[i]) {
				cur = s[i] + cur;
			} else {
				cur.push_back(s[i]);
			}
		}
		cout << cur << endl;
	}
	
	
	return 0; 
} 
