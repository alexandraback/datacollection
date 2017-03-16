#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>

#define REP(i,a,b) for(int i=a; i<b; ++i)
#define DOWN(i,a,b) for(int i=a; i>=b; --i)
#define ft first
#define sd second
#define mp make_pair
#define pb push_back

using namespace std;

map<int,int>M;
int t,n;
string A,B;
bool was[300];

int main(){
	
	M['a'] = 'y';
	M['b'] = 'h';
	M['c'] = 'e';
	M['d'] = 's';
	M['e'] = 'o';
	M['f'] = 'c';
	M['g'] = 'v';
	M['h'] = 'x';
	M['i'] = 'd';
	M['j'] = 'u';
	M['k'] = 'i';
	M['l'] = 'g';
	M['m'] = 'l';
	M['n'] = 'b';
	M['o'] = 'k';
	M['p'] = 'r';
	M['q'] = 'z';
	M['r'] = 't';
	M['s'] = 'n';
	M['t'] = 'w';
	M['u'] = 'j';
	M['v'] = 'p';
	M['w'] = 'f';
	M['x'] = 'm';
	M['y'] = 'a';
	M['z'] = 'q';
	M[' '] = ' ';
	ios_base::sync_with_stdio(0);
	cin >> t;
	getline(cin,A);

int u = 0;
while(t--){
	u++;
	cout << "Case #" << u << ": "; 
	getline(cin,A);
	n = A.size();
	string B(n,0);
	REP(i,0,n) B[i] = M[A[i]];
	cout << B << endl;
}
	/*
	M['z'] = 'q';
	was['q'] = 1;
	
	REP(i,0,3){
		getline(cin,A);
		getline(cin,B);
		n = A.size();
		REP(j,0,n) {M[A[j]] = B[j]; was[B[j]] = true;}
	}
	
	REP(i,'a','z'+1) if(!was[i]) {M['q'] = i;}
	
	REP(i,'a','z'+1){
		cout << "M['" << (char)i << "'] = '" << (char)M[i] << "';" << endl;
	}
	*/
}
