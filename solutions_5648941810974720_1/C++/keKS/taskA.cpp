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

int main(){ 
	ios_base::sync_with_stdio(false); 
	int T;
	cin >> T;
	for(int test = 1; test <= T; test++) {
		string s;
		cin >> s;
		int a[255];
		int c[10];
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		for(int i = 0; i < s.size(); i++)
			a[s[i]]++;
		
		while (a['Z'] > 0) {
			a['Z']--, a['E']--, a['R']--, a['O']--;
			c[0]++;
		}
		while (a['X'] > 0) {
			a['X']--, a['I']--, a['S']--;
			c[6]++;
		}
		while (a['G'] > 0) {
			a['E']--, a['I']--, a['G']--, a['H']--, a['T']--;
			c[8]++;
		}
		while (a['W'] > 0) {
			a['T']--, a['W']--, a['O']--;
			c[2]++;
		}
		while (a['G'] > 0) {
			a['E']--, a['I']--, a['G']--, a['H']--, a['T']--;
			c[8]++;
		}
		while (a['H'] > 0) {
			a['T']--, a['H']--, a['R']--, a['E']--, a['E']--;
			c[3]++;
		}
		while (a['U'] > 0) {
			a['F']--, a['O']--, a['U']--, a['R']--;
			c[4]++;
		}
		while (a['O'] > 0) {
			a['O']--, a['N']--, a['E']--;
			c[1]++;
		}
		while (a['F'] > 0) {
			a['F']--, a['I']--, a['V']--, a['E']--;
			c[5]++;
		}
		while (a['V'] > 0) {
			a['S']--, a['E']--, a['V']--, a['E']--,a['N']--;
			c[7]++;
		}
		while (a['I'] > 0) {
			a['N']--, a['I']--, a['N']--, a['E']--;
			c[9]++;
		}

		cout << "Case #" << test << ": ";
		for(int i = 0; i < 10; i++)
			for(int j = 0; j < c[i]; j++)
				cout << i;
		cout << endl;
	}
	
	
	return 0; 
} 
