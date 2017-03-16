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
#define sol(sol, i) cout << "Case #" << i << ": " << sol << '\n';

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;

int main(){
	int n, sol;
	string s;
	cin >> n;
	For (i, n){
		cin >> s;
		sol = 0;
		FOR(j, s){
			if (j != s.size() - 1 && s[j]!=s[j+1]){
				++sol;
			}
		}
		if (s[s.size()-1] == '-') ++sol;
		sol(sol, i + 1);
	}
	return 0;
}