// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
	int T,K,N,x;
	cin >> T;
	for(int t =0; t < T; t++) {
		cin >> K >> N;
		map<int,int> typy;
		vector< vector<int> > kluce(N);
		vector<int> open(N);
		vector<int> moje(K);
		for(int i =0; i < K; i++) {
			cin >> moje[i];
			typy[moje[i]] =0;}
		for(int i =0; i < N; i++) {
			cin >> open[i] >> x;
			kluce[i].resize(x);
			typy[open[i]] =0;
			for(int j =0; j < x; j++) {
				cin >> kluce[i][j];
				typy[kluce[i][j]] =0;}}
		int x =0;
		ALL_THE(typy,it) {
			it->second =x;
			x++;}
		for(int i =0; i < N; i++) {
			for(uint j =0; j < kluce[i].size(); j++) kluce[i][j] =typy[kluce[i][j]];
			open[i] =typy[open[i]];}
		for(int i =0; i < K; i++) moje[i] =typy[moje[i]];
		
		int a =1;
		for(int i =0; i < N; i++) a *=2;
		int Pow[N+2];
		Pow[0] =1;
		for(int i =0; i <= N; i++) Pow[i+1] =Pow[i]*2;
		vector< vector<int> > adjL(a);
		for(int b =0; b < a; b++) {
			int c =b;
			vector<int> poc(x,0);
			for(int i =0; i < N; i++) {
				if(c%2 == 1) {
					poc[open[i]]--;
					for(uint j =0; j < kluce[i].size(); j++) poc[kluce[i][j]]++;}
				c /=2;}
			for(int i =0; i < K; i++) poc[moje[i]]++;
			c =b;
//			cout << b <<  "   ";
			for(int i =0; i < N; i++) {
				if(c%2 == 0 && poc[open[i]] > 0) 
					adjL[b+Pow[i]].push_back(i);
//					cout << i << " ";}
				c /=2;}}
//			cout << endl;}
		
		queue<int> q;
		q.push(a-1);
		vector<int> ako(a,N+1);
		vector<int> A(a,0);
		A[a-1] =1, ako[a-1] =0;
		while(!q.empty()) {
			x =q.front();
			A[x]--;
			if(A[x] > 0) {
				q.pop();
				continue;}
			for(uint i =0; i < adjL[x].size(); i++) if(ako[x-Pow[adjL[x][i]]] > adjL[x][i]) {
				ako[x-Pow[adjL[x][i]]] =adjL[x][i];
				A[x-Pow[adjL[x][i]]]++;
				q.push(x-Pow[adjL[x][i]]);}
			q.pop();}
		cout << "Case #" << t+1 << ":";
		if(ako[0] > N) cout << " IMPOSSIBLE\n";
		else {
			x =0;
			while(x != a-1) {
				cout << " " << ako[x]+1;
				x +=Pow[ako[x]];}
			cout << endl;}
		}
	return 0;}
        
// look at my code
// my code is amazing
