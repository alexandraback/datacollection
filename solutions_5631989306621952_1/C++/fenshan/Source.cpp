#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <bitset>
using namespace std;

#define For(i, a) for (int i = 0; i < a; ++i)
#define FOR(i, v) for (int i = 0; i < v.size(); ++i)
#define sol(sol, i) cout << "Case #" << i+1 << ": " << sol << '\n';

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;

int main(){
	int n;
	string sol;
	char aux;
	cin >> n; cin.get(aux);
	for (int i = 0; i < n; ++i){
		sol = "";
		cin.get(aux);
		while (aux != '\n'){
			if (sol == "")sol += aux;
			else if (aux >= sol[0])sol = aux + sol;
			else sol += aux;
			cin.get(aux);
		}
		sol(sol, i);
	}
	return 0;
}