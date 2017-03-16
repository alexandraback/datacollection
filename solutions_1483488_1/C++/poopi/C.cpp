								/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

ifstream fin("C.in");
ofstream fout("C.out");

#define cin fin
#define cout fout
#define Max 2000000

vector <int> adj[Max + 10];

int main(){
	for(int i = 1; i <= Max; i++){
		int t = i, p = 1, d = 0;
		while(p * 10 < t)
			p *= 10, d++;
		for(int j = 0; j < d; j++){
			t = t / 10 + (t % 10) * p;
			if(t > i)
				adj[i].push_back(t);
		}
		sort(adj[i].begin(), adj[i].end());
	}
	cerr << "start" << endl;
	int T, test = 0, A, B;
	for(cin >> T; T--; ){
		cin >> A >> B;
		int cnt = 0;
		for(int i = A; i <= B; i++)
			for(int j = 0; j < adj[i].size(); j++)
				if((j == 0 || adj[i][j] != adj[i][j - 1]) && adj[i][j] <= B)
					cnt++;
		cout << "Case #" << ++test << ": " << cnt << endl;
		cerr << T << endl;
	}
	return 0;
}
