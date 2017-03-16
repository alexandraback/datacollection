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
	int T;
	cin >> T;
	for(int t =0; t < T; t++) {
		int N,M;
		cin >> N >> M;
		vector< vector<int> > res(N);
		vector< vector<int> > akt(N);
		for(int i =0; i < N; i++) {
			res[i].resize(M);
			int a =0;
			for(int j =0; j < M; j++) {
				cin >> res[i][j];
				a =max(a,res[i][j]);}
			akt[i].resize(M,a);}
		for(int j =0; j < M; j++) {
			int a =0;
			for(int i =0; i < N; i++) a =max(a,res[i][j]);
			for(int i =0; i < N; i++) akt[i][j] =min(akt[i][j],a);}
		int x =0;
		for(int i =0; i < N; i++) for(int j =0; j < M; j++)
			if(akt[i][j] != res[i][j]) x++;
		cout << "Case #" << t+1 << ": ";
		if(x == 0) cout << "YES\n";
		else cout << "NO\n";}
	return 0;}
        
// look at my code
// my code is amazing
