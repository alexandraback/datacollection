#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <complex>
#include <stack>
#include <cctype>
#include "assert.h"
#include <cstdlib>
#include <iostream>

#define PB push_back
#define MP make_pair
#define FR(i,n) for( long long i = 0; i < n; i ++ )
#define FOR(i,a,n) for(long long i = a; i < n; i ++)
#define FREACH(it,v) for( typeof(v.end()) it = v.begin(); it != v.end(); it ++ )
#define EPS 1e-9
using namespace std;
typedef long long ll;

char maap[1000];


int main() {
	int T;
	maap['a']='y';
	maap['b']='h';
	maap['c']='e';
	maap['d']='s';
	maap['e']='o';
	maap['f']='c';
	maap['g']='v';
	maap['h']='x';
	maap['i']='d';
	maap['j']='u';
	maap['k']='i';
	maap['l']='g';
	maap['m']='l';
	maap['n']='b';
	maap['o']='k';
	maap['p']='r';
	maap['q']='z';
	maap['r']='t';
	maap['s']='n';
	maap['t']='w';
	maap['u']='j';
	maap['v']='p';
	maap['w']='f';
	maap['x']='m';
	maap['y']='a';
	maap['z']='q';
	
	
	scanf("%d",&T);
	string s;
	getline(cin,s);
	FR(i,T) {
		cout << "Case #" << i+1 << ": ";
		getline(cin,s);
		stringstream ss(s);
		string s2;
		bool c=false;
		while(ss>>s2) {
			if(c) cout << ' ';
			c=true;
			FR(i,s2.size()) s2[i]=maap[s2[i]];
			cout << s2;
		}
		cout << endl;
	}
}