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

		int Ma =Ms1.size(), Mb =Ms2.size();
		vector< vector<int> > F(2+Ma+Mb,vector<int>(2+Ma+Mb,0));
		vector< vector<int> > G(2+Ma+Mb);
		for(int i =0; i < Ma; i++) {
			F[0][i+1] =1;
			G[0].push_back(i+1);
			G[i+1].push_back(0);}
		for(int i =0; i < Mb; i++) {
			F[Ma+1+i][Ma+Mb+1] =1;
			G[Ma+1+i].push_back(Ma+Mb+1);
			G[Ma+Mb+1].push_back(Ma+1+i);}
		for(int i =0; i < N; i++) {
			F[V[i].ff+1][V[i].ss+Ma+1] =1;
			G[V[i].ff+1].push_back(V[i].ss+Ma+1);
			G[V[i].ss+Ma+1].push_back(V[i].ff+1);}

		int f =0;
		while(true) {
			vector<int> ako(2+Ma+Mb,-1);
			queue<int> q;
			q.push(0);
			while(!q.empty()) {
				ALL_THE(G[q.front()],it) if(F[q.front()][*it] == 1 && ako[*it] == -1) {
					ako[*it] =q.front();
					q.push(*it);}
				q.pop();}
			if(ako[1+Ma+Mb] == -1) break;
			f++;
			int akt =1+Ma+Mb;
			while(akt > 0) {
				swap(F[akt][ako[akt]],F[ako[akt]][akt]);
				akt =ako[akt];}
			}

		int minc =Ma+Mb-f;
		cout << N-minc << "\n";}
	return 0;}

// look at my code
// my code is amazing
