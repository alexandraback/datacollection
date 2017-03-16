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
		int N;
		cin >> N;
		map<string,int> Ms1,Ms2;
		vector< pair<int,int> > V(N);
		for(int i =0; i < N; i++) {
			string s;
			cin >> s;
			auto it =Ms1.find(s);
			if(it == Ms1.end()) {
				V[i].ff =Ms1.size();
				Ms1[s] =V[i].ff;}
			else V[i].ff =it->ss;
			cin >> s;
			it =Ms2.find(s);
			if(it == Ms2.end()) {
				V[i].ss =Ms2.size();
				Ms2[s] =V[i].ss;}
			else V[i].ss =it->ss;}
		
		vector<int> ans(1<<N,0),occ1(1<<N,0),occ2(1<<N,0);
		for(int i =1; i < (1<<N); i++) for(int j =0; j < N; j++) if((i>>j)&1) {
			if((occ1[i-(1<<j)]>>V[j].ff)&1) if((occ2[i-(1<<j)]>>V[j].ss)&1) ans[i] =max(ans[i],ans[i-(1<<j)]+1);
			occ1[i] =occ1[i-(1<<j)]|(1<<V[j].ff);
			occ2[i] =occ2[i-(1<<j)]|(1<<V[j].ss);}
		cout << ans[(1<<N)-1] << "\n";}
	return 0;}

// look at my code
// my code is amazing
