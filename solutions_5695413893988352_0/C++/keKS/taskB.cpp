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
	for(int test = 1; test <= T; test++) {
		string s1, s2;
		cin >> s1 >> s2;
		int greater = -1;
		for(int i = 0; i < s1.size(); i++) {
			if (greater == 0) {
				if (s1[i] == '?') {
					s1[i] = '0';
				}
				if (s2[i] == '?') {
					s2[i] = '9';
				}
			} else if (greater == 1) {
				if (s1[i] == '?') {
					s1[i] = '9';
				}
				if (s2[i] == '?') {
					s2[i] = '0';
				}
			} else {
				if (s1[i] == '?') {
					if (s2[i] == '?') {
						s1[i] = s2[i] = '0';
					} else {
						s1[i] = s2[i];
					}
				} else if (s2[i] == '?') {
					if (s1[i] == '?') {
						s1[i] = s2[i] = '0';
					} else {
						s2[i] = s1[i];
					}
				} else {
					if (s1[i] != s2[i]) {
						greater = (s1[i] < s2[i]);
					}
				}
			}
		}
		cout << "Case #" << test << ": " << s1 << " " << s2 << endl;
	}
	
	return 0; 
} 
