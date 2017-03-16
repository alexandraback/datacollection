// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int t =0; t < T; t++) {
		cout << "Case #"  << t+1 << ": ";
		int X,R,C;
		cin >> X >> R >> C;
		if(R < C) swap(R,C);
		if(X >= 7 || (R*C)%X != 0 || R < X) {cout << "RICHARD\n"; continue;}
		// generate all
		if(X > 2 && C == 1) {cout << "RICHARD\n"; continue;}
		if(X == 4 && C == 2) {cout << "RICHARD\n"; continue;}
		cout << "GABRIEL\n";}
	return 0;}

// look at my code
// my code is amazing
