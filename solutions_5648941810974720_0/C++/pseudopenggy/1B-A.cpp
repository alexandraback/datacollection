#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORN(i,N) for (int i = 0; i < N; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)


using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int c[256];

vi answer() {
	vi x;
	//6
	while(c['X'] > 0) {
		x.push_back(6);
		c['S']--;
		c['I']--;
		c['X']--;
	}
	while(c['W'] > 0) {
		x.push_back(2);
		c['T']--;
		c['W']--;
		c['O']--;
	}
	while(c['Z'] > 0) {
		x.push_back(0);
		c['Z']--;
		c['E']--;
		c['R']--;
		c['O']--;
	}
	while(c['U'] > 0) {
		x.push_back(4);
		c['F']--;
		c['O']--;
		c['U']--;
		c['R']--;
	}
	while(c['F'] > 0) {
		x.push_back(5);
		c['F']--;
		c['I']--;
		c['V']--;
		c['E']--;
	}
	while(c['S'] > 0) {
		x.push_back(7);
		c['S']--;
		c['E']--;
		c['V']--;
		c['E']--;
		c['N']--;
	}
	while(c['O'] > 0) {
		x.push_back(1);
		c['O']--;
		c['N']--;
		c['E']--;
	}
	while(c['N'] > 0) {
		x.push_back(9);
		c['N']--;
		c['I']--;
		c['N']--;
		c['E']--;
	}
	while(c['I'] > 0) {
		x.push_back(8);
		c['E']--;
		c['I']--;
		c['G']--;
		c['H']--;
		c['T']--;
	}
	while(c['H'] > 0) {
		x.push_back(3);
		c['T']--;
		c['H']--;
		c['R']--;
		c['E']--;
		c['E']--;
	}

	sort(x.begin(),x.end());

	return x;
}

int main() {
	int T;
	string str;
	scanf("%d",&T);

	FOR(i,1,T) {
		FORN(n,256) c[n] = 0;
		cin >> str;

		FORN(a,str.length()) {
			c[str[a]]++;
		}
		cout << "Case #" << i << ": ";
		vi x = answer();
		FORN(ii,x.size())
			cout << x[ii];
		cout << endl;
	}
	return 0;
}
