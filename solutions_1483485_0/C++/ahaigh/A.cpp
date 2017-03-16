/*
 ID: aandrew
 PROG: GCJ qual 2012, A
 URL: 
 LANG: C++
 
 
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <utility>
#include <cassert>
#include <queue>
#include <ctime>
#include <map>
#include <set>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define CL(x) memset(x, 0, sizeof(x))
typedef long long ll;

char f[26];
void add(char from, char to) {
	f[ to-'a' ] = from;
}

int T;
string G;

int main() {
	add('a','y');
	add('b','n');
	add('c','f');
	add('d','i');
	add('e','c');
	add('f','w');
	add('g','l');
	add('h','b');
	add('i','k');
	add('j','u');
	add('k','o');
	add('l','m');
	add('m','x');
	add('n','s');
	add('o','e');
	add('p','v');
	add('r','p');
	add('s','d');
	add('t','r');
	add('u','j');
	add('v','g');
	add('w','t');
	add('x','h');
	add('y','a');
	add('z','q');
	
	add('q','z'); //deduced :)
	
	//REP(i, 26) cout << ((char)(i+'a')) << " " << f[i] << endl;

	cin >> T; getline(cin,G);
	REP(i, T) {
		getline(cin,G);
		cout << "Case #" << (i+1) << ": ";
		REP(i, G.size()) if (G[i] == ' ') cout << ' '; else cout << f[ G[i]-'a' ];
		cout << endl;
	}
}