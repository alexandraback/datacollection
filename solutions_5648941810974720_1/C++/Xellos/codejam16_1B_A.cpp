#include <bits/stdc++.h>
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
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	for(int t =0; t < T; t++) {
		cout << "Case #" << t+1 << ": ";
		string s;
		cin >> s;
		int N =s.length();
		vector<int> poc(10,0);
		for(int i =0; i < N; i++) if(s[i] == 'Z') poc[0]++;
		for(int i =0; i < N; i++) if(s[i] == 'X') poc[6]++;
		for(int i =0; i < N; i++) if(s[i] == 'S') poc[7]++;
		poc[7] -=poc[6];
		for(int i =0; i < N; i++) if(s[i] == 'V') poc[5]++;
		poc[5] -=poc[7];
		for(int i =0; i < N; i++) if(s[i] == 'F') poc[4]++;
		poc[4] -=poc[5];
		for(int i =0; i < N; i++) if(s[i] == 'W') poc[2]++;
		for(int i =0; i < N; i++) if(s[i] == 'G') poc[8]++;
		for(int i =0; i < N; i++) if(s[i] == 'O') poc[1]++;
		poc[1] -=poc[0]+poc[2]+poc[4];
		for(int i =0; i < N; i++) if(s[i] == 'N') poc[9]++;
		poc[9] -=poc[1]+poc[7];
		poc[9] /=2;
		for(int i =0; i < N; i++) if(s[i] == 'H') poc[3]++;
		poc[3] -=poc[8];
		string ans;
		for(int i =0; i < 10; i++) for(int j =0; j < poc[i]; j++) ans +=(char)('0'+i);
		cout << ans << "\n";}
	return 0;}

// look at my code
// my code is amazing
